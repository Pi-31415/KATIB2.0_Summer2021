/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *InstructionsTxtBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Preview;
    QPushButton *PlaySound;
    QPushButton *SubmitWorkBtn;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QStackedWidget *stackedWidget;
    QWidget *paint;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *VisGuide;
    QLineEdit *HapG;
    QCheckBox *OffG;
    QCheckBox *PartialG;
    QCheckBox *FullG;
    QSpacerItem *verticalSpacer_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ClearBtn;
    QPushButton *PrevTskBtn;
    QPushButton *NextTaskBtn;
    QPushButton *SaveTskBtn;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QPushButton *exitBtn;
    QButtonGroup *HapGuide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"\n"
"background:rgb(233, 185, 110);}"));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        InstructionsTxtBox = new QPlainTextEdit(centralwidget);
        InstructionsTxtBox->setObjectName(QString::fromUtf8("InstructionsTxtBox"));
        InstructionsTxtBox->setGeometry(QRect(240, 30, 1021, 91));
        InstructionsTxtBox->setReadOnly(true);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1434, 80, 161, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Preview = new QPushButton(verticalLayoutWidget_2);
        Preview->setObjectName(QString::fromUtf8("Preview"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Preview->sizePolicy().hasHeightForWidth());
        Preview->setSizePolicy(sizePolicy1);
        Preview->setStyleSheet(QString::fromUtf8("#Preview {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Preview:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_2->addWidget(Preview);

        PlaySound = new QPushButton(verticalLayoutWidget_2);
        PlaySound->setObjectName(QString::fromUtf8("PlaySound"));
        sizePolicy1.setHeightForWidth(PlaySound->sizePolicy().hasHeightForWidth());
        PlaySound->setSizePolicy(sizePolicy1);
        PlaySound->setStyleSheet(QString::fromUtf8("#PlaySound {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#PlaySound:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_2->addWidget(PlaySound);

        SubmitWorkBtn = new QPushButton(verticalLayoutWidget_2);
        SubmitWorkBtn->setObjectName(QString::fromUtf8("SubmitWorkBtn"));
        SubmitWorkBtn->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SubmitWorkBtn->sizePolicy().hasHeightForWidth());
        SubmitWorkBtn->setSizePolicy(sizePolicy2);
        SubmitWorkBtn->setMinimumSize(QSize(96, 0));
        SubmitWorkBtn->setStyleSheet(QString::fromUtf8("#SubmitWorkBtn {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#SubmitWorkBtn:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_2->addWidget(SubmitWorkBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(89, 150, 1321, 631));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1321, 631));
        stackedWidget->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget{\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"}"));
        paint = new QWidget();
        paint->setObjectName(QString::fromUtf8("paint"));
        stackedWidget->addWidget(paint);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1430, 360, 160, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        VisGuide = new QCheckBox(verticalLayoutWidget);
        VisGuide->setObjectName(QString::fromUtf8("VisGuide"));

        verticalLayout->addWidget(VisGuide);

        HapG = new QLineEdit(verticalLayoutWidget);
        HapG->setObjectName(QString::fromUtf8("HapG"));
        HapG->setStyleSheet(QString::fromUtf8("#HapG {\n"
"\n"
"background:rgb(233, 185, 110);}"));

        verticalLayout->addWidget(HapG);

        OffG = new QCheckBox(verticalLayoutWidget);
        HapGuide = new QButtonGroup(MainWindow);
        HapGuide->setObjectName(QString::fromUtf8("HapGuide"));
        HapGuide->addButton(OffG);
        OffG->setObjectName(QString::fromUtf8("OffG"));

        verticalLayout->addWidget(OffG);

        PartialG = new QCheckBox(verticalLayoutWidget);
        HapGuide->addButton(PartialG);
        PartialG->setObjectName(QString::fromUtf8("PartialG"));

        verticalLayout->addWidget(PartialG);

        FullG = new QCheckBox(verticalLayoutWidget);
        HapGuide->addButton(FullG);
        FullG->setObjectName(QString::fromUtf8("FullG"));

        verticalLayout->addWidget(FullG);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(84, 810, 1321, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ClearBtn = new QPushButton(horizontalLayoutWidget);
        ClearBtn->setObjectName(QString::fromUtf8("ClearBtn"));
        sizePolicy2.setHeightForWidth(ClearBtn->sizePolicy().hasHeightForWidth());
        ClearBtn->setSizePolicy(sizePolicy2);
        ClearBtn->setStyleSheet(QString::fromUtf8("#ClearBtn {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#ClearBtn:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        horizontalLayout->addWidget(ClearBtn);

        PrevTskBtn = new QPushButton(horizontalLayoutWidget);
        PrevTskBtn->setObjectName(QString::fromUtf8("PrevTskBtn"));
        sizePolicy2.setHeightForWidth(PrevTskBtn->sizePolicy().hasHeightForWidth());
        PrevTskBtn->setSizePolicy(sizePolicy2);
        PrevTskBtn->setStyleSheet(QString::fromUtf8("#PrevTskBtn {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#PrevTskBtn:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        horizontalLayout->addWidget(PrevTskBtn);

        NextTaskBtn = new QPushButton(horizontalLayoutWidget);
        NextTaskBtn->setObjectName(QString::fromUtf8("NextTaskBtn"));
        sizePolicy2.setHeightForWidth(NextTaskBtn->sizePolicy().hasHeightForWidth());
        NextTaskBtn->setSizePolicy(sizePolicy2);
        NextTaskBtn->setStyleSheet(QString::fromUtf8("#NextTaskBtn {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#NextTaskBtn:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        horizontalLayout->addWidget(NextTaskBtn);

        SaveTskBtn = new QPushButton(horizontalLayoutWidget);
        SaveTskBtn->setObjectName(QString::fromUtf8("SaveTskBtn"));
        sizePolicy2.setHeightForWidth(SaveTskBtn->sizePolicy().hasHeightForWidth());
        SaveTskBtn->setSizePolicy(sizePolicy2);
        SaveTskBtn->setStyleSheet(QString::fromUtf8("#SaveTskBtn {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#SaveTskBtn:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        horizontalLayout->addWidget(SaveTskBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(1460, 40, 89, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        InstructionsTxtBox->setPlainText(QApplication::translate("MainWindow", "Any instructions would appear here\n"
"", nullptr));
        Preview->setText(QApplication::translate("MainWindow", "Preview", nullptr));
        PlaySound->setText(QApplication::translate("MainWindow", "Play Sound", nullptr));
        SubmitWorkBtn->setText(QApplication::translate("MainWindow", "Submit Work", nullptr));
        VisGuide->setText(QApplication::translate("MainWindow", "Visual Guidance", nullptr));
        HapG->setText(QApplication::translate("MainWindow", "Haptic Guidance", nullptr));
        OffG->setText(QApplication::translate("MainWindow", "Off", nullptr));
        PartialG->setText(QApplication::translate("MainWindow", "Partial", nullptr));
        FullG->setText(QApplication::translate("MainWindow", "Full", nullptr));
        ClearBtn->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        PrevTskBtn->setText(QApplication::translate("MainWindow", "Previous Task", nullptr));
        NextTaskBtn->setText(QApplication::translate("MainWindow", "Next Task", nullptr));
        SaveTskBtn->setText(QApplication::translate("MainWindow", "Save", nullptr));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
