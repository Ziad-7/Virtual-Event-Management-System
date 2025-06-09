#include "search.h"
#include "menu.h"
#include "ui_search.h"
#include "calender.h"
#include <fstream>
#include <sstream>

using namespace std;

Search::Search(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::on_back_button_clicked()
{
    Menu *m = new Menu();
    m->show();
    this->close();
}


void Search::on_search_clicked()
{
    Calender *cal = new Calender();
    string target_event = ui->event_name->text().toStdString();
    string line;
    string creator, name, desc, date, time, platform, capacityStr, type, attendees_number_str, registrar;
    ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!file.is_open()) {
        exit(0);
        return;
    }

    while(getline(file, line)){
        stringstream ss(line);
        getline(ss, type, '|');
        getline(ss, creator, '|');
        getline(ss, name, '|');
        if(name != target_event){continue;}
        getline(ss, desc, '|');
        getline(ss, date, '|');
        getline(ss, time, '|');
        getline(ss, platform, '|');
        getline(ss, capacityStr, '|');
        getline(ss, attendees_number_str, '|');
        int capacity = stoi(capacityStr);
        cal->addEvent(QString(name.c_str()), QString(desc.c_str()), QString(type.c_str()), QString(date.c_str())
                      , QString(time.c_str()), QString(platform.c_str()), capacity);
    }

    cal->show();
    this->close();
}

