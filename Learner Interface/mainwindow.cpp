#include "mainwindow.h"
#include "ui_mainwindow.h"

//This constructor is the first thing that is called when the program runs
//everything within this block needs to happen before any user input
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    connect(&login, SIGNAL(check_Cred()), this, SLOT(correct_Cred()));
/*
    db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("127.0.0.1");
            db.setUserName("root");
            db.setPassword("");
            db.setDatabaseName("qt5");
            */

    // Connect to Database
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("katibproject.cbzdtmrltiha.us-east-2.rds.amazonaws.com");
        db.setUserName("admin");
        db.setPassword("Tgmkh333");
        db.setDatabaseName("katibproject");

    //initialize serial port and start Login procedure
    active.SerialPort_Init();
    login.setModal(true);
    login.exec();
    correct_Cred();


    // index is intialized at zero for the first task
    index = 0;

    hapGuide = false;

    //Setting up the UI for the window and connecting the painting area's UI to the window
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(0, &active);
    ui->stackedWidget->setCurrentIndex(0);

    //Setting the window title to something approporiate
    this->setWindowTitle("AIM Lab Writing Tool");

    //Connecting signals and slots allows for communication between different UI files (here it's mainwindow and painting area)
    connect(this, SIGNAL(preview()), &active, SLOT(begin()));
    connect(this, SIGNAL(reset()), &active, SLOT(clear()));
    connect(this, SIGNAL(startTask()), &active, SLOT(start()));

    //Size must be constant
    setFixedSize(this->size());

    //Load function is called intially to recursively store all the coordinate information into the vectors
    load();
    if(tasks.size()>0)
    {
    //The first task is loaded into the painting area
    active.setX_in(tasks[0].getX_in());
    active.setY_in(tasks[0].getY_in());
    active.setX_out(tasks[0].getX_out());
    active.setY_out(tasks[0].getY_out());

    ui->InstructionsTxtBox->setPlainText(tasks[0].getName());
    start();
    }
    else
    {
        QMessageBox::information (this, "No tasks", "There are no assigned tasks right now");
        exit(0);
    }
    //start callibration routine
    active.callibration_routine();
}

MainWindow::~MainWindow(){
   db.close();
    delete ui;
}

void MainWindow::correct_Cred(){
    if(db.open())
        {
                //Get data from user input
            QString Username = login.get_User();
            QString Password = login.get_Pass();

                // Get data from database
            QSqlQuery query;
            query.prepare("SELECT * FROM student WHERE username = :username "
                                   "AND password = :password");
            query.bindValue(":username", Username);
            query.bindValue(":password", Password);

                //Verify Data
            if (!query.exec())
                {
                QMessageBox::information (this, "Error", "Error Accessing Database");
                exit(-1);
                }

            else{
                while (query.next())
                {
                    QString Uname = query.value(4).toString();
                    QString Pword = query.value(5).toString();
                    if (Username ==Uname && Password == Pword)
                    {
                        valid_Login = true;
                        Id = query.value(0).toString();
                    }
                    else exit(-1);
                }

                if (!valid_Login)
                   {
                    QMessageBox::information (this, "Error", "Username or Password not found");
                    exit(-1);
                   }
                else login.close();
                }
        }
    else
    {
        QMessageBox::information(this,"Not Connected", "Error Accessing Database");
        exit(-1);
    }
}

