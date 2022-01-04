#include "display_area.h"
#include "ui_display_area.h"

Display_area::Display_area(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Display_area)
{
    ui->setupUi(this);

    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);
}

Display_area::~Display_area()
{
    delete ui;
}

void Display_area::paintEvent(QPaintEvent *event){
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), image, image.rect());
}

void Display_area::clear(){
    Xs.clear();
    Ys.clear();

    image.fill(Qt::white);
    this->update();
}

void Display_area::display(){
    QPainter imagePainter(&image);
    imagePainter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    QPoint point, next_point;
    for(int i = 1; i < Xs.size(); i++){
        point.setX(Xs[i-1]);
        point.setY(Ys[i-1]);
        next_point.setX(Xs[i]);
        next_point.setY(Ys[i]);

        if(abs((Xs[i] - Xs[i-1])) < 7 || abs((Ys[i] - Ys[i-1])) < 7)
            imagePainter.drawLine(point, next_point);
    }

    this->update();
}
