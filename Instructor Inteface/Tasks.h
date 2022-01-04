#ifndef TASKS_H
#define TASKS_H

#endif // TASKS_H

#include <QVector>

//These are the tasks assgined

class Task{

    QVector<float> Xs, Ys;
    QString name,id;

public:
    Task(){
        Xs = {};
        Ys = {};
        name = "Task ";
    }

    void set_Xs(QVector<float> in){Xs = in;}
    void set_Ys(QVector<float> in){Ys = in;}

    void set_Xs(float x){Xs.push_back(x);}
    void set_Ys(float y){Ys.push_back(y);}

    void set_Name(QString str){name = str;}
    void clear()
    {
        Xs = {};
        Ys = {};
        name = "Task ";
    }
    QVector<float> get_Xs(){return Xs;}
    QVector<float> get_Ys(){return Ys;}
    QString get_Name(){return name;}
    void set_TaskId (QString str) {id = str;}
    QString get_task_id (){return id;}
};
