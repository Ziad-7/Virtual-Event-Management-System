/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *eventsLayout;
    QPushButton *back_button;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(800, 600);
        mainLayout = new QVBoxLayout(Register);
        mainLayout->setObjectName("mainLayout");
        scrollArea = new QScrollArea(Register);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 534));
        eventsLayout = new QVBoxLayout(scrollAreaWidgetContents);
        eventsLayout->setObjectName("eventsLayout");
        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);

        back_button = new QPushButton(Register);
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


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        back_button->setText(QCoreApplication::translate("Register", "Back", nullptr));
        (void)Register;
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
