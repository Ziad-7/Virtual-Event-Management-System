#include "loginpage.h"
#include "events.h"
#include "./ui_loginpage.h"
#include "menu.h"
#include "signup.h"
#include <fstream>

using namespace std;
string current_user;


LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ui->hiddentext->hide();
}

LoginPage::~LoginPage()
{
    delete ui;
}




void LoginPage::on_loginButton_clicked()
{
    string username, password;
    username = ui->username_textbox->text().toStdString();
    password = ui->password_textbox->text().toStdString();

    ifstream users("/home/mhendy/qtProjects/virtual_system/loginDataBase.txt");
    if (!users.is_open()) {
        exit(0);
        return;
    }

    string fileUsername, filePassword;
    bool loginSuccess = false;

    while (users >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            loginSuccess = true;
            break;
        }
    }

    users.close();

    if (loginSuccess) {
        current_user = username;
        Menu *m = new Menu();  // Create menu window
        m->show();             // Show menu
        this->close();
    } else {
        ui->hiddentext->show();
    }
}



void LoginPage::on_registerButton_clicked()
{
    signup *su = new signup();  // Create menu window
    su->show();             // Show menu
    this->close();
}