void MainWindow::load(){
    QSqlQuery query, query2;
    QList <QStringList>  Coordinates;
    QStringList taskNames;
    query.prepare("SELECT * FROM student WHERE id = :id");
    query.bindValue(":id", Id);
    query.exec();
    query.next();

    if(query.value(8)!="")
    {   //get the IDs of the tasks assigned to the student
        taskId =query.value(8).toString().split(",");
        //load coordinates of those tasks one by one from 'tasks' table
        for (int i=0;i<taskId.size();i++)
        {
            query2.prepare("SELECT * FROM tasks WHERE id = :id");
            query2.bindValue(":id", taskId[i]);
            query2.exec();
            query2.next();
            Coordinates.append(query2.value(4).toString().split(" "));
            taskNames.append(query2.value(1).toString()+ query2.value(0).toString());
        }

        //load tasks into the tasks list
        for (int i=0;i<Coordinates.size();i++)
        {
            Task temp;
            temp.setName(taskNames[i]);
            for (int j=0; j<Coordinates[i].size();j++)
            {
                temp.setX_in(Coordinates[i][j].split(",")[0].toFloat()*1431);
                temp.setY_in(Coordinates[i][j].split(",")[1].toFloat()*631);
            }

            active.setX_in(temp.getX_in());
            active.setY_in(temp.getY_in());

            tasks.push_back(temp);
        }
    }
}

//korres exiting the window (usefull for remote debugging)
void MainWindow::on_exitBtn_clicked(){
    MainWindow::close();
}
void MainWindow::on_Preview_clicked(){
    emit preview();
}


void MainWindow::start()
{
    emit startTask();
}


void MainWindow::on_NextTaskBtn_clicked(){
   //function to load next task into active area

    if ((index +1) < taskId.size()) //check if last item is not reached
    {
       if(!active.getX_out().empty() && !saved)
       {
           QMessageBox box;
           box.setText("Do you want to save your changes?");
           box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
           box.setWindowTitle("Task modified");
           box.button(QMessageBox::Discard)->setText("Discard");
           box.setDefaultButton(QMessageBox::Save);
           box.move(geometry().x()+450, geometry().y()+370);
           int result = box.exec();
           switch (result)
           {
            case QMessageBox::Save:
               if(save())
               {
               emit reset();
               index++;
               active.setX_in(tasks[index%tasks.size()].getX_in());
               active.setY_in(tasks[index%tasks.size()].getY_in());
               active.setX_out(tasks[index%tasks.size()].getX_out());
               active.setY_out(tasks[index%tasks.size()].getY_out());
               ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
               start();
               }
               break;
             case QMessageBox::Discard:
               emit reset();
               index++;
               active.setX_in(tasks[index%tasks.size()].getX_in());
               active.setY_in(tasks[index%tasks.size()].getY_in());
               active.setX_out(tasks[index%tasks.size()].getX_out());
               active.setY_out(tasks[index%tasks.size()].getY_out());
               ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
               start();
               break;
           }
       }
       else
       {
           save();
           emit reset();

           index++;
           active.setX_in(tasks[index%tasks.size()].getX_in());
           active.setY_in(tasks[index%tasks.size()].getY_in());
           active.setX_out(tasks[index%tasks.size()].getX_out());
           active.setY_out(tasks[index%tasks.size()].getY_out());

           ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
           start();

       }
    }
    else
        popup("Last task reached");
    saved = false;
}

void MainWindow::on_PlaySound_clicked(){
    //emit some signal
}

void MainWindow::on_SubmitWorkBtn_clicked(){
    //function to save your work to the database
    save();
    QSqlQuery query,query2;
    QString x;

    int c = 0;
    if(db.open())
    {
        foreach(Task t, tasks)
        {
          x = "";
          x.append("'");
           for(int i = 0; i < t.getX_out().size(); i++)
           {
               x.append(QString::number((float)t.getX_out()[i]/1431) + "," + QString::number((float)t.getY_out()[i]/631) + " ");
           }
          if(t.getX_out().size() >0)x.chop(1);
          x.append("'");
          query2.prepare(QString("SELECT * FROM %1 WHERE taskid = %2 AND studentid = %3").arg("tasksAttempted").arg(taskId[c]).arg(Id));
          query2.exec();
          // check if task is already stored
          if (query2.next())
          {
           // update task if it already exists
              query.exec(QString("UPDATE %1 SET coordinates = %2 WHERE taskid = %3 AND studentid = %4").arg("tasksAttempted").arg(x).arg(taskId[c++]).arg(Id));
          }
          else
          {
             // create new entry if it does not exist
            query.prepare(QString("INSERT INTO %1 (taskid,coordinates,studentid) VALUES (%2,%3,%4)").arg("tasksAttempted").arg(taskId[c++]).arg(x).arg(Id));
            query.exec();
          }
        }
        popup ("Submitted successfully");
        qDebug() << query.lastError();
        qDebug() << query2.lastError();
     }
}

