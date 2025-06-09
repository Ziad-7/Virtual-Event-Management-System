/********************************************************************************
** Form generated from reading UI file 'feedback.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACK_H
#define UI_FEEDBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Feedback
{
public:
    QVBoxLayout *mainLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *eventsLayout;
    QPushButton *back_button;

    void setupUi(QWidget *Feedback)
    {
        if (Feedback->objectName().isEmpty())
            Feedback->setObjectName("Feedback");
        Feedback->resize(800, 600);
        mainLayout = new QVBoxLayout(Feedback);
        mainLayout->setObjectName("mainLayout");
        scrollArea = new QScrollArea(Feedback);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 534));
        eventsLayout = new QVBoxLayout(scrollAreaWidgetContents);
        eventsLayout->setObjectName("eventsLayout");
        scrollArea->setWidget(scrollAreaWidgetContents);

        mainLayout->addWidget(scrollArea);

        back_button = new QPushButton(Feedback);
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


        retranslateUi(Feedback);

        QMetaObject::connectSlotsByName(Feedback);
    } // setupUi

    void retranslateUi(QWidget *Feedback)
    {
        back_button->setText(QCoreApplication::translate("Feedback", "Back", nullptr));
        (void)Feedback;
    } // retranslateUi

};

namespace Ui {
    class Feedback: public Ui_Feedback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACK_H
