#include "teacher.h"
#include "ui_teacher.h"

// #define current_Name new_tasks[ui->Task_list->currentRow()].get_Name()

Teacher::Teacher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Teacher){

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


    login.setModal(true);
    login.exec();
    correct_Cred();

    ui->setupUi(this);
    setFixedSize(this->size());
    statusBar()->setSizeGripEnabled(false);
    setWindowTitle("Katib - Instructor");

    ui->tab->setAutoFillBackground(true);
    ui->tab_2->setAutoFillBackground(true);
    ui->tab_3->setAutoFillBackground(true);
    ui->tabWidget->setTabText(0, "Feedback");
    ui->tabWidget->setTabText(1, "Assigning");
    ui->tabWidget->setTabText(2, "New Tasks");

    ui->Grade->setMaximum(10);

    ui->Letter_name->setPlaceholderText("Optional");
    ui->Comment_box->setPlaceholderText("Provide feedback, optional");
    ui->Description->setPlaceholderText("Provide a description of the task");

    ui->Painting_area->insertWidget(0, &assigning);
    ui->Painting_area->setCurrentIndex(0);

    ui->Painting_area_2->insertWidget(0, &grading);
    ui->Painting_area_2->setCurrentIndex(0);

    ui->Painting_area_3->insertWidget(0, &active);
    ui->Painting_area_3->setCurrentIndex(0);

    task_selected = true;
    student_selected = false;
    name_changed = false;

    load();
}

Teacher::~Teacher(){
   db.close();
    delete ui;
}


