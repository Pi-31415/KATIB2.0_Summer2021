#include "painting_area.h"
#include "ui_painting_area.h"
#include <QProgressDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QMessageBox>

const float Xaxis = 1321.0;
const float Yaxis = 631.0;
QSerialPort *serialport;
int control =0;
void Painting_area::SerialPort_Init()
{
    //read serial port name from file
       QString path = QCoreApplication::applicationDirPath() + "/port.txt";

   QFile file(path);
   if (!file.exists())
   {
       qDebug() <<"doesn't exist";
       qDebug() <<path<<endl;
   }
   if (!file.open(QIODevice::ReadOnly))
   {
       QMessageBox::information(this,"Error", "Unable to read port.txt! Please check the file");
       exit(-1);
   }
    QTextStream stream(&file);
    QString line = stream.readLine();
    qDebug() <<line<<endl;




    // list available ports
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    qDebug() << "Hereee"<< ports.count();
   for(int i=0;i<ports.count();i++)
   {
       qDebug()<<ports.at(i).portName()<<"-"<<ports.at(i).description();
   }

   //initialize serial port

   serialport = new QSerialPort();
   serialport->setPortName("ttyACM0"); //korres: changed from qt_var: line
   serialport->open(QSerialPort::ReadWrite);//open(QSerialPort::WriteOnly); //korres changed to read write
   serialport->setBaudRate(QSerialPort::Baud115200);
   serialport->setDataBits(QSerialPort::Data8);
   serialport->setFlowControl(QSerialPort::NoFlowControl);
   serialport->setParity(QSerialPort::NoParity);
   serialport->setStopBits(QSerialPort::OneStop);

}

// function called at the start of the program to callibrate the writing device
void Painting_area::callibration_routine()
{
   QProgressDialog progress("Initializing device. Please wait a moment","",0,103,this);
   progress.setWindowModality(Qt::WindowModal);
   progress.setModal(true);
   progress.setCancelButton(nullptr);
   progress.setWindowFlag(Qt::FramelessWindowHint);
   QStringList temp;
   temp.append("$X\n");
   temp.append("M3 S100\n");
   temp.append("M3 S500\n");
   temp.append("$H\n");
   temp.append("$X\n");
   temp.append("G10 P1 L20 X0 Y0\n");
   temp.append("$X\n");
   temp.append("G21 X9 Y-7 F4000\n"); //movement
   temp.append("M3 S700\n");
   temp.append("G10 P1 L20 X0 Y0\n");//soft home
   temp.append("G21 X0 Y-145 F4000\n");
   temp.append("G21 X300 Y-145 F4000\n");
   temp.append("G21 X0 Y0 F4000\n");
   temp.append("M3 S1000\n");
   for (int i=0;i<3;i++)
   {
     progress.setValue(i);
     serialport->write(temp[i].toUtf8());
     QThread::msleep(100);
   }
   serialport->write(temp[3].toUtf8());

   for (int i =0;i<100;i++)
   {
       progress.setValue(i+3);
       QThread::msleep(100);
   }
   for (int i=0;i<9;i++)
   {
       progress.setValue(i+103);
       serialport->write(temp[i+4].toUtf8());
       QThread::msleep(100);
   }
   progress.setValue(103);

}

QList<float> normalizePixels(int x, int y)
{
    //function to map recorded pixels to 0-1
    QList<float> position;
    float x_norm,y_norm;
    x_norm = (x)/Xaxis;
    y_norm = (y)/Yaxis;
    position.append(x_norm);
    position.append(y_norm);
    return position;
}

