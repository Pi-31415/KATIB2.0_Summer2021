#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QVector>
#include <QDebug>

class Task{
    QVector<int> Xs_in, Xs_out;
    QVector<int> Ys_in, Ys_out;
    QString comments, name;

public:
    Task(){
        Xs_in = {};
        Ys_in = {};
        Xs_out = {};
        Ys_out = {};
    }
    Task(QVector<int> Xs_in, QVector<int> Xs_out, QVector<int> Ys_in, QVector<int> Ys_out){
        this->Xs_in = Xs_in;
        this->Xs_out = Xs_out;
        this->Ys_in = Ys_in;
        this->Ys_out = Ys_out;
    }

    QVector<int> getX_in(){
        return Xs_in;
    }
    QVector<int> getY_in(){
        return Ys_in;
    }
    QVector<int> getX_out(){
        return Xs_out;
    }
    QVector<int> getY_out(){
        return Ys_out;
    }

    void setX_in(int i, int num){
        Xs_in.insert(i, num);
    }
    void setY_in(int i, int num){
        Ys_in.insert(i, num);
    }
    void setX_out(int i, int num){
        Xs_out.insert(i, num);
    }
    void setY_out(int i, int num){
        Ys_out.insert(i, num);
    }

    void setX_in(int num){
        Xs_in.push_back(num);
    }
    void setY_in(int num){
        Ys_in.push_back(num);
    }
    void setX_out(int num){
        Xs_out.push_back(num);
    }
    void setY_out(int num){
        Ys_out.push_back(num);
    }

    void setX_in(QVector<int> X){
        Xs_in = X;
    }
    void setY_in(QVector<int> Y){
        Ys_in = Y;
    }
    void setX_out(QVector<int> X){
        Xs_out = X;
    }
    void setY_out(QVector<int> Y){
        Ys_out = Y;
    }

    QString getName(){
        return name;
    }

    void setName(QString string){
        //string.chop(4);
        name = string;
    }

};

#endif // TASK_H
