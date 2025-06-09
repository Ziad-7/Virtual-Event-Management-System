#include "postpone.h"
#include "ui_postpone.h"
#include "menu.h"
#include "events.h"
#include <fstream>
#include <vector>
#include <set>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QTimeEdit>
#include <QDialogButtonBox>
#include <QFrame>
#include <QHBoxLayout>

using namespace std;

Postpone::Postpone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Postpone)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    m_eventsContainer = ui->scrollAreaWidgetContents;
    m_eventsLayout = ui->eventsLayout;
    m_eventsLayout->setAlignment(Qt::AlignTop);
    m_eventsLayout->setSpacing(10);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(m_eventsContainer);
}

Postpone::~Postpone()
{
    delete ui;
}

void Postpone::addEvent(const QString &name, const QString &desc, const QString &type,
                        const QString &date, const QString &time, const QString &platform,
                        const int &capacity)
{
    QWidget *eventWidget = new QWidget(m_eventsContainer);
    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Set consistent event card styling
    eventWidget->setStyleSheet("background-color: #ffffff; border: 2px solid #000000; border-radius: 8px; padding: 10px;");

    // Create event details labels with consistent styling
    QLabel *nameLabel = new QLabel("<b>Event:</b> " + name, eventWidget);
    QLabel *descLabel = new QLabel("<b>Description:</b> " + desc, eventWidget);
    QLabel *typeLabel = new QLabel("<b>Type:</b> " + type, eventWidget);
    QLabel *dateLabel = new QLabel("<b>Current Date:</b> " + date, eventWidget);
    QLabel *timeLabel = new QLabel("<b>Current Time:</b> " + time, eventWidget);
    QLabel *platformLabel = new QLabel("<b>Platform:</b> " + platform, eventWidget);
    QLabel *capacityLabel = new QLabel("<b>Capacity:</b> " + QString::number(capacity), eventWidget);

    // Apply consistent label styling
    QString labelStyle = "font-size: 16px; color: #333;";
    nameLabel->setStyleSheet(labelStyle);
    descLabel->setStyleSheet(labelStyle);
    typeLabel->setStyleSheet(labelStyle);
    dateLabel->setStyleSheet(labelStyle);
    timeLabel->setStyleSheet(labelStyle);
    platformLabel->setStyleSheet(labelStyle);
    capacityLabel->setStyleSheet(labelStyle);

    // Add labels to layout
    eventLayout->addWidget(nameLabel);
    eventLayout->addWidget(descLabel);
    eventLayout->addWidget(typeLabel);
    eventLayout->addWidget(dateLabel);
    eventLayout->addWidget(timeLabel);
    eventLayout->addWidget(platformLabel);
    eventLayout->addWidget(capacityLabel);

    // Create Postpone button with consistent styling
    QPushButton *postponeButton = new QPushButton("Postpone", eventWidget);
    postponeButton->setObjectName(name);
    postponeButton->setStyleSheet(
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

    QLabel *statusLabel = new QLabel(eventWidget);
    statusLabel->setStyleSheet("color: green; font-weight: bold;");
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->hide();

    // Create datetime controls with consistent styling
    QHBoxLayout *datetimeLayout = new QHBoxLayout();
    QDateTimeEdit *datetimeEdit = new QDateTimeEdit(eventWidget);
    datetimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm");
    datetimeEdit->setDateTime(QDateTime::currentDateTime());
    datetimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
    datetimeEdit->setStyleSheet(
        "QDateTimeEdit {"
        "   padding: 6px;"
        "   border: 1px solid #ccc;"
        "   border-radius: 4px;"
        "}"
        );
    datetimeEdit->hide();

    QPushButton *confirmButton = new QPushButton("Confirm", eventWidget);
    confirmButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #2196F3;"  // Blue color for confirm
        "   color: white;"
        "   border: none;"
        "   border-radius: 4px;"
        "   padding: 8px 16px;"
        "   font-size: 14px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #0b7dda;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #0a68b4;"
        "}"
        );
    confirmButton->hide();

    datetimeLayout->addWidget(datetimeEdit);
    datetimeLayout->addWidget(confirmButton);

    // Connect the postpone button
    connect(postponeButton, &QPushButton::clicked, this, [=]() {
        postponeButton->hide();
        datetimeEdit->show();
        confirmButton->show();
    });

    // Connect the confirm button
    connect(confirmButton, &QPushButton::clicked, this, [=]() {
        QString newDateTime = datetimeEdit->dateTime().toString("yyyy-MM-dd hh:mm");
        QStringList parts = newDateTime.split(" ");
        QString qNewDate = parts[0];
        QString qNewTime = parts[1];

        // Update the UI
        dateLabel->setText("<b>Current Date:</b> " + qNewDate);
        timeLabel->setText("<b>Current Time:</b> " + qNewTime);
        statusLabel->setText("Postponed to: " + newDateTime);
        statusLabel->show();

        datetimeEdit->hide();
        confirmButton->hide();
        postponeButton->show();

        string newDate = qNewDate.toStdString();
        string newTime = qNewTime.toStdString();

        // File handling
        ifstream file("/home/mhendy/qtProjects/virtual_system/events.txt");
        if (!file.is_open()) {return; }
        vector<string> updatedLines;
        string line, fileEventName, fileEventDate, fileEventTime, fileNumberAttendees, fileRegisters;
        string fileType, fileUsername, fileDescription, filePlatform, fileCapacity;

        while (getline(file, line)) {
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
            getline(ss, fileRegisters);
            if (name == fileEventName && date == fileEventDate && time == fileEventTime && type == fileType){
                string updatedLine;
                updatedLine = fileType + "|" + fileUsername + "|" + fileEventName + "|" + fileDescription + "|" +
                              newDate + "|" + newTime + "|" + filePlatform + "|" +
                              fileCapacity + "|" + fileNumberAttendees + "|" + fileRegisters;
                updatedLines.push_back(updatedLine);
            }else{
                string updatedLine;
                updatedLine = fileType + "|" + fileUsername + "|" + fileEventName + "|" + fileDescription + "|" +
                              fileEventDate + "|" + fileEventTime + "|" + filePlatform + "|" +
                              fileCapacity + "|" + fileNumberAttendees + "|" + fileRegisters;
                updatedLines.push_back(updatedLine);
            }
        }
        file.close();

        ofstream outFile("/home/mhendy/qtProjects/virtual_system/events.txt", ios::trunc);
        if (!outFile.is_open()) {return; }
        for (const string& l : updatedLines) {
            outFile << l << endl;
        }
        outFile.close();

        // Feedback file handling
        ifstream feedbackFile("/home/mhendy/qtProjects/virtual_system/feedback.txt");
        if (!feedbackFile.is_open()) {return; }
        vector<string> updatedLinesFeedback;
        string fileRegistersFeedback;

        while (getline(feedbackFile, line)) {
            stringstream ss(line);
            getline(ss, fileType, '|');
            getline(ss, fileEventName, '|');
            getline(ss, fileEventDate, '|');
            getline(ss, fileEventTime, '|');
            getline(ss, fileRegistersFeedback);
            if (name == fileEventName && date == fileEventDate && time == fileEventTime && type == fileType){
                string updatedLine;
                updatedLine = fileType + "|" + fileEventName + "|"  +
                              newDate + "|" + newTime + "|" + fileRegistersFeedback;
                updatedLinesFeedback.push_back(updatedLine);
            }else{
                string updatedLine;
                updatedLine = fileType + "|" + fileEventName +  "|" +
                              fileEventDate + "|" + fileEventTime + "|" + fileRegistersFeedback;
                updatedLinesFeedback.push_back(updatedLine);
            }
        }
        feedbackFile.close();

        ofstream outFileFeedback("/home/mhendy/qtProjects/virtual_system/feedback.txt", ios::trunc);
        if (!outFileFeedback.is_open()) {return; }
        for (const string& l : updatedLinesFeedback) {
            outFileFeedback << l << endl;
        }
        outFileFeedback.close();
    });

    eventLayout->addWidget(postponeButton);
    eventLayout->addLayout(datetimeLayout);
    eventLayout->addWidget(statusLabel);

    // Add separator using QFrame
    QFrame *separator = new QFrame(eventWidget);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    eventLayout->addWidget(separator);

    m_eventsLayout->setSpacing(30);
    m_eventsLayout->addWidget(eventWidget);
}

void Postpone::on_back_button_clicked()
{
    Menu *m = new Menu();
    m->show();
    this->close();
}
