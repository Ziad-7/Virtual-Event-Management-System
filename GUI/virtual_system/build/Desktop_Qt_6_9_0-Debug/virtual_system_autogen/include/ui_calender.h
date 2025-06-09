/********************************************************************************
** Form generated from reading UI file 'calender.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDER_H
#define UI_CALENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calender
{
public:
    QVBoxLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *eventsLayout;
    QPushButton *back_button;

    void setupUi(QWidget *Calender)
    {
        if (Calender->objectName().isEmpty())
            Calender->setObjectName("Calender");
        Calender->resize(800, 600);
        mainLayout = new QVBoxLayout(Calender);
        mainLayout->setObjectName("mainLayout");
        scrollArea = new QScrollArea(Calender);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 534));
        eventsLayout = new QVBoxLayout(scrollAreaWidgetContents);
        eventsLayout->setObjectName("eventsLayout");
        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);

        back_button = new QPushButton(Calender);
        back_button->setObjectName("back_button");
        back_button->setMinimumSize(QSize(96, 40));
        back_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px; /* Ample space */\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"    min-width: 80px; /* Ensures text fits */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        mainLayout->addWidget(back_button);


        retranslateUi(Calender);

        QMetaObject::connectSlotsByName(Calender);
    } // setupUi

    void retranslateUi(QWidget *Calender)
    {
        back_button->setText(QCoreApplication::translate("Calender", "Back", nullptr));
        (void)Calender;
    } // retranslateUi

};

namespace Ui {
    class Calender: public Ui_Calender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDER_H
