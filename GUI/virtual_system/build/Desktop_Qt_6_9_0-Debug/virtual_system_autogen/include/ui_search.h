/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QLabel *label_2;
    QLineEdit *event_name;
    QPushButton *search;
    QPushButton *back_button;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(800, 600);
        label_2 = new QLabel(Search);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 46, 131, 20));
        event_name = new QLineEdit(Search);
        event_name->setObjectName("event_name");
        event_name->setGeometry(QRect(170, 40, 221, 31));
        search = new QPushButton(Search);
        search->setObjectName("search");
        search->setGeometry(QRect(430, 40, 101, 31));
        search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));
        back_button = new QPushButton(Search);
        back_button->setObjectName("back_button");
        back_button->setGeometry(QRect(590, 40, 96, 31));
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
"}"));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Search", "Enter event name:", nullptr));
        event_name->setText(QString());
        event_name->setPlaceholderText(QCoreApplication::translate("Search", "name", nullptr));
        search->setText(QCoreApplication::translate("Search", "Search", nullptr));
        back_button->setText(QCoreApplication::translate("Search", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
