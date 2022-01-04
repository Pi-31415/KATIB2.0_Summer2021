#ifndef PAINTING_AREA_H
#define PAINTING_AREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QStringList>
#include <QTimer>
#include <QElapsedTimer>
#include <QFile>



namespace Ui {
class Painting_area;
}

class Painting_area : public QWidget
{
    Q_OBJECT

public:
    explicit Painting_area(QWidget *parent = nullptr);
    ~Painting_area();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

    QVector<int> getX_in();
    QVector<int> getY_in();
    QVector<int> getX_out();
    QVector<int> getY_out();

    void setX_in(QVector<int> X);
    void setY_in(QVector<int> X);
    void setX_out(QVector<int> X);
    void setY_out(QVector<int> X);

    void setGuide(bool check);

    void pasteImage();

    void setGuidance(QString);
    void callibration_routine();
    void SerialPort_Init();

private slots:
    void begin();
    void clear();
    void start();

public slots:
    void drawImage();
    void blinker();

private:
    Ui::Painting_area *ui;

    bool drawing, animate;
    bool visGuide, pressed;
    bool blinker1;
    bool started;
    QString Guidance;
    int i, ctr;

    QImage image;

    QPoint lastPoint;
    QColor brushColor;

    QVector<int> Xs_out, Xs_in;
    QVector<int> Ys_out, Ys_in;

    QTimer *timer;
    QTimer *blink;
};

#endif // PAINTING_AREA_H
