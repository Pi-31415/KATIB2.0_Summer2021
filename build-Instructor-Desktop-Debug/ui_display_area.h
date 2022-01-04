/********************************************************************************
** Form generated from reading UI file 'display_area.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_AREA_H
#define UI_DISPLAY_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Display_area
{
public:

    void setupUi(QWidget *Display_area)
    {
        if (Display_area->objectName().isEmpty())
            Display_area->setObjectName(QString::fromUtf8("Display_area"));
        Display_area->resize(300, 300);

        retranslateUi(Display_area);

        QMetaObject::connectSlotsByName(Display_area);
    } // setupUi

    void retranslateUi(QWidget *Display_area)
    {
        Display_area->setWindowTitle(QApplication::translate("Display_area", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display_area: public Ui_Display_area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_AREA_H
