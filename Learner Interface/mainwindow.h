
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort>
#include <QThread>
#include <cmath>
#include <string>
#include <painting_area.h>
#include <task.h>
#include <user_info.h>
#include <QtSql>
#include <QSqlDatabase>
#include <login_form.h>
#include <QFile>

//Mainwindow is the main class, it routes the vector information to and from the painting area from the tasks available depending on user input
//The painting area class is responsible for creating the active area in the centre of the window, only one object of the painting area is
//instantiated, and it is created at run time.
//The Task class is responsible for holding all the coordinate information needed and the necessary containers to store student input

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace Ui {class Widget; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Called immedaitely at run time to store all the instructor input into task objects
    void load();
    bool save();
    void start();


signals:
    void preview();
    void reset();
    void startTask();

private slots:
    void on_exitBtn_clicked();
    void on_NextTaskBtn_clicked();
    void on_Preview_clicked();
    void on_PlaySound_clicked();
    void on_SubmitWorkBtn_clicked();
    void on_pushButton_clicked();
    void on_VisGuide_clicked();
    void on_VisGuide_clicked(bool checked);

    void on_ClearBtn_clicked();

    void on_SaveTskBtn_clicked();

    void on_PrevTskBtn_clicked();

    void on_OffG_clicked(bool checked);

    void on_PartialG_clicked(bool checked);

    void on_FullG_clicked(bool checked);
    void popup(QString text);

public slots:
    void correct_Cred();

private:
    Ui::MainWindow *ui;

    // There is only one object of painting area but there is a vector of tasks, needs to be dynamic as the number of tasks is only known at run time
    Painting_area active;
    QVector<Task> tasks;

    // Stores the information about which task is currently being interacted with at the present moment
    // the task with this index has the instructor drawing displayed on the screen and the user input is stored in it's vectors
    int index;
    int avg = 0, t = 0;
    bool hapGuide,valid_Login,saved;
    float thR, thL;
    float xc, yc;


    QString R_portName, L_portName, m_portName, Guidance = "off";

    QString Id;

    Login_form login;

    QSqlDatabase db;
    QStringList taskId;

};
#endif // MAINWINDOW_H
