/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QSpacerItem *verticalSpacerTop;
    QLineEdit *username_textbox;
    QLineEdit *password_textbox;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *hiddentext;
    QSpacerItem *verticalSpacerBottom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(800, 600);
        LoginPage->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        centralwidget = new QWidget(LoginPage);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        headerLabel = new QLabel(centralwidget);
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

        username_textbox = new QLineEdit(centralwidget);
        username_textbox->setObjectName("username_textbox");
        username_textbox->setMinimumSize(QSize(300, 40));
        username_textbox->setMaximumSize(QSize(400, 40));
        username_textbox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        verticalLayout->addWidget(username_textbox, 0, Qt::AlignHCenter);

        password_textbox = new QLineEdit(centralwidget);
        password_textbox->setObjectName("password_textbox");
        password_textbox->setMinimumSize(QSize(300, 40));
        password_textbox->setMaximumSize(QSize(400, 40));
        password_textbox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        password_textbox->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password_textbox, 0, Qt::AlignHCenter);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setMinimumSize(QSize(300, 45));
        loginButton->setMaximumSize(QSize(400, 45));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        loginButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout->addWidget(loginButton, 0, Qt::AlignHCenter);

        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setMinimumSize(QSize(300, 30));
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #4CAF50;\n"
"    background: transparent;\n"
"    border: none;\n"
"    font-size: 14px;\n"
"    text-decoration: underline;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #45a049;\n"
"}\n"
"QPushButton:pressed {\n"
"    color: #3d8b40;\n"
"}"));
        registerButton->setFlat(true);
        registerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        verticalLayout->addWidget(registerButton, 0, Qt::AlignHCenter);

        hiddentext = new QLabel(centralwidget);
        hiddentext->setObjectName("hiddentext");
        hiddentext->setMinimumSize(QSize(300, 20));
        hiddentext->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #e53935;\n"
"    font-size: 13px;\n"
"    padding: 5px 0;\n"
"}"));

        verticalLayout->addWidget(hiddentext, 0, Qt::AlignCenter);

        verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacerBottom);

        LoginPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LoginPage->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginPage);
        statusbar->setObjectName("statusbar");
        LoginPage->setStatusBar(statusbar);

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Login", nullptr));
        headerLabel->setText(QCoreApplication::translate("LoginPage", "Login Page", nullptr));
        username_textbox->setPlaceholderText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        password_textbox->setPlaceholderText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginPage", "Create new account", nullptr));
        hiddentext->setText(QCoreApplication::translate("LoginPage", "Invalid username or password!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
