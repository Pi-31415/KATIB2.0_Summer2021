/********************************************************************************
** Form generated from reading UI file 'teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_H
#define UI_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teacher
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QPushButton *Previous;
    QPushButton *Next;
    QFrame *frame_2;
    QStackedWidget *Painting_area_2;
    QWidget *page;
    QLabel *label_3;
    QTextEdit *Comment_box;
    QPushButton *Save_feedback;
    QLabel *label_5;
    QLabel *label_6;
    QListWidget *graded_students_list;
    QListWidget *Completed_tasks_list;
    QDoubleSpinBox *Grade;
    QWidget *tab_2;
    QFrame *frame;
    QStackedWidget *Painting_area;
    QWidget *page_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *Assign;
    QPushButton *Drop;
    QPushButton *Assign_all;
    QSpacerItem *verticalSpacer;
    QPushButton *Delete;
    QListWidget *Task_list;
    QLabel *label;
    QListWidget *Student_list;
    QListWidget *Assigned_tasks_list;
    QLabel *label_2;
    QLabel *label_7;
    QWidget *tab_3;
    QFrame *frame_3;
    QStackedWidget *Painting_area_3;
    QWidget *page_4;
    QLabel *label_18;
    QLineEdit *Letter_name;
    QTextEdit *Description;
    QLabel *label_19;
    QPushButton *Save;
    QPushButton *Clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Teacher)
    {
        if (Teacher->objectName().isEmpty())
            Teacher->setObjectName(QString::fromUtf8("Teacher"));
        Teacher->resize(1300, 900);
        centralwidget = new QWidget(Teacher);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("#tabWidget {\n"
"\n"
"background:rgb(233, 185, 110);}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setStyleSheet(QString::fromUtf8("#tab {\n"
"\n"
"background:rgb(233, 185, 110);}"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(960, 560, 101, 16));
        Previous = new QPushButton(tab);
        Previous->setObjectName(QString::fromUtf8("Previous"));
        Previous->setGeometry(QRect(730, 650, 30, 30));
        Next = new QPushButton(tab);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(770, 650, 30, 30));
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(70, 80, 650, 600));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Painting_area_2 = new QStackedWidget(frame_2);
        Painting_area_2->setObjectName(QString::fromUtf8("Painting_area_2"));
        Painting_area_2->setGeometry(QRect(0, 0, 650, 600));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        Painting_area_2->addWidget(page);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(880, 400, 111, 16));
        Comment_box = new QTextEdit(tab);
        Comment_box->setObjectName(QString::fromUtf8("Comment_box"));
        Comment_box->setGeometry(QRect(890, 420, 341, 131));
        Save_feedback = new QPushButton(tab);
        Save_feedback->setObjectName(QString::fromUtf8("Save_feedback"));
        Save_feedback->setGeometry(QRect(1150, 580, 93, 28));
        Save_feedback->setStyleSheet(QString::fromUtf8("#Save_feedback {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Save_feedback:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(880, 80, 81, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1060, 80, 121, 16));
        graded_students_list = new QListWidget(tab);
        graded_students_list->setObjectName(QString::fromUtf8("graded_students_list"));
        graded_students_list->setGeometry(QRect(880, 110, 151, 91));
        Completed_tasks_list = new QListWidget(tab);
        Completed_tasks_list->setObjectName(QString::fromUtf8("Completed_tasks_list"));
        Completed_tasks_list->setGeometry(QRect(1060, 110, 161, 271));
        Grade = new QDoubleSpinBox(tab);
        Grade->setObjectName(QString::fromUtf8("Grade"));
        Grade->setGeometry(QRect(960, 580, 62, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("#tab_2{\n"
"\n"
"background:rgb(233, 185, 110);}"));
        frame = new QFrame(tab_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 80, 550, 500));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Painting_area = new QStackedWidget(frame);
        Painting_area->setObjectName(QString::fromUtf8("Painting_area"));
        Painting_area->setGeometry(QRect(0, 0, 550, 500));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        Painting_area->addWidget(page_3);
        verticalLayoutWidget_3 = new QWidget(tab_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(820, 80, 101, 301));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Assign = new QPushButton(verticalLayoutWidget_3);
        Assign->setObjectName(QString::fromUtf8("Assign"));
        Assign->setStyleSheet(QString::fromUtf8("#Assign {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Assign:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_3->addWidget(Assign);

        Drop = new QPushButton(verticalLayoutWidget_3);
        Drop->setObjectName(QString::fromUtf8("Drop"));
        Drop->setStyleSheet(QString::fromUtf8("#Drop {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Drop:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_3->addWidget(Drop);

        Assign_all = new QPushButton(verticalLayoutWidget_3);
        Assign_all->setObjectName(QString::fromUtf8("Assign_all"));
        Assign_all->setStyleSheet(QString::fromUtf8("#Assign_all {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Assign_all:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_3->addWidget(Assign_all);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        Delete = new QPushButton(verticalLayoutWidget_3);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setStyleSheet(QString::fromUtf8("#Delete {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Delete:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));

        verticalLayout_3->addWidget(Delete);

        Task_list = new QListWidget(tab_2);
        Task_list->setObjectName(QString::fromUtf8("Task_list"));
        Task_list->setGeometry(QRect(630, 80, 171, 301));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(630, 60, 91, 16));
        Student_list = new QListWidget(tab_2);
        Student_list->setObjectName(QString::fromUtf8("Student_list"));
        Student_list->setGeometry(QRect(970, 80, 171, 291));
        Assigned_tasks_list = new QListWidget(tab_2);
        Assigned_tasks_list->setObjectName(QString::fromUtf8("Assigned_tasks_list"));
        Assigned_tasks_list->setGeometry(QRect(970, 440, 171, 291));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 60, 71, 16));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(970, 420, 111, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("#tab_3 {\n"
"\n"
"background:rgb(233, 185, 110);}"));
        frame_3 = new QFrame(tab_3);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(70, 80, 800, 600));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
"border-style: solid;\n"
"border-width: 1px;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        Painting_area_3 = new QStackedWidget(frame_3);
        Painting_area_3->setObjectName(QString::fromUtf8("Painting_area_3"));
        Painting_area_3->setGeometry(QRect(0, 0, 800, 600));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        Painting_area_3->addWidget(page_4);
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(910, 130, 101, 16));
        Letter_name = new QLineEdit(tab_3);
        Letter_name->setObjectName(QString::fromUtf8("Letter_name"));
        Letter_name->setGeometry(QRect(910, 150, 261, 51));
        Description = new QTextEdit(tab_3);
        Description->setObjectName(QString::fromUtf8("Description"));
        Description->setGeometry(QRect(910, 250, 261, 201));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(910, 230, 81, 16));
        Save = new QPushButton(tab_3);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(1050, 490, 93, 24));
        Save->setStyleSheet(QString::fromUtf8("#Save {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Save:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));
        Clear = new QPushButton(tab_3);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(940, 490, 93, 24));
        Clear->setStyleSheet(QString::fromUtf8("#Clear {\n"
"background:rgb(52, 101, 164);\n"
"\n"
"}\n"
"\n"
"#Clear:hover{\n"
"background:rgb(114, 159, 207);\n"
"}"));
        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        Teacher->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Teacher);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 22));
        Teacher->setMenuBar(menubar);
        statusbar = new QStatusBar(Teacher);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Teacher->setStatusBar(statusbar);

        retranslateUi(Teacher);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Teacher);
    } // setupUi

    void retranslateUi(QMainWindow *Teacher)
    {
        Teacher->setWindowTitle(QApplication::translate("Teacher", "Teacher", nullptr));
        label_4->setText(QApplication::translate("Teacher", "Assign Grade", nullptr));
        Previous->setText(QApplication::translate("Teacher", "<", nullptr));
        Next->setText(QApplication::translate("Teacher", ">", nullptr));
        label_3->setText(QApplication::translate("Teacher", "Comment", nullptr));
        Save_feedback->setText(QApplication::translate("Teacher", "Save", nullptr));
        label_5->setText(QApplication::translate("Teacher", "Student", nullptr));
        label_6->setText(QApplication::translate("Teacher", "Tasks Completed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Teacher", "Tab 1", nullptr));
        Assign->setText(QApplication::translate("Teacher", "Assign >>", nullptr));
        Drop->setText(QApplication::translate("Teacher", "<< Drop", nullptr));
        Assign_all->setText(QApplication::translate("Teacher", "Assign to all", nullptr));
        Delete->setText(QApplication::translate("Teacher", "Delete Task", nullptr));
        label->setText(QApplication::translate("Teacher", "Tasks List", nullptr));
        label_2->setText(QApplication::translate("Teacher", "Students", nullptr));
        label_7->setText(QApplication::translate("Teacher", "Assigned Tasks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Teacher", "Tab 2", nullptr));
        label_18->setText(QApplication::translate("Teacher", "Letter Name:", nullptr));
        Letter_name->setText(QString());
        label_19->setText(QApplication::translate("Teacher", "Description", nullptr));
        Save->setText(QApplication::translate("Teacher", "Save Task", nullptr));
        Clear->setText(QApplication::translate("Teacher", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Teacher", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Teacher: public Ui_Teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
