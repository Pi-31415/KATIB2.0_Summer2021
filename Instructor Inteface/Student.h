#ifndef STUDENT_H
#define STUDENT_H

#endif // STUDENT_H

#include <QVector>
#include <Tasks_done.h>
#include <Tasks.h>

class Student{
    QString name,StudentId;
    QVector<Completed> completed_Tasks;
    QStringList task_IDs;

public:
    Student(){
        name = "Student";
        completed_Tasks = {};
        task_IDs.clear();
    }

    QString get_Name(){return name;}
    QString get_Id() {return StudentId;}
    QVector<Completed> get_Completed_Tasks(){return completed_Tasks;}
    QStringList get_Task_IDs(){return task_IDs;}
    void remove_task(int index) {task_IDs.removeAt(index);}
    void remove_task(QString str) {task_IDs.removeOne(str);}

    void set_Name(QString str){name = str;}
    void set_Id (QString str) {StudentId = str;}
    void set_Completed_Task(Completed t){completed_Tasks.push_back(t);}
    void set_Task_IDs(QString str){task_IDs.push_back(str);}
    void set_Task_IDs(QStringList str){task_IDs = str;}
    void clear() {task_IDs.clear();}

};
