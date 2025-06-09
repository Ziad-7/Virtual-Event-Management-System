#include "feedback.h"
#include "ui_feedback.h"
#include "menu.h"
#include <QLabel>
#include "events.h"
#include <fstream>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>

using namespace  std;

Feedback::Feedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Feedback)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    m_eventsContainer = ui->scrollAreaWidgetContents;
    m_eventsLayout = ui->eventsLayout;
    m_eventsLayout->setAlignment(Qt::AlignTop);
    m_eventsLayout->setSpacing(30);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(m_eventsContainer);
}

Feedback::~Feedback()
{
    delete ui;
}

void Feedback::addEvent(const QString &name, const QString &desc, const QString &type,
                        const QString &date, const QString &time, const QString &platform,
                        const int &capacity)
{
    QWidget *eventWidget = new QWidget(m_eventsContainer);
    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Set a background color and padding for the event widget
    eventWidget->setStyleSheet("background-color: #ffffff; border: 2px solid #000000; border-radius: 8px; padding: 10px;");

    // Event details labels with HTML formatting for bold labels
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

    // Add labels to layout
    eventLayout->addWidget(nameLabel);
    eventLayout->addWidget(descLabel);
    eventLayout->addWidget(typeLabel);
    eventLayout->addWidget(dateLabel);
    eventLayout->addWidget(timeLabel);
    eventLayout->addWidget(platformLabel);
    eventLayout->addWidget(capacityLabel);

    bool showFeedbackInput = true;

    ifstream feedbackFile("/home/mhendy/qtProjects/virtual_system/feedback.txt");
    if (!feedbackFile.is_open()) { return; }
    string fileRegister, fileRegistersFeedback, current_user_feedback;
    string line, fileType, fileEventName, fileEventDate, fileEventTime;

    while (getline(feedbackFile, line)) {
        bool user_is_registered = false;
        stringstream ss(line);
        getline(ss, fileType, '|');
        if(fileType != type) continue;
        getline(ss, fileEventName, '|');
        getline(ss, fileEventDate, '|');
        getline(ss, fileEventTime, '|');
        while(getline(ss, fileRegister, '|')){
            getline(ss, fileRegistersFeedback, '|');
            if(fileRegister == current_user){
                user_is_registered = true;
                current_user_feedback = fileRegistersFeedback;
            }
        }
        if (name == fileEventName && date == fileEventDate && time == fileEventTime && type == fileType && user_is_registered){
            showFeedbackInput = false;
        }
    }

    if (showFeedbackInput) {
        // Create feedback input and submit button
        QHBoxLayout *feedbackLayout = new QHBoxLayout();

        QLineEdit *feedbackInput = new QLineEdit(eventWidget);
        feedbackInput->setPlaceholderText("Enter your feedback...");
        feedbackInput->setStyleSheet("font-size: 14px; padding: 5px;");

        QPushButton *submitButton = new QPushButton("Submit", eventWidget);
        submitButton->setStyleSheet("QPushButton {"
                                    "background-color: #4CAF50;"
                                    "border: none;"
                                    "color: white;"
                                    "padding: 8px 16px;"
                                    "text-align: center;"
                                    "text-decoration: none;"
                                    "font-size: 14px;"
                                    "margin: 4px 2px;"
                                    "border-radius: 4px;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: #45a049;"
                                    "}");

        feedbackLayout->addWidget(feedbackInput);
        feedbackLayout->addWidget(submitButton);

        // Status label for after submission
        QLabel *statusLabel = new QLabel(eventWidget);
        statusLabel->hide();
        statusLabel->setStyleSheet(labelStyle);

        connect(submitButton, &QPushButton::clicked, this, [=]() {
            if (!feedbackInput->text().isEmpty()) {
                string submitted_feedback = feedbackInput->text().toStdString();
                // Process the feedback
                ifstream inFile("/home/mhendy/qtProjects/virtual_system/feedback.txt");
                vector<string> updatedLines;
                string fileType, fileEventName, fileEventDate, fileEventTime;
                string line, feedbacks;

                while (getline(inFile, line)) {
                    stringstream ss(line);
                    getline(ss, fileType, '|');
                    getline(ss, fileEventName, '|');
                    getline(ss, fileEventDate, '|');
                    getline(ss, fileEventTime, '|');
                    getline(ss, feedbacks);
                    if (name == fileEventName && date == fileEventDate && time == fileEventTime && type == fileType) {
                        // Append new user and feedback to existing line
                        line += current_user + "|" + submitted_feedback + '|';
                    }
                    updatedLines.push_back(line);
                }
                inFile.close();

                // Write back to file
                ofstream outFile("/home/mhendy/qtProjects/virtual_system/feedback.txt");
                for (const string& l : updatedLines) {
                    outFile << l << endl;
                }
                outFile.close();
                // Hide the input and button
                feedbackInput->hide();
                submitButton->hide();

                // Show feedback
                statusLabel->setText("<b>Feedback:</b> " + QString(submitted_feedback.c_str()));
                statusLabel->show();
            }
        });

        eventLayout->addLayout(feedbackLayout);
        eventLayout->addWidget(statusLabel);
    } else {
        // Show read-only message with styling
        QLabel *feedbackLabel = new QLabel(eventWidget);
        feedbackLabel->setText("<b>Feedback:</b> " + QString(current_user_feedback.c_str()));
        feedbackLabel->setStyleSheet(labelStyle);
        eventLayout->addWidget(feedbackLabel);
    }

    // Add a separator using QFrame
    QFrame *separator = new QFrame(eventWidget);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    eventLayout->addWidget(separator);

    m_eventsLayout->addWidget(eventWidget);
}

void Feedback::on_back_button_clicked()
{
    Menu *m = new Menu();
    m->show();
    this->close();
}
