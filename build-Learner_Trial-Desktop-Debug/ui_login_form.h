/********************************************************************************
** Form generated from reading UI file 'login_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FORM_H
#define UI_LOGIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_form
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *User;
    QLineEdit *Pass;
    QPushButton *Login;

    void setupUi(QWidget *Login_form)
    {
        if (Login_form->objectName().isEmpty())
            Login_form->setObjectName(QString::fromUtf8("Login_form"));
        Login_form->resize(283, 173);
        formLayoutWidget = new QWidget(Login_form);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 40, 221, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        User = new QLineEdit(formLayoutWidget);
        User->setObjectName(QString::fromUtf8("User"));

        formLayout->setWidget(0, QFormLayout::FieldRole, User);

        Pass = new QLineEdit(formLayoutWidget);
        Pass->setObjectName(QString::fromUtf8("Pass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Pass);

        Login = new QPushButton(Login_form);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(170, 120, 80, 24));
        Login->setStyleSheet(QString::fromUtf8("#Login {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Login:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        retranslateUi(Login_form);

        QMetaObject::connectSlotsByName(Login_form);
    } // setupUi

    void retranslateUi(QWidget *Login_form)
    {
        Login_form->setWindowTitle(QApplication::translate("Login_form", "Form", nullptr));
        label->setText(QApplication::translate("Login_form", "Username:", nullptr));
        label_2->setText(QApplication::translate("Login_form", "Password:", nullptr));
        Login->setText(QApplication::translate("Login_form", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_form: public Ui_Login_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FORM_H
