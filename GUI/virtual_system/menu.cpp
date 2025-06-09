#include "menu.h"
#include "ui_menu.h"
#include "loginpage.h"
#include "createmeeting.h"
#include "calender.h"
#include "register.h"
#include "events.h"
#include "search.h"
#include "postpone.h"
#include "cancel.h"
#include "feedback.h"
#include <fstream>


using namespace std;

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    LoginPage *lp = new LoginPage();  // Create login window
    lp->show();             // Show login
    this->close();         // Close current window
}


void Menu::on_create_meeting_clicked()
{
    CreateMeeting *cm = new CreateMeeting();
    cm->show();
    this->close();
}


void Menu::on_show_events_clicked()
{
    Calender *cal = new Calender();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, fileRegister;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        bool user_registered = false;
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        getline(ss, name, '|');
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        while (getline(ss, fileRegister, '|')) {
            if(current_user == fileRegister){
                user_registered = true;
                break;  // No need to continue checking further registrars
            }
        }
        if(user_registered || (creator == current_user)){
            cal->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                          , QString(time.c_str()), QString(platform.c_str()), capacity);
        }
    }
    cal->show();
    this->close();
}


void Menu::on_register_meeting_clicked()
{

    Register *r = new Register();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, fileRegister;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        bool user_already_registered = false;
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        if (creator == current_user){continue;}
        getline(ss, name, '|');
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        int attendees_number = stoi(attendees_number_str);
        if(capacity <= attendees_number){continue;}
        while (getline(ss, fileRegister, '|')) {
            if(current_user == fileRegister){
                user_already_registered = true;
                break;  // No need to continue checking further registrars
            }
        }
        if (user_already_registered) continue;
        r->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                      , QString(time.c_str()), QString(platform.c_str()), capacity);
    }
    r->show();
    this->close();
}


void Menu::on_search_for_event_clicked()
{
    Search *s = new Search();
    s->show();
    this->close();
}


void Menu::on_cancel_meeting_clicked()
{
    Cancel *c = new Cancel();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, fileRegister;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        bool user_registered = false;
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        if(creator != current_user){continue;}
        getline(ss, name, '|');
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        while (getline(ss, fileRegister, '|')) {

        }
         c->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                          , QString(time.c_str()), QString(platform.c_str()), capacity);
    }
    c->show();
    this->close();
}


void Menu::on_postpone_meeting_clicked()
{
    Postpone *p = new Postpone();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, fileRegister;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        bool user_registered = false;
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        if(creator != current_user){continue;}
        getline(ss, name, '|');
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        while (getline(ss, fileRegister, '|')) {

        }
        p->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                    , QString(time.c_str()), QString(platform.c_str()), capacity);
    }
    p->show();
    this->close();
}


void Menu::on_feedback_clicked()
{
    Feedback *f = new Feedback();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, fileRegister;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        bool user_registered = false;
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        if (creator == current_user){continue;}
        getline(ss, name, '|');
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        while (getline(ss, fileRegister, '|')) {
            if(current_user == fileRegister){
                user_registered = true;
                break;  // No need to continue checking further registrars
            }
        }
        if (user_registered){
                f->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                , QString(time.c_str()), QString(platform.c_str()), capacity);
        }

    }
    f->show();
    this->close();

}

