#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include <QDir>
#include <QTextStream>
#include <painting_area.h>
#include <display_area.h>
#include <login_form.h>
#include <Student.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Teacher; }
QT_END_NAMESPACE

class Teacher : public QMainWindow
{
    Q_OBJECT

public:
    Teacher(QWidget *parent = nullptr);
    ~Teacher();

    void load();
    void display();

private slots:
    void on_Clear_clicked();
    void on_Save_clicked();
    void on_Letter_name_textChanged(const QString &arg1);
    void on_Delete_clicked();
    void on_Task_list_itemSelectionChanged();
    void on_Student_list_itemSelectionChanged();
    void on_Assign_clicked();
    void on_Drop_clicked();
    void on_Assigned_tasks_list_itemSelectionChanged();
    void on_Next_clicked();
    void on_Previous_clicked();
    void on_Completed_tasks_list_currentRowChanged(int currentRow);
    void on_Assign_all_clicked();
    void on_graded_students_list_itemSelectionChanged();

    void on_Save_feedback_clicked();


    void on_Task_list_currentRowChanged(int currentRow);

    void on_Task_list_itemClicked(QListWidgetItem *item);

public slots:
    void correct_Cred();

private:
    Ui::Teacher *ui;

    Painting_Area active;
    Display_area grading, assigning;
    Login_form login;

    Task task_Temp;
    Completed completed_Task_Temp;
    Student student_Temp;

    QVector<Task> new_tasks;
    QVector<Student> student_vector;

    bool task_selected, assigned_task_selected, student_selected, name_changed, disp;
    bool valid_Login;

    int grading_index =0;

    QSqlDatabase db;
    QString adminId, adminName;
};
#endif // TEACHER_H
