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

class Ui_Painting_Area
{
public:

    void setupUi(QWidget *Painting_Area)
    {
        if (Painting_Area->objectName().isEmpty())
            Painting_Area->setObjectName(QString::fromUtf8("Painting_Area"));
        Painting_Area->resize(800, 600);

        retranslateUi(Painting_Area);

        QMetaObject::connectSlotsByName(Painting_Area);
    } // setupUi

    void retranslateUi(QWidget *Painting_Area)
    {
        Painting_Area->setWindowTitle(QApplication::translate("Painting_Area", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Painting_Area: public Ui_Painting_Area {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTING_AREA_H
