#include "painting_area.h"
#include "ui_painting_area.h"

Painting_Area::Painting_Area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Painting_Area)
{
    ui->setupUi(this);
    setFixedSize(this->size());

    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);

    drawing = false;
}

Painting_Area::~Painting_Area()
{
    delete ui;
}

void Painting_Area::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton
       && event->pos().x() > 0
       && event->pos().y() > 0
       && event->pos().x() < 800
       && event->pos().y() < 600){
        drawing = true;
        last_point = event->pos();

        Xs.push_back(event->pos().x());
        Ys.push_back(event->pos().y());
    }
}

void Painting_Area::mouseMoveEvent(QMouseEvent *event){
    if ((event->buttons() & Qt::LeftButton) && drawing
            && event->pos().x() > 0
            && event->pos().y() > 0
            && event->pos().x() < 800
            && event->pos().y() < 600){

            QPainter painter(&image);
            painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
            painter.drawLine(last_point, event->pos());

            Xs.push_back(event->pos().x());
            Ys.push_back(event->pos().y());
            last_point = event->pos();
            this->update();
    }
}

void Painting_Area::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        drawing = false;
    }
}

void Painting_Area::paintEvent(QPaintEvent *event){
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void Painting_Area::clear(){
    Xs.clear();
    Ys.clear();

    image.fill(Qt::white);
    this->update();
}
