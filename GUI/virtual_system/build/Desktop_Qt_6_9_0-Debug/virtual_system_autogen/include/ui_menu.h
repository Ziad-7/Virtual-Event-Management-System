/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QSpacerItem *verticalSpacerTop;
    QPushButton *create_meeting;
    QPushButton *register_meeting;
    QPushButton *cancel_meeting;
    QPushButton *postpone_meeting;
    QPushButton *show_events;
    QPushButton *search_for_event;
    QPushButton *feedback;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(800, 600);
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        headerLabel = new QLabel(Menu);
        headerLabel->setObjectName("headerLabel");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        headerLabel->setFont(font);
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignHCenter);

        verticalLayout->addWidget(headerLabel);

        verticalSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacerTop);

        create_meeting = new QPushButton(Menu);
        create_meeting->setObjectName("create_meeting");
        create_meeting->setMinimumSize(QSize(0, 50));
        create_meeting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(create_meeting);

        register_meeting = new QPushButton(Menu);
        register_meeting->setObjectName("register_meeting");
        register_meeting->setMinimumSize(QSize(0, 50));
        register_meeting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(register_meeting);

        cancel_meeting = new QPushButton(Menu);
        cancel_meeting->setObjectName("cancel_meeting");
        cancel_meeting->setMinimumSize(QSize(0, 50));
        cancel_meeting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(cancel_meeting);

        postpone_meeting = new QPushButton(Menu);
        postpone_meeting->setObjectName("postpone_meeting");
        postpone_meeting->setMinimumSize(QSize(0, 50));
        postpone_meeting->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(postpone_meeting);

        show_events = new QPushButton(Menu);
        show_events->setObjectName("show_events");
        show_events->setMinimumSize(QSize(0, 50));
        show_events->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(show_events);

        search_for_event = new QPushButton(Menu);
        search_for_event->setObjectName("search_for_event");
        search_for_event->setMinimumSize(QSize(0, 50));
        search_for_event->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(search_for_event);

        feedback = new QPushButton(Menu);
        feedback->setObjectName("feedback");
        feedback->setMinimumSize(QSize(0, 50));
        feedback->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px 8px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed { background-color: #3d8b40; }"));

        verticalLayout->addWidget(feedback);

        pushButton = new QPushButton(Menu);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #4CAF50;\n"
"    background: transparent;\n"
"    border: 1px solid #4CAF50;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(76, 175, 80, 0.1);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgba(76, 175, 80, 0.2);\n"
"}"));

        verticalLayout->addWidget(pushButton);

        verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacerBottom);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Meeting Scheduler", nullptr));
        headerLabel->setText(QCoreApplication::translate("Menu", "Meeting Scheduler Menu", nullptr));
        create_meeting->setText(QCoreApplication::translate("Menu", "Create Meeting", nullptr));
        register_meeting->setText(QCoreApplication::translate("Menu", "Register Meeting", nullptr));
        cancel_meeting->setText(QCoreApplication::translate("Menu", "Cancel Meeting", nullptr));
        postpone_meeting->setText(QCoreApplication::translate("Menu", "Postpone Meeting", nullptr));
        show_events->setText(QCoreApplication::translate("Menu", "Show Events", nullptr));
        search_for_event->setText(QCoreApplication::translate("Menu", "Search for Event", nullptr));
        feedback->setText(QCoreApplication::translate("Menu", "Feedback", nullptr));
        pushButton->setText(QCoreApplication::translate("Menu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
