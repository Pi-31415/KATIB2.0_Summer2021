#ifndef TASKS_DONE_H
#define TASKS_DONE_H

#endif // TASKS_DONE_H

#include <QVector>

//These are the tasks completed by the student

class Completed{
    QVector<float> Xs, Ys;
    QString name, comment;
    int grade;

public:
    Completed(){
        Xs.clear();
        Ys.clear();
        name = "";
        comment = "";
        grade = 0;
    }

    void reset(){
        Xs.clear();
        Ys.clear();
        name = "";
        comment = "";
        grade = 0;
    }

    void set_Xs(QVector<float> in){Xs = in;}
    void set_Ys(QVector<float> in){Ys = in;}

    void set_Xs(float x){Xs.push_back(x);}
    void set_Ys(float y){Ys.push_back(y);}

    void set_Name(QString str){name = str;}
    void set_Comment(QString str){comment = str;}

    void set_Grade(int num){grade = num;}

    QVector<float> get_Xs(){return Xs;}
    QVector<float> get_Ys(){return Ys;}

    QString get_Name(){return name;}
    QString get_Comment(){return comment;}

    int get_Grade(){return grade;}
};
