#include "user_info.h"
#include "ui_user_info.h"

User_info::User_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_info)
{
    ui->setupUi(this);
    setFixedSize(this->size());
}

User_info::~User_info()
{
    delete ui;
}
