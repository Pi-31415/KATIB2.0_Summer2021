#ifndef DISPLAY_AREA_H
#define DISPLAY_AREA_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Display_area;
}

class Display_area : public QWidget
{
    Q_OBJECT

public:
    explicit Display_area(QWidget *parent = nullptr);
    ~Display_area();

    void set_Xs(QVector<float> X){Xs = X;}
    void set_Ys(QVector<float> Y){Ys = Y;}

    void paintEvent(QPaintEvent *event);
    void clear();
    void display();

private:
    Ui::Display_area *ui;

    QImage image;
    QVector<float> Xs, Ys;

};

#endif // DISPLAY_AREA_H
