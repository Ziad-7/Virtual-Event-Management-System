#include "createmeeting.h"
#include "ui_createmeeting.h"
#include "menu.h"
#include "events.h"

using namespace std;

CreateMeeting::CreateMeeting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateMeeting)
{
    ui->setupUi(this);
    ui->error->hide();
}

CreateMeeting::~CreateMeeting()
{
    delete ui;
}

void CreateMeeting::on_back_clicked()
{

    Menu *m = new Menu();  // Create menu window
    m->show();             // Show menu
    this->close();
}


void CreateMeeting::on_create_clicked()
{
    if(ui->meeting_type->currentIndex() == 0 || ui->name->text().isEmpty() || ui->description->text().isEmpty() ||
        ui->platform->text().isEmpty() || ui->capacity->text().isEmpty()){
        ui->error->setText("Please fill the missing fields.");
        ui->error->show();
        return;
    }

    bool is_int;
    QString capacity_check = ui->capacity->text().trimmed(); // Get the input and trim whitespace
    int check = capacity_check.toInt(&is_int); // Attempt to convert to int
    if (is_int) {
        // The input is a valid integer, continue
    } else {
        // The input is not a valid integer
        ui->error->setText("Please enter a valid integer for capacity.");
        ui->error->show();
        return;
    }


    string name, description, platform;
    int capacity, number_of_attendees = 1;
    string selectedType = ui->meeting_type->currentText().toStdString();
    name = ui->name->text().toStdString();
    description = ui->description->text().toStdString();
    platform = ui->platform->text().toStdString();
    capacity = ui->capacity->text().toInt();


    QDate qdate = ui->date_time->date();
    QTime qtime = ui->date_time->time();

    string date = qdate.toString("yyyy-MM-dd").toStdString();
    string time = qtime.toString("HH:mm").toStdString();

    string line, fileEventName, fileEventDate, fileEventTime, fileNumberAttendees, fileRegisters;
    string fileType, fileUsername, fileDescription, filePlatform, fileCapacity;
    ifstream checkFile("/home/mhendy/qtProjects/virtual_system/events.txt");
    if (!checkFile.is_open()) {
        exit(0);
        return;
    }


    while(getline(checkFile, line)){

        stringstream ss(line);
        getline(ss, fileType, '|');
        getline(ss, fileUsername, '|');
        getline(ss, fileEventName, '|');
        getline(ss, fileDescription, '|');
        getline(ss, fileEventDate, '|');
        getline(ss, fileEventTime, '|');
        getline(ss, filePlatform, '|');
        getline(ss, fileCapacity, '|');
        getline(ss, fileNumberAttendees, '|');
        int capacity = stoi(fileCapacity);
        getline(ss, fileRegisters);
        if(fileType == selectedType && fileEventName == name && fileEventDate == date && fileEventTime == time){
            ui->error->setText("This event already exists.");
            ui->error->show();
            return;
        }

    }
    checkFile.close();


    ofstream file("/home/mhendy/qtProjects/virtual_system/events.txt", ios::app); // append mode
    if (!file.is_open()) {
        cout << "Error opening events file!" << endl;
        return;
    }
    file << selectedType << '|'
         << current_user << "|"
         << name << "|"
         << description << "|"
         << date << "|"
         << time << "|"
         << platform << "|"
         << capacity << "|"
         << number_of_attendees <<"|"
         << endl;
    file.close();


    ofstream feedbackFile("/home/mhendy/qtProjects/virtual_system/feedback.txt", ios::app); // append mode
    if (!feedbackFile.is_open()) {
        cout << "Error opening feedback file!" << endl;
        return;
    }
    feedbackFile << selectedType << '|'
         << name << "|"
         << date << "|"
         << time << "|"
         << endl;
    feedbackFile.close();

    Menu *m = new Menu();  // Create menu window
    m->show();             // Show menu
    this->close();
}

