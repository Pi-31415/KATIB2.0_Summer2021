#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Login_form;
}

class Login_form : public QDialog
{
    Q_OBJECT

public:
    explicit Login_form(QWidget *parent = nullptr);
    ~Login_form();

    QString get_User(){return user;}
    QString get_Pass(){return pass;}

    void isValid();

signals:
    void check_Cred();

private slots:
    void on_Login_clicked();

private:
    Ui::Login_form *ui;

    QString user, pass;
    bool valid_Cred;
};

#endif // LOGIN_FORM_H
