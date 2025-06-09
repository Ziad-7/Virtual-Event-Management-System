#ifndef CANCEL_H
#define CANCEL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>

namespace Ui {
class Cancel;
}

class Cancel : public QWidget
{
    Q_OBJECT

public:
    explicit Cancel(QWidget *parent = nullptr);
    ~Cancel();

    void addEvent(const QString &name, const QString &desc, const QString &type,
                  const QString &date, const QString &time, const QString &platform,
                  const int &capacity);

private slots:
    void on_back_button_clicked();

private:
    Ui::Cancel *ui;
    QVBoxLayout *m_eventsLayout;
    QWidget *m_eventsContainer;
};

#endif // CANCEL_H