void Teacher::correct_Cred() {

    if(db.open())
        {
                //Get data from user input
            QString Username = login.get_User();
            QString Password = login.get_Pass();

                // Get data from database
            QSqlQuery query;
            query.prepare("SELECT * FROM admin WHERE username = :username "
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
                    QString Uname = query.value(1).toString();
                    QString Pword = query.value(2).toString();
                    if (Username ==Uname && Password == Pword)
                    {
                        valid_Login = true;
                        adminId = query.value(0).toString();
                        adminName = query.value(1).toString();
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

void Teacher::on_Clear_clicked(){
    active.clear();
}

void Teacher::load(){

    if(db.open())
    {
        QSqlQuery query,query2;
        QStringList StudentId;

        query.prepare("SELECT * FROM student" );
        if (!query.exec())
        {
            QMessageBox::information (this, "Error", "Error Accessing Database");
            exit(-1);
        }
        else
        {
            QVector<QString> name_list;
            while (query.next())
            {
                // get student list
                QString convert = query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(1).toString();
                student_Temp.set_Name(convert);
                student_Temp.set_Id(query.value(0).toString());
                if (query.value(8).toString() != "")student_Temp.set_Task_IDs(query.value(8).toString().split(","));
                student_vector.push_back(student_Temp);
                student_Temp.clear();
                name_list.push_back(convert);
                ui->Student_list->addItem(convert);
                ui->graded_students_list->addItem(convert);
                StudentId.append(query.value(0).toString());
            }

            //get task list
            query.exec("SELECT * FROM tasks");
            while(query.next())
            {
                task_Temp.set_Name(query.value(2).toString());
                task_Temp.set_TaskId(query.value(0).toString());
                QStringList Coordinates;
                Coordinates = query.value(4).toString().split(" ");
                //QVector X_list, Y_list;
                for (int i =0;i<Coordinates.size();i++)
                {
                    task_Temp.set_Xs(Coordinates[i].split(",")[0].toFloat()*300);
                     task_Temp.set_Ys(Coordinates[i].split(",")[1].toFloat()*300);
                }
                ui->Task_list->addItem(QString::number(new_tasks.size() + 1) + ". " + task_Temp.get_Name()+ "(" + task_Temp.get_task_id() + ")");
                new_tasks.push_back(task_Temp);
                task_Temp.clear();
            }
            if (new_tasks.size()==0)
            {
                query.exec("ALTER TABLE tasks AUTO_INCREMENT=1;");
            }
            int i = 0;
            foreach (QString Id, StudentId) //for each student
            {

                query.exec(QString("SELECT * from %1 WHERE studentid = %2").arg("tasksAttempted").arg(Id));
                while(query.next()) // for each task of every student
                {
                    // get coordinates
                    QStringList list;
                    list.append(query.value(2).toString().split(" "));
                    for (int i=0;i<list.size();i++)
                    {
                        completed_Task_Temp.set_Xs(list[i].split(",")[0].toFloat()*300);
                        completed_Task_Temp.set_Ys(list[i].split(",")[1].toFloat()*300);
                    }

                    //get task id
                    QString temp = query.value(0).toString();
                    query2.prepare("SELECT * FROM tasks WHERE id = :id");
                    query2.bindValue(":id",temp);
                    query2.exec();
                    query2.next();

                    completed_Task_Temp.set_Name(temp+" " + query2.value(2).toString());
                    student_vector[i].set_Completed_Task(completed_Task_Temp);
                    completed_Task_Temp.reset();
                }
                i++;
            }
        }
    }
}

void Teacher::display(){
    grading.clear();
    grading.set_Xs(student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks()[grading_index].get_Xs());
    grading.set_Ys(student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks()[grading_index].get_Ys());
    grading.display();
}
QString Arg1;
void Teacher::on_Save_clicked(){
    QVector<float> x,y,X_list, Y_list;
    if(!active.get_Xs().isEmpty()){

        for (int i = 0; i<active.get_Xs().size();i++)
        {
            X_list.push_back(active.get_Xs()[i]);
            Y_list.push_back(active.get_Ys()[i]);
            x.push_back(active.get_Xs()[i]*0.375);
            y.push_back(active.get_Ys()[i]*0.5);
        }

        task_Temp.set_Xs(x);
        task_Temp.set_Ys(y);

        if(!name_changed)
            task_Temp.set_Name("Task " + QString::number(new_tasks.size() + 1));
        else
        {
            task_Temp.set_Name(Arg1);
        }
        if(new_tasks.size()>0)
        {
            task_Temp.set_TaskId(QString::number(new_tasks.back().get_task_id().toInt() + 1));
        }
        else
        {
            task_Temp.set_TaskId("1");
        }
        ui->Task_list->addItem(QString::number(new_tasks.size() + 1) + ". " + task_Temp.get_Name()+ "(" + task_Temp.get_task_id() + ")");

        new_tasks.push_back(task_Temp);

        name_changed = false;

    }
    if (db.open())
    {
        QString x;
        for (int i =0; i<X_list.size();i++)
        {
            x.append(QString::number((float)X_list[i]/800) +","+ QString::number((float)Y_list[i]/600) +" ");
        }
        if(X_list.size()>0) x.chop(1);
        QSqlQuery query;
        query.prepare("INSERT INTO tasks (task_name,Letter_Name,Description,coordinates) VALUES (:tname,:lname,:descr,:x)");
        query.bindValue(":tname",adminName);
        query.bindValue(":lname",ui->Letter_name->text());
        query.bindValue(":descr",ui->Description->toPlainText());
        query.bindValue(":x",x);
        query.exec();
    }
    active.clear();
    ui->Letter_name->clear();
    ui->Description->clear();
}

void Teacher::on_Letter_name_textChanged(const QString &arg1){
    if(!arg1.isEmpty()){
        name_changed = true;
        Arg1 = arg1;
    }
}

void Teacher::on_Delete_clicked(){
    if(ui->Task_list->currentRow()!=-1)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM tasks WHERE id = :id");
        query.bindValue(":id",new_tasks[ui->Task_list->currentRow()].get_task_id());
        query.exec();
        QString tskId = new_tasks[ui->Task_list->currentRow()].get_task_id();

        for(int i=0;i<student_vector.size();i++)
        {
           student_vector[i].remove_task(tskId);
           QString tskid = student_vector[i].get_Task_IDs().join(",");
           query.prepare(QString("UPDATE student SET task_assigned = %1 WHERE id = %2").arg("'" + tskid+"'").arg("'" + student_vector[i].get_Id()) + "'");
           query.exec();
        }
        if(task_selected)
        {
            int cur = ui->Task_list->currentRow();
            qDeleteAll(ui->Task_list->selectedItems());
            new_tasks.remove(cur);
            //ui->Task_list->takeItem(cur);
            qDebug()<< "444";
        }
        ui->Task_list->clear();

        for(int i = 0; i < new_tasks.size(); i++)
        {
            ui->Task_list->addItem(QString::number(i + 1) + ". " + new_tasks[i].get_Name());
        }
        task_selected = false;
        if (new_tasks.isEmpty())
        {
            query.exec("ALTER TABLE tasks AUTO_INCREMENT=1;");
        }
    }
}

void Teacher::on_Task_list_itemSelectionChanged(){
    task_selected = true;
}

void Teacher::on_Student_list_itemSelectionChanged(){
    ui->Assigned_tasks_list->clear();
    student_selected = true;

    for(int i = 0; i < student_vector[ui->Student_list->currentRow()].get_Task_IDs().size(); i++){
        ui->Assigned_tasks_list->addItem(student_vector[ui->Student_list->currentRow()].get_Task_IDs()[i]);
    }
}

void Teacher::on_Assign_clicked(){
    if(task_selected && student_selected){
        ui->Assigned_tasks_list->addItem(new_tasks[ui->Task_list->currentRow()].get_task_id());
        student_vector[ui->Student_list->currentRow()].set_Task_IDs(new_tasks[ui->Task_list->currentRow()].get_task_id());
        //update database
        QSqlQuery query;
        QString tskid = student_vector[ui->Student_list->currentRow()].get_Task_IDs().join(",");
        if (tskid[0]=="'") tskid.remove(0,1);
       query.prepare(QString("UPDATE student SET task_assigned = %1 WHERE id = %2").arg("'" + tskid+"'").arg("'" + student_vector[ui->Student_list->currentRow()].get_Id()) + "'");
       query.exec();
    }
}

void Teacher::on_Drop_clicked(){
    if(assigned_task_selected && student_selected){
        student_vector[ui->Student_list->currentRow()].remove_task(ui->Assigned_tasks_list->currentRow());
        ui->Assigned_tasks_list->takeItem(ui->Assigned_tasks_list->currentRow());

        //update Database
        QSqlQuery query;
        QString tskid = student_vector[ui->Student_list->currentRow()].get_Task_IDs().join(",");
       query.prepare(QString("UPDATE student SET task_assigned = %1 WHERE id = %2").arg("'" + tskid+"'").arg("'" + student_vector[ui->Student_list->currentRow()].get_Id()) + "'");
       query.exec();
    }
    //assigned_task_selected = false;
}

void Teacher::on_Assigned_tasks_list_itemSelectionChanged(){
    assigned_task_selected = true;
}

void Teacher::on_Next_clicked(){
    if (ui->graded_students_list->currentRow() >= 0)
    {
    if(grading_index != student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks().size() - 1)
        grading_index++;
    display();
    }
}

void Teacher::on_Previous_clicked(){
    if (ui->graded_students_list->currentRow() >= 0)
    {
    if(grading_index > 0)
        grading_index--;
    if (ui->graded_students_list->currentRow() >= 0)
    display();
    }
}

void Teacher::on_Completed_tasks_list_currentRowChanged(int currentRow){
    grading_index = currentRow;
    if(disp) display();
}

void Teacher::on_Assign_all_clicked(){
    if(task_selected){
        ui->Assigned_tasks_list->addItem(new_tasks[ui->Task_list->currentRow()].get_task_id());
        QSqlQuery query;
        QString tskid;
        for(int i = 0; i < student_vector.size(); i++){
            student_vector[i].set_Task_IDs(new_tasks[ui->Task_list->currentRow()].get_task_id());
            tskid = student_vector[i].get_Task_IDs().join(",");
            if (tskid[0]=="'") tskid.remove(0,1);
           query.prepare(QString("UPDATE student SET task_assigned = %1 WHERE id = %2").arg("'" + tskid+"'").arg("'" + student_vector[i].get_Id()) + "'");
           query.exec();
        }
    }
}

void Teacher::on_graded_students_list_itemSelectionChanged(){
    disp = false;
    ui->Completed_tasks_list->clear();
    disp = true;
    for(int i = 0; i < student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks().size(); i++){
        ui->Completed_tasks_list->addItem(student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks()[i].get_Name());
    }
}

void Teacher::on_Save_feedback_clicked()
{
    QSqlQuery query;
    QString tsk_Id = student_vector[ui->graded_students_list->currentRow()].get_Completed_Tasks()[ui->Completed_tasks_list->currentRow()].get_Name().split(" ")[0];
    qDebug() << tsk_Id;
    QString std_Id = student_vector[ui->graded_students_list->currentRow()].get_Id();
    query.prepare(QString("UPDATE %1 SET comments = %2, score = %3 WHERE taskid = %4 AND studentid = %5").arg("tasksAttempted").arg("'"+ui->Comment_box->toPlainText()+"'").arg("'"+ui->Grade->text()+"'").arg(tsk_Id).arg(std_Id));
    query.exec();
    qDebug()<<query.lastError();
    ui->Comment_box->clear();
    ui->Grade->clear();
}

void Teacher::on_Task_list_currentRowChanged(int currentRow)
{
    if(task_selected && currentRow != -1)
    {
    assigning.clear();
    assigning.set_Xs(new_tasks[currentRow].get_Xs());
    assigning.set_Ys(new_tasks[currentRow].get_Ys());
    assigning.display();
    }
}


void Teacher::on_Task_list_itemClicked(QListWidgetItem *item)
{
    task_selected = true;
}