void MainWindow::on_pushButton_clicked(){
    User_info stats;
    stats.setModal(true);
    stats.exec();
}

void MainWindow::on_VisGuide_clicked(){
    emit reset();
}

void MainWindow::on_VisGuide_clicked(bool checked){
    //check box to start Visual Guidance
    active.setGuide(checked);
    start();
}

void MainWindow::on_ClearBtn_clicked()
{
    emit startTask();
}

bool MainWindow::save()
{
    // save attempted task to the tasks list to prepare the list for submission
    if (active.getX_out().empty())
    {
        QVector<int> temp = {0};
        tasks[index].setX_out(temp);
        tasks[index].setY_out({temp});
        saved = true;
        return true;
    }

    tasks[index].setX_out(active.getX_out());
    tasks[index].setY_out(active.getY_out());
    popup("Task saved successfully");
    saved = true;
    return true;
}

void MainWindow::on_SaveTskBtn_clicked()
{
  save();
}


void MainWindow::on_PrevTskBtn_clicked()
{
    // function to lead previous task on the active screen
    if(index>0)
    {
        if(!active.getX_out().empty() && !saved)
        {
            QMessageBox box;
            box.setText("Do you want to save your changes?");
            box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
            box.setWindowTitle("Task modified");
            box.button(QMessageBox::Discard)->setText("Discard");
            box.setDefaultButton(QMessageBox::Save);
            box.move(geometry().x()+450, geometry().y()+370);
            int result = box.exec();
            switch (result)
            {
             case QMessageBox::Save:
                if(save())
                {
                emit reset();
                index--;
                active.setX_in(tasks[index%tasks.size()].getX_in());
                active.setY_in(tasks[index%tasks.size()].getY_in());
                active.setX_out(tasks[index%tasks.size()].getX_out());
                active.setY_out(tasks[index%tasks.size()].getY_out());
                ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
                start();
                }
                break;
              case QMessageBox::Discard:
                emit reset();
                index--;
                active.setX_in(tasks[index%tasks.size()].getX_in());
                active.setY_in(tasks[index%tasks.size()].getY_in());
                active.setX_out(tasks[index%tasks.size()].getX_out());
                active.setY_out(tasks[index%tasks.size()].getY_out());
                ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
                start();
                break;
            }
        }
        else
        {
            save();
            emit reset();
            index--;
            active.setX_in(tasks[index%tasks.size()].getX_in());
            active.setY_in(tasks[index%tasks.size()].getY_in());
            active.setX_out(tasks[index%tasks.size()].getX_out());
            active.setY_out(tasks[index%tasks.size()].getY_out());
            ui->InstructionsTxtBox->setPlainText(tasks[index%tasks.size()].getName());
            start();
        }
    }
    else
      popup("First task reached");
    saved = false;
}

void MainWindow::on_OffG_clicked(bool checked){
   // Haptic Guidance Off
    if (checked)
        active.setGuidance("Off");
    start();
}

void MainWindow::on_PartialG_clicked(bool checked)
{ // Partial Haptic Guidance clicked

    if (checked)
        active.setGuidance("Partial");
    start();
}

void MainWindow::on_FullG_clicked(bool checked)
{
    //Full Haptic Guidance clicked
    if (checked)
        active.setGuidance("Full");
    start();
}
void MainWindow::popup(QString text)
{
    //function to didplay popup messages
       QMessageBox *box = new QMessageBox;
       box->setText(text);
       box->setStandardButtons(0);
       box->setWindowFlag(Qt::FramelessWindowHint);
       box->setModal(false);
       box->move(geometry().x()+1000, geometry().y()+370);
       box->setIcon(QMessageBox::Information);
       box->show();
       QTimer::singleShot(2000,box,SLOT(hide()));
}
