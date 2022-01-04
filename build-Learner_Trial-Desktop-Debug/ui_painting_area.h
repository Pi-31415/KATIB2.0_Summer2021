/********************************************************************************
** Form generated from reading UI file 'painting_area.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTING_AREA_H
#define UI_PAINTING_AREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Painting_area
{
public:

    void setupUi(QWidget *Painting_area)
    {
        if (Painting_area->objectName().isEmpty())
            Painting_area->setObjectName(QString::fromUtf8("Painting_area"));
        Painting_area->resize(1429, 629);
        Painting_area->setCursor(QCursor(Qt::CrossCursor));
        Painting_area->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Painting_area);

        QMetaObject::connectSlotsByName(Painting_area);
    } // setupUi

    void retranslateUi(QWidget *Painting_area)
    {
        Painting_area->setWindowTitle(QApplication::translate("Painting_area", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Painting_area: public Ui_Painting_area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTING_AREA_H
