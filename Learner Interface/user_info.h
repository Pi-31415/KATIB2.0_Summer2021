#ifndef USER_INFO_H
#define USER_INFO_H

#include <QDialog>

namespace Ui {
class User_info;
}

class User_info : public QDialog
{
    Q_OBJECT

public:
    explicit User_info(QWidget *parent = nullptr);
    ~User_info();

private:
    Ui::User_info *ui;
};

#endif // USER_INFO_H
