/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QSpacerItem *verticalSpacerTop;
    QLineEdit *usernametb;
    QLineEdit *password_tb;
    QLabel *hiddentext;
    QPushButton *singupButton;
    QPushButton *back;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(800, 600);
        signup->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f5f5f5;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        verticalLayout = new QVBoxLayout(signup);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        headerLabel = new QLabel(signup);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    padding-bottom: 10px;\n"
"}"));
        headerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(headerLabel);

        verticalSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacerTop);

        usernametb = new QLineEdit(signup);
        usernametb->setObjectName("usernametb");
        usernametb->setMinimumSize(QSize(300, 40));
        usernametb->setMaximumSize(QSize(400, 40));
        usernametb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 8px 12px;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #4CAF50;\n"
"    outline: none;\n"
"}"));

        verticalLayout->addWidget(usernametb, 0, Qt::AlignHCenter);

        password_tb = new QLineEdit(signup);
        password_tb->setObjectName("password_tb");
        password_tb->setMinimumSize(QSize(300, 40));
        password_tb->setMaximumSize(QSize(400, 40));
        password_tb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    padding: 8px 12px;\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    background-color: white;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #4CAF50;\n"
"    outline: none;\n"
"}"));
        password_tb->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password_tb, 0, Qt::AlignHCenter);

        hiddentext = new QLabel(signup);
        hiddentext->setObjectName("hiddentext");
        hiddentext->setMinimumSize(QSize(300, 20));
        hiddentext->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #e53935;\n"
"    font-size: 13px;\n"
"    padding: 5px 0;\n"
"}"));
        hiddentext->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(hiddentext, 0, Qt::AlignHCenter);

        singupButton = new QPushButton(signup);
        singupButton->setObjectName("singupButton");
        singupButton->setMinimumSize(QSize(300, 45));
        singupButton->setMaximumSize(QSize(400, 45));
        singupButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #43A047;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;\n"
"}"));
        singupButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout->addWidget(singupButton, 0, Qt::AlignHCenter);

        back = new QPushButton(signup);
        back->setObjectName("back");
        back->setMinimumSize(QSize(300, 35));
        back->setMaximumSize(QSize(400, 35));
        back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        back->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout->addWidget(back, 0, Qt::AlignHCenter);

        verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacerBottom);


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Create Account", nullptr));
        headerLabel->setText(QCoreApplication::translate("signup", "Create Your Account", nullptr));
        usernametb->setPlaceholderText(QCoreApplication::translate("signup", "Enter your username", nullptr));
        password_tb->setPlaceholderText(QCoreApplication::translate("signup", "Enter your password", nullptr));
        hiddentext->setText(QCoreApplication::translate("signup", "Username already taken!", nullptr));
        singupButton->setText(QCoreApplication::translate("signup", "Create Account", nullptr));
        back->setText(QCoreApplication::translate("signup", "Back to Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
