#include "login_form.h"
#include "ui_login_form.h"

Login_form::Login_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_form)
{
    ui->setupUi(this);
    ui->Pass->setEchoMode(QLineEdit::Password);
    setWindowTitle("Login");
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlag(Qt::WindowTitleHint);
}

Login_form::~Login_form()
{
    delete ui;
}

void Login_form::on_Login_clicked(){
    isValid();
    if(valid_Cred){
       user = ui->User->text();
       pass = ui->Pass->text();
       emit check_Cred();
    }
}

void Login_form::isValid(){
    if(ui->User->text() == ""){
        QMessageBox::warning(this, "Invalid Username", "Username field left empty!");
        valid_Cred = false;
    }
    else if(ui->Pass->text() == ""){
        QMessageBox::warning(this, "Invalid Password", "Password field left empty!");
        valid_Cred = false;
    }
    else
        valid_Cred = true;
}
