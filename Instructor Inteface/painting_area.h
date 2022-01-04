#ifndef PAINTING_AREA_H
#define PAINTING_AREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>


namespace Ui {
class Painting_Area;
}

class Painting_Area : public QWidget
{
    Q_OBJECT

public:
    explicit Painting_Area(QWidget *parent = nullptr);
    ~Painting_Area();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);


    QVector<int> get_Xs(){return Xs;}
    QVector<int> get_Ys(){return Ys;}

    void clear();

private:
    Ui::Painting_Area *ui;

    QImage image;
    QPoint last_point;
    QVector<int> Xs, Ys;

    bool drawing;

};

#endif // PAINTING_AREA_H
