#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class Feedback;
}

class Feedback : public QWidget
{
    Q_OBJECT

public:
    explicit Feedback(QWidget *parent = nullptr);
    ~Feedback();

    void addEvent(const QString &name, const QString &desc, const QString &type,
                  const QString &date, const QString &time, const QString &platform,
                  const int &capacity);

private slots:
    void on_back_button_clicked();

private:
    Ui::Feedback *ui;
    QVBoxLayout *m_eventsLayout;
    QWidget *m_eventsContainer;
};

#endif // FEEDBACK_H
