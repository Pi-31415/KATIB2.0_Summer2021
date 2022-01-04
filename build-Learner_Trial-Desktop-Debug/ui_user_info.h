/********************************************************************************
** Form generated from reading UI file 'user_info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_INFO_H
#define UI_USER_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_info
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;

    void setupUi(QDialog *User_info)
    {
        if (User_info->objectName().isEmpty())
            User_info->setObjectName(QString::fromUtf8("User_info"));
        User_info->resize(345, 245);
        formLayoutWidget = new QWidget(User_info);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 291, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEdit);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_4);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_5);

        lineEdit_6 = new QLineEdit(formLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_6);

        lineEdit_7 = new QLineEdit(formLayoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_7);

        lineEdit_8 = new QLineEdit(formLayoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_8);

        lineEdit_9 = new QLineEdit(formLayoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lineEdit_9);

        lineEdit_10 = new QLineEdit(formLayoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_10);

        lineEdit_11 = new QLineEdit(formLayoutWidget);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lineEdit_11);

        lineEdit_12 = new QLineEdit(formLayoutWidget);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_12);


        retranslateUi(User_info);

        QMetaObject::connectSlotsByName(User_info);
    } // setupUi

    void retranslateUi(QDialog *User_info)
    {
        User_info->setWindowTitle(QApplication::translate("User_info", "Dialog", nullptr));
        lineEdit->setText(QApplication::translate("User_info", "Name:", nullptr));
        lineEdit_3->setText(QApplication::translate("User_info", "Student ID:", nullptr));
        lineEdit_5->setText(QApplication::translate("User_info", "Age:", nullptr));
        lineEdit_7->setText(QApplication::translate("User_info", "Grade:", nullptr));
        lineEdit_9->setText(QApplication::translate("User_info", "Tasks Completed:", nullptr));
        lineEdit_11->setText(QApplication::translate("User_info", "Instructor:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_info: public Ui_User_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_INFO_H