QList<float> mapToCoordinates(float x, float y)
{
    //function to get x,y coordinates in mm according to the working space
    QList<float> coordinates;
    coordinates.append(304.0 * x);
    coordinates.append(-145 * y);
    return coordinates;
}
int check =0;
int SendMsg(float x, float y,int feedrate)
{
    check++;
    char buffer[50];
    //function to send commands to serial port
    //serialport->setReadBufferSize(500);
    QString val = "G21 X"+QString::number(x) + " Y" +QString::number(y) +" F"+QString::number(feedrate) +"\n";
    int retVal = serialport->write(val.toUtf8());
    QThread::msleep(10);
    serialport->read(buffer,50);
    qDebug()<<"Serial Response: " <<buffer;
    //val = "$X\n";
    //serialport->write(val.toUtf8());
    serialport->flush();
    qDebug() << check<<"..."<<retVal;
    return retVal;
}

int SetMagnetPos(int height)
{
    //function to set the position of the magnet
    //serialport->setReadBufferSize(500);
    QString val ="M3 S" + QString::number(height) + "\n";
    int retVal = serialport->write(val.toUtf8());
    //serialport->clear();
    return retVal;
}

void fullGuidance(int x_scr,int y_scr,float x_file,float y_file,int radius)
{       qDebug() << x_scr <<"..."<<y_scr<<"..."<<x_file<<"..."<<y_file<<"....";
        QList<float> pos = normalizePixels(x_scr,y_scr);
        QList<float> screen_coords = mapToCoordinates(pos[0],pos[1]);
        QList<float> pos2 = normalizePixels(x_file,y_file);
        QList<float> coords = mapToCoordinates(pos2[0],pos2[1]);
        //qDebug() << screen_coords[0] <<"..."<<screen_coords[1]<<"..."<<coords[0]<<"..."<<coords[1]<<"....";
        if(coords[0] - radius < screen_coords[0] && screen_coords[0] <=coords[0] + radius && coords[1] - radius < screen_coords[1] && screen_coords[1] <=coords[1] + radius)
        {
            qDebug() << "inside";
            SendMsg(coords[0],coords[1],1000);
            qDebug() << "Here";
            control++;
        }
}


Painting_area::Painting_area(QWidget *parent) : QWidget(parent), ui(new Ui::Painting_area){

    ui->setupUi(this);
    setFixedSize(this->size());

    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);

    drawing = false;
    brushColor = Qt::black;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawImage()));
    timer->start(75);

    blink = new QTimer(this);
    connect(blink, SIGNAL(timeout()), this, SLOT(blinker()));
    blink->start(600);

    animate = false;
    visGuide = false;
    pressed = false;
    blinker1 = true;
    started = false;

    i = 0;
    ctr = 0;
}

Painting_area::~Painting_area(){
    delete ui;
}

void Painting_area::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton
            && event->pos().x() > 0
            && event->pos().x() < Xaxis
            && event->pos().y() > 0
            && event->pos().y() < Yaxis){

        drawing = true;
        lastPoint = event->pos();

        ctr = 1;

        if(visGuide){
            QPainter look(&image);
            look.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            QPoint point(Xs_in[3], Ys_in[3]);
            look.drawPoint(point);
            this->update();
        }

        pressed = true;
        blink->start(1);
    }
}

void Painting_area::mouseMoveEvent(QMouseEvent *event){
    if ((event->buttons() & Qt::LeftButton) && drawing
            && event->pos().x() > 0
            && event->pos().x() < Xaxis
            && event->pos().y() > 0
            && event->pos().y() < Yaxis){

        QPainter painter(&image);
        painter.setPen(QPen(brushColor, 10, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
        painter.drawLine(lastPoint, event->pos());

        lastPoint = event->pos();
         Xs_out.push_back(event->pos().x());
         Ys_out.push_back(event->pos().y());
        if (Guidance == "Full")
        {
            if (control+4>=Xs_in.size()) control = 0;
            fullGuidance(event->pos().x(),event->pos().y(),Xs_in[control+4],Ys_in[control+4],3);
        }

        if((abs(event->pos().x() - Xs_in[ctr]) < 10 && abs(event->pos().y() - Ys_in[ctr]) < 10) && ctr < Xs_in.size() - 1)
            ctr++;
    }

    if(visGuide){
        QPainter lookAhead(&image);
        lookAhead.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        if(ctr > 0 && ctr < Xs_in.size() - 3){
            QPoint point(Xs_in[ctr + 3], Ys_in[ctr + 3]), removed(Xs_in[ctr + 1], Ys_in[ctr + 1]);

            lookAhead.drawPoint(point);
            lookAhead.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            lookAhead.drawPoint(removed);

            this->update();
        }
    }
}

void Painting_area::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        drawing = false;
        blink->start(600);
    }
}

