#include "register.h"
#include "ui_register.h"
#include "menu.h"
#include "events.h"
#include <fstream>
#include <vector>
#include <set>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>
#include <sstream>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    // Set fixed window size
    this->setFixedSize(800, 600);

    // Initialize container and layouts
    m_eventsContainer = ui->scrollAreaWidgetContents;
    m_eventsLayout = ui->eventsLayout;

    // Configure layout
    m_eventsLayout->setAlignment(Qt::AlignTop);
    m_eventsLayout->setSpacing(10);

    // Configure scroll area
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(m_eventsContainer);
}

Register::~Register()
{
    delete ui;
}

void Register::addEvent(const QString &name, const QString &desc, const QString &type,
                        const QString &date, const QString &time, const QString &platform,
                        const int &capacity)
{
    QWidget *eventWidget = new QWidget(m_eventsContainer);
    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Set a background color and padding for the event widget
    eventWidget->setStyleSheet("background-color: #ffffff; border: 2px solid #000000; border-radius: 8px; padding: 10px;");

    // Create event details labels with bold formatting for constant strings
    QLabel *nameLabel = new QLabel("<b>Event:</b> " + name, eventWidget);
    QLabel *descLabel = new QLabel("<b>Description:</b> " + desc, eventWidget);
    QLabel *typeLabel = new QLabel("<b>Type:</b> " + type, eventWidget);
    QLabel *dateLabel = new QLabel("<b>Date:</b> " + date, eventWidget);
    QLabel *timeLabel = new QLabel("<b>Time:</b> " + time, eventWidget);
    QLabel *platformLabel = new QLabel("<b>Platform:</b> " + platform, eventWidget);
    QLabel *capacityLabel = new QLabel("<b>Capacity:</b> " + QString::number(capacity), eventWidget);

    // Customize label styles
    QString labelStyle = "font-size: 16px; color: #333;";
    nameLabel->setStyleSheet(labelStyle);
    descLabel->setStyleSheet(labelStyle);
    typeLabel->setStyleSheet(labelStyle);
    dateLabel->setStyleSheet(labelStyle);
    timeLabel->setStyleSheet(labelStyle);
    platformLabel->setStyleSheet(labelStyle);
    capacityLabel->setStyleSheet(labelStyle);

    // Add labels to the event layout
    eventLayout->addWidget(nameLabel);
    eventLayout->addWidget(descLabel);
    eventLayout->addWidget(typeLabel);
    eventLayout->addWidget(dateLabel);
    eventLayout->addWidget(timeLabel);
    eventLayout->addWidget(platformLabel);
    eventLayout->addWidget(capacityLabel);

    // Create Register button and Registered label
    QPushButton *registerButton = new QPushButton("Register", eventWidget);
    registerButton->setObjectName(name);

    // Apply the same green button styling
    registerButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50;"  // Green color
        "   color: white;"               // White text
        "   border: none;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   font-size: 14px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"  // Darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #3d8b40;"  // Even darker when pressed
        "}"
        );

    QLabel *registeredLabel = new QLabel("Registered", eventWidget);
    registeredLabel->setStyleSheet("color: green; font-weight: bold;");
    registeredLabel->setAlignment(Qt::AlignCenter);
    registeredLabel->hide();  // Initially hidden

    // Horizontal layout for button and label at the same spot
    QHBoxLayout *regLayout = new QHBoxLayout();
    regLayout->addWidget(registerButton);
    regLayout->addWidget(registeredLabel);
    eventLayout->addLayout(regLayout);

    // Connect the button to hide itself and show the label
    connect(registerButton, &QPushButton::clicked, this, [=, &current_user]() {
        registerButton->hide();
        registeredLabel->show();

        int number_of_attendees;
        set<string> registrars;
        string line, fileEventName, fileEventDate, fileEventTime, fileNumberAttendees, fileRegister;
        string fileType, fileUsername, fileDescription, filePlatform, fileCapacity;
        vector<string> lines;
        int targetLine = -1, index = 0;

        fstream inFile("/home/mhendy/qtProjects/virtual_system/events.txt", ios::in);
        while (getline(inFile, line)) {
            lines.push_back(line);
            stringstream ss(line);
            getline(ss, fileType, '|');        // type
            getline(ss, fileUsername, '|');    // username
            getline(ss, fileEventName, '|');   // event name
            getline(ss, fileDescription, '|'); // description
            getline(ss, fileEventDate, '|');   // date
            getline(ss, fileEventTime, '|');   // time

            if (name == fileEventName && date == fileEventDate && time == fileEventTime && type == fileType) {
                targetLine = index;
                getline(ss, filePlatform, '|'); // platform
                getline(ss, fileCapacity, '|'); // capacity
                getline(ss, fileNumberAttendees, '|'); // number of attendees
                try {
                    number_of_attendees = stoi(fileNumberAttendees);
                    number_of_attendees++;
                } catch (const invalid_argument& e) {
                    number_of_attendees = 0;
                }
                while (getline(ss, fileRegister, '|')) {
                    registrars.insert(fileRegister);
                }
            }
            index++;
        }
        inFile.close();

        if (targetLine == -1) return; // Event not found

        // Add the current user to the registrars set
        registrars.insert(current_user);

        // Parse and update fixed fields
        stringstream ss(lines[targetLine]);
        vector<string> fields;
        string field;
        for (int i = 0; i < 9; ++i) {
            getline(ss, field, '|');
            fields.push_back(field);
        }

        // Update number of attendees
        fields[8] = to_string(number_of_attendees);

        // Rebuild the updated line
        string newLine;
        for (int i = 0; i < 9; ++i) {
            newLine += fields[i] + "|";
        }

        for (const string &registrar : registrars) {
            newLine += registrar + "|";
        }

        lines[targetLine] = newLine;

        // Write all lines back to the file
        ofstream outFile("/home/mhendy/qtProjects/virtual_system/events.txt", ios::trunc);
        for (const string& l : lines) {
            outFile << l << endl;
        }
        outFile.close();
    });

    // Add a separator using QFrame
    QFrame *separator = new QFrame(eventWidget);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    eventLayout->addWidget(separator);

    m_eventsLayout->setSpacing(30);
    // Add the entire event widget to the scroll layout
    m_eventsLayout->addWidget(eventWidget);
}

void Register::on_back_button_clicked()
{
    Menu *m = new Menu();
    m->show();
    this->close();
}
