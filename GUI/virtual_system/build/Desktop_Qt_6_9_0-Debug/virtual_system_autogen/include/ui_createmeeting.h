/********************************************************************************
** Form generated from reading UI file 'createmeeting.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMEETING_H
#define UI_CREATEMEETING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateMeeting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *meeting_type;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;
    QLineEdit *description;
    QLabel *label_4;
    QDateTimeEdit *date_time;
    QLabel *label_5;
    QLineEdit *platform;
    QLabel *label_6;
    QLineEdit *capacity;
    QLabel *error;
    QHBoxLayout *buttonLayout;
    QPushButton *back;
    QPushButton *create;

    void setupUi(QWidget *CreateMeeting)
    {
        if (CreateMeeting->objectName().isEmpty())
            CreateMeeting->setObjectName("CreateMeeting");
        CreateMeeting->resize(800, 600);
        verticalLayout = new QVBoxLayout(CreateMeeting);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CreateMeeting);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        meeting_type = new QComboBox(CreateMeeting);
        meeting_type->addItem(QString());
        meeting_type->addItem(QString());
        meeting_type->addItem(QString());
        meeting_type->addItem(QString());
        meeting_type->setObjectName("meeting_type");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(meeting_type->sizePolicy().hasHeightForWidth());
        meeting_type->setSizePolicy(sizePolicy);
        meeting_type->setMinimumSize(QSize(200, 31));

        verticalLayout->addWidget(meeting_type);

        label_2 = new QLabel(CreateMeeting);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        name = new QLineEdit(CreateMeeting);
        name->setObjectName("name");
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(200, 31));

        verticalLayout->addWidget(name);

        label_3 = new QLabel(CreateMeeting);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        description = new QLineEdit(CreateMeeting);
        description->setObjectName("description");
        sizePolicy.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy);
        description->setMinimumSize(QSize(200, 61));

        verticalLayout->addWidget(description);

        label_4 = new QLabel(CreateMeeting);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        date_time = new QDateTimeEdit(CreateMeeting);
        date_time->setObjectName("date_time");
        sizePolicy.setHeightForWidth(date_time->sizePolicy().hasHeightForWidth());
        date_time->setSizePolicy(sizePolicy);
        date_time->setMinimumSize(QSize(200, 31));

        verticalLayout->addWidget(date_time);

        label_5 = new QLabel(CreateMeeting);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        platform = new QLineEdit(CreateMeeting);
        platform->setObjectName("platform");
        sizePolicy.setHeightForWidth(platform->sizePolicy().hasHeightForWidth());
        platform->setSizePolicy(sizePolicy);
        platform->setMinimumSize(QSize(200, 31));

        verticalLayout->addWidget(platform);

        label_6 = new QLabel(CreateMeeting);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        capacity = new QLineEdit(CreateMeeting);
        capacity->setObjectName("capacity");
        sizePolicy.setHeightForWidth(capacity->sizePolicy().hasHeightForWidth());
        capacity->setSizePolicy(sizePolicy);
        capacity->setMinimumSize(QSize(200, 31));

        verticalLayout->addWidget(capacity);

        error = new QLabel(CreateMeeting);
        error->setObjectName("error");
        error->setFont(font);
        error->setVisible(false);
        error->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(error);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        back = new QPushButton(CreateMeeting);
        back->setObjectName("back");
        back->setMinimumSize(QSize(112, 40));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 16px;\n"
"    padding: 8px 16px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));

        buttonLayout->addWidget(back);

        create = new QPushButton(CreateMeeting);
        create->setObjectName("create");
        create->setMinimumSize(QSize(112, 40));
        create->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 16px;\n"
"    padding: 8px 16px;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}"));

        buttonLayout->addWidget(create);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(CreateMeeting);

        QMetaObject::connectSlotsByName(CreateMeeting);
    } // setupUi

    void retranslateUi(QWidget *CreateMeeting)
    {
        CreateMeeting->setWindowTitle(QCoreApplication::translate("CreateMeeting", "Create Meeting", nullptr));
        label->setText(QCoreApplication::translate("CreateMeeting", "Meeting Type:", nullptr));
        meeting_type->setItemText(0, QCoreApplication::translate("CreateMeeting", "Select the type", nullptr));
        meeting_type->setItemText(1, QCoreApplication::translate("CreateMeeting", "Conference", nullptr));
        meeting_type->setItemText(2, QCoreApplication::translate("CreateMeeting", "Webinar", nullptr));
        meeting_type->setItemText(3, QCoreApplication::translate("CreateMeeting", "Workshop", nullptr));

        meeting_type->setPlaceholderText(QCoreApplication::translate("CreateMeeting", "Select the type", nullptr));
        label_2->setText(QCoreApplication::translate("CreateMeeting", "Event Name:", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("CreateMeeting", "Enter event name", nullptr));
        label_3->setText(QCoreApplication::translate("CreateMeeting", "Description:", nullptr));
        description->setPlaceholderText(QCoreApplication::translate("CreateMeeting", "Enter description", nullptr));
        label_4->setText(QCoreApplication::translate("CreateMeeting", "Date & Time:", nullptr));
        date_time->setDisplayFormat(QCoreApplication::translate("CreateMeeting", "yyyy-MM-dd hh:mm", nullptr));
        label_5->setText(QCoreApplication::translate("CreateMeeting", "Platform:", nullptr));
        platform->setPlaceholderText(QCoreApplication::translate("CreateMeeting", "Enter platform", nullptr));
        label_6->setText(QCoreApplication::translate("CreateMeeting", "Capacity:", nullptr));
        capacity->setPlaceholderText(QCoreApplication::translate("CreateMeeting", "Enter capacity", nullptr));
        error->setStyleSheet(QCoreApplication::translate("CreateMeeting", "color: red;", nullptr));
        error->setText(QString());
        back->setText(QCoreApplication::translate("CreateMeeting", "Back", nullptr));
        create->setText(QCoreApplication::translate("CreateMeeting", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateMeeting: public Ui_CreateMeeting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMEETING_H