void Painting_area::paintEvent(QPaintEvent *event){
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void Painting_area::resizeEvent(QResizeEvent *event)
{
    QImage newImage(event->size(), QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), image);
    image = newImage;
}

QVector<int> Painting_area::getX_in(){
    return Xs_in;
}
QVector<int> Painting_area::getY_in(){
    return Ys_in;
}
QVector<int> Painting_area::getX_out(){
    return Xs_out;
}
QVector<int> Painting_area::getY_out(){
    return Ys_out;
}

void Painting_area::setX_in(QVector<int> X){
    Xs_in = X;
}
void Painting_area::setY_in(QVector<int> Y){
    Ys_in = Y;
}
void Painting_area::setX_out(QVector<int> X){
    Xs_out = X;
}
void Painting_area::setY_out(QVector<int> Y){
    Ys_out = Y;
}
void Painting_area::setGuide(bool check){
    visGuide = check;

    if(!check)
        clear();
}

void Painting_area::pasteImage(){
    QPainter painter(&image);
    painter.setPen(QPen(QColor(192,192,192), 10, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));

    QPoint point, nextPoint;

    for(int i = 0; i < Xs_in.size() - 1; i++){
        point.setX(Xs_in[i]);
        point.setY(Ys_in[i]);
        nextPoint.setX(Xs_in[i+1]);
        nextPoint.setY(Ys_in[i+1]);

        if(nextPoint.x() - point.x() <= 3 && nextPoint.y() - point.y() <= 3)
            painter.drawLine(point, nextPoint);
    }

    this->update();
}

void Painting_area::begin(){
    clear();
    animate = true;
}

void Painting_area::clear(){
    Xs_out.clear();
    Ys_out.clear();

    i = 0;
    animate = false;
    pressed = false;
    started = false;

    blink->start(600);

    image.fill(Qt::white);
    this->update();
}

void Painting_area::start(){
    clear();
    control =0;
    started = true;
    if(visGuide)
        pasteImage();
    if(Guidance=="Full")
    {
        QList <float> initial = normalizePixels(Xs_in[control],Ys_in[control]);
        QList <float> coords = mapToCoordinates(initial[0],initial[1]);
        int msg = SendMsg(coords[0],coords[1],4000);
        qDebug() <<"initial";
    }

}

void Painting_area::drawImage(){
    QPainter painter(&image);
    painter.setPen(QPen(QColor(192,192,192), 10, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));

    QPoint point, nextPoint;

    if(i < Xs_in.size() - 1 && animate){
        point.setX(Xs_in[i]);
        point.setY(Ys_in[i]);
        nextPoint.setX(Xs_in[i+1]);
        nextPoint.setY(Ys_in[i+1]);

        if(nextPoint.x() - point.x() <= 3 && nextPoint.y() - point.y() <= 3)
            painter.drawLine(point, nextPoint);

        i++;
        this->update();
    }
}

void Painting_area::blinker(){
    if(started){
        QPainter dot(&image);
        QPoint point(Xs_in[0], Ys_in[0]);

        if(!pressed && visGuide){
            if(blinker1){
                dot.setPen(QPen(Qt::blue, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                dot.drawPoint(point);
                blinker1 = false;
            }
            else{
                dot.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
                dot.drawPoint(point);
                blinker1 = true;
            }
        }

        else if(visGuide){
            dot.setPen(QPen(Qt::white, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            dot.drawPoint(point);
        }

        this->update();
    }
}

void Painting_area::setGuidance(QString x)
{
    Guidance = x;
}
