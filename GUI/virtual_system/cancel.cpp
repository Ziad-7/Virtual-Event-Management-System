#include "cancel.h"
#include "ui_cancel.h"
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

using namespace std;

Cancel::Cancel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cancel)
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

Cancel::~Cancel()
{
    delete ui;
}

void Cancel::addEvent(const QString &name, const QString &desc, const QString &type,
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

    // Create Cancel button and Cancelled label
    QPushButton *cancelButton = new QPushButton("Cancel", eventWidget);
    cancelButton->setObjectName(name);

    cancelButton->setStyleSheet(
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

    QLabel *cancelledLabel = new QLabel("Cancelled", eventWidget);
    cancelledLabel->setStyleSheet("color: red; font-weight: bold;");
    cancelledLabel->setAlignment(Qt::AlignCenter);
    cancelledLabel->hide();  // Initially hidden

    // Horizontal layout for button and label at the same spot
    QHBoxLayout *cancelLayout = new QHBoxLayout();
    cancelLayout->addWidget(cancelButton);
    cancelLayout->addWidget(cancelledLabel);
    eventLayout->addLayout(cancelLayout);

    // Connect the button to hide itself and show the label
    connect(cancelButton, &QPushButton::clicked, this, [=]() {
        cancelButton->hide();
        cancelledLabel->show();

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
            if (name == QString::fromStdString(fileEventName)
                && date == QString::fromStdString(fileEventDate)
                && time == QString::fromStdString(fileEventTime)
                && type == QString::fromStdString(fileType)) {
                continue;
            }
            updatedLines.push_back(line);
        }
        file.close();

        ofstream outFile("/home/mhendy/qtProjects/virtual_system/events.txt", ios::trunc);
        if (!outFile.is_open()) {return; }
        for (const string& l : updatedLines)
            outFile << l << "\n";
        outFile.close();

        // Feedback update
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
            if (name == QString::fromStdString(fileEventName)
                && date == QString::fromStdString(fileEventDate)
                && time == QString::fromStdString(fileEventTime)
                && type == QString::fromStdString(fileType)) {
                continue;
            }
            updatedLinesFeedback.push_back(line);
        }
        feedbackFile.close();

        ofstream outFeedbackFile("/home/mhendy/qtProjects/virtual_system/feedback.txt", ios::trunc);
        if (!outFeedbackFile.is_open()) {return; }
        for (const string& l : updatedLinesFeedback)
            outFeedbackFile << l << "\n";
        outFeedbackFile.close();
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

void Cancel::on_back_button_clicked()
{
    Menu *m = new Menu();
    m->show();
    this->close();
}
