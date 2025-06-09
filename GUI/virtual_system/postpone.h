#ifndef POSTPONE_H
#define POSTPONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>

namespace Ui {
class Postpone;
}

class Postpone : public QWidget
{
    Q_OBJECT

public:
    explicit Postpone(QWidget *parent = nullptr);
    ~Postpone();

    void addEvent(const QString &name, const QString &desc, const QString &type,
                  const QString &date, const QString &time, const QString &platform,
                  const int &capacity);

private slots:
    void on_back_button_clicked();

private:
    Ui::Postpone *ui;
    QVBoxLayout *m_eventsLayout;
    QWidget *m_eventsContainer;
};

#endif // POSTPONE_H
