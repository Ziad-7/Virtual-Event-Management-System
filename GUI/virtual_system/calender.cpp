#include "calender.h"
#include "ui_calender.h"
#include "menu.h"
#include <QLabel>
#include <QFrame>

Calender::Calender(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calender)
{
    ui->setupUi(this);

    // Set fixed window size (optional)
    this->setFixedSize(800, 600);

    // Initialize container and layouts
    m_eventsContainer = ui->scrollAreaWidgetContents;  // Use the widget from UI file
    m_eventsLayout = ui->eventsLayout;  // Use the layout from UI file

    // Configure layout
    m_eventsLayout->setAlignment(Qt::AlignTop);
    m_eventsLayout->setSpacing(10);

    // Configure scroll area
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(m_eventsContainer);
}

Calender::~Calender()
{
    delete ui;
    // Child widgets auto-deleted by Qt's parent system
}

void Calender::addEvent(const QString &name, const QString &desc, const QString &type, const QString &date, const QString &time,
                        const QString &platform, const int &capacity)
{
    QWidget *eventWidget = new QWidget(m_eventsContainer);
    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Set a background color and padding for the event widget
    eventWidget->setStyleSheet("background-color: #ffffff; border: 2px solid #000000; border-radius: 8px; padding: 10px;");

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

    // Add a separator using QFrame
    QFrame *separator = new QFrame(eventWidget);
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Sunken);
    eventLayout->addWidget(separator);

    m_eventsLayout->setSpacing(30);

    // Add the event widget to the main layout
    m_eventsLayout->addWidget(eventWidget);
}

void Calender::on_back_button_clicked()
{
    Menu *m = new Menu();  // Create menu window
    m->show();             // Show menu
    this->close();
}
