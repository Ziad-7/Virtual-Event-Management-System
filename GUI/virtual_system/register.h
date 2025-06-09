#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void addEvent(const QString &name, const QString &desc, const QString &type,
                  const QString &date, const QString &time, const QString &platform,
                  const int &capacity);

private slots:
    void on_back_button_clicked();

private:
    Ui::Register *ui;
    QVBoxLayout *m_eventsLayout;
    QWidget *m_eventsContainer;
};

#endif // REGISTER_H
