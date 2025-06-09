#include "signup.h"
#include "ui_signup.h"
#include "loginpage.h"
#include <fstream>
#include <unordered_set>

using namespace std;


signup::signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->hiddentext->hide();
}

signup::~signup()
{
    delete ui;
}

void signup::on_singupButton_clicked()
{

    if(ui->usernametb->text().isEmpty() || ui->password_tb->text().isEmpty()){
        return;
    }
    unordered_set<string> usernames;
    string userName, dummy;

    // First open for reading only
    ifstream inFile("/home/mhendy/qtProjects/virtual_system/loginDataBase.txt");
    if (inFile.is_open()) {
        while (inFile >> userName >> dummy) {
            usernames.insert(userName);
        }
        inFile.close();
    }

    string username, password;
    username = ui->usernametb->text().toStdString();
    password = ui->password_tb->text().toStdString();


    if (usernames.count(username)) {
        ui->hiddentext->show();
    } else {
        // Then open for appending
        ofstream outFile("/home/mhendy/qtProjects/virtual_system/loginDataBase.txt", ios::app);
        if (outFile.is_open()) {
            outFile << username << " " << password << "\n";
            outFile.close();
            usernames.insert(username);

            LoginPage *lp = new LoginPage();  // Create login window
            lp->show();             // Show login
            this->close();
        }
    }
}


void signup::on_back_clicked()
{
    LoginPage *lp = new LoginPage();  // Create login window
    lp->show();             // Show login
    this->close();
}

