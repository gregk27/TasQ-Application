/********************************************************************************
** Form generated from reading UI file 'to_do.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TO_DO_H
#define UI_TO_DO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_To_Do
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextEdit *t1;
    QTextEdit *t2;
    QTextEdit *t3;
    QTextEdit *t4;
    QTextEdit *t5;
    QTextEdit *t6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *c1;
    QCheckBox *c2;
    QCheckBox *c3;
    QCheckBox *c4;
    QCheckBox *c5;
    QCheckBox *c6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *p1;
    QPushButton *p2;
    QPushButton *p3;
    QPushButton *p4;
    QPushButton *p5;
    QPushButton *p6;
    QMenuBar *menubar;
    QMenu *menuProfile;
    QMenu *menuSchedule;
    QMenu *menuAssignment;
    QMenu *menuTo_Do;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *To_Do)
    {
        if (To_Do->objectName().isEmpty())
            To_Do->setObjectName(QString::fromUtf8("To_Do"));
        To_Do->resize(692, 600);
        centralwidget = new QWidget(To_Do);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 60, 121, 61));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);
        t1 = new QTextEdit(centralwidget);
        t1->setObjectName(QString::fromUtf8("t1"));
        t1->setGeometry(QRect(170, 150, 281, 31));
        t2 = new QTextEdit(centralwidget);
        t2->setObjectName(QString::fromUtf8("t2"));
        t2->setGeometry(QRect(170, 200, 281, 31));
        t3 = new QTextEdit(centralwidget);
        t3->setObjectName(QString::fromUtf8("t3"));
        t3->setGeometry(QRect(170, 250, 281, 31));
        t4 = new QTextEdit(centralwidget);
        t4->setObjectName(QString::fromUtf8("t4"));
        t4->setGeometry(QRect(170, 300, 281, 31));
        t5 = new QTextEdit(centralwidget);
        t5->setObjectName(QString::fromUtf8("t5"));
        t5->setGeometry(QRect(170, 350, 281, 31));
        t6 = new QTextEdit(centralwidget);
        t6->setObjectName(QString::fromUtf8("t6"));
        t6->setGeometry(QRect(170, 400, 281, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 130, 31, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        c1 = new QCheckBox(layoutWidget);
        c1->setObjectName(QString::fromUtf8("c1"));

        verticalLayout->addWidget(c1);

        c2 = new QCheckBox(layoutWidget);
        c2->setObjectName(QString::fromUtf8("c2"));

        verticalLayout->addWidget(c2);

        c3 = new QCheckBox(layoutWidget);
        c3->setObjectName(QString::fromUtf8("c3"));

        verticalLayout->addWidget(c3);

        c4 = new QCheckBox(layoutWidget);
        c4->setObjectName(QString::fromUtf8("c4"));

        verticalLayout->addWidget(c4);

        c5 = new QCheckBox(layoutWidget);
        c5->setObjectName(QString::fromUtf8("c5"));

        verticalLayout->addWidget(c5);

        c6 = new QCheckBox(layoutWidget);
        c6->setObjectName(QString::fromUtf8("c6"));

        verticalLayout->addWidget(c6);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(470, 130, 84, 331));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        p1 = new QPushButton(layoutWidget1);
        p1->setObjectName(QString::fromUtf8("p1"));

        verticalLayout_2->addWidget(p1);

        p2 = new QPushButton(layoutWidget1);
        p2->setObjectName(QString::fromUtf8("p2"));

        verticalLayout_2->addWidget(p2);

        p3 = new QPushButton(layoutWidget1);
        p3->setObjectName(QString::fromUtf8("p3"));

        verticalLayout_2->addWidget(p3);

        p4 = new QPushButton(layoutWidget1);
        p4->setObjectName(QString::fromUtf8("p4"));

        verticalLayout_2->addWidget(p4);

        p5 = new QPushButton(layoutWidget1);
        p5->setObjectName(QString::fromUtf8("p5"));

        verticalLayout_2->addWidget(p5);

        p6 = new QPushButton(layoutWidget1);
        p6->setObjectName(QString::fromUtf8("p6"));

        verticalLayout_2->addWidget(p6);

        To_Do->setCentralWidget(centralwidget);
        menubar = new QMenuBar(To_Do);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 692, 20));
        menuProfile = new QMenu(menubar);
        menuProfile->setObjectName(QString::fromUtf8("menuProfile"));
        menuSchedule = new QMenu(menubar);
        menuSchedule->setObjectName(QString::fromUtf8("menuSchedule"));
        menuAssignment = new QMenu(menubar);
        menuAssignment->setObjectName(QString::fromUtf8("menuAssignment"));
        menuTo_Do = new QMenu(menubar);
        menuTo_Do->setObjectName(QString::fromUtf8("menuTo_Do"));
        To_Do->setMenuBar(menubar);
        statusbar = new QStatusBar(To_Do);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        To_Do->setStatusBar(statusbar);

        menubar->addAction(menuProfile->menuAction());
        menubar->addAction(menuSchedule->menuAction());
        menubar->addAction(menuAssignment->menuAction());
        menubar->addAction(menuTo_Do->menuAction());

        retranslateUi(To_Do);

        QMetaObject::connectSlotsByName(To_Do);
    } // setupUi

    void retranslateUi(QMainWindow *To_Do)
    {
        To_Do->setWindowTitle(QCoreApplication::translate("To_Do", "To_Do", nullptr));
        label->setText(QCoreApplication::translate("To_Do", "Event List", nullptr));
        c1->setText(QString());
        c2->setText(QString());
        c3->setText(QString());
        c4->setText(QString());
        c5->setText(QString());
        c6->setText(QString());
        p1->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        p2->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        p3->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        p4->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        p5->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        p6->setText(QCoreApplication::translate("To_Do", "Done", nullptr));
        menuProfile->setTitle(QCoreApplication::translate("To_Do", "Profile", nullptr));
        menuSchedule->setTitle(QCoreApplication::translate("To_Do", "Schedule", nullptr));
        menuAssignment->setTitle(QCoreApplication::translate("To_Do", "Assignment", nullptr));
        menuTo_Do->setTitle(QCoreApplication::translate("To_Do", "To-Do", nullptr));
    } // retranslateUi

};

namespace Ui {
    class To_Do: public Ui_To_Do {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TO_DO_H
