#ifndef CALENDER_H
#define CALENDER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>

namespace Ui {
class Calender;
}

class Calender : public QWidget
{
    Q_OBJECT

public:
    explicit Calender(QWidget *parent = nullptr);
    ~Calender();

    void addEvent(const QString &name, const QString &desc, const QString &type, const QString &date, const QString &time
                  , const QString &platform, const int &capacity);

private slots:
    void on_back_button_clicked();

private:
    Ui::Calender *ui;
    QVBoxLayout *m_eventsLayout;
    QWidget *m_eventsContainer;
};

#endif // CALENDER_H
