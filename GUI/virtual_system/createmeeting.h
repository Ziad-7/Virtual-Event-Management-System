#ifndef CREATEMEETING_H
#define CREATEMEETING_H

#include <QWidget>

namespace Ui {
class CreateMeeting;
}

class CreateMeeting : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMeeting(QWidget *parent = nullptr);
    ~CreateMeeting();

private slots:
    void on_back_clicked();

    void on_create_clicked();

private:
    Ui::CreateMeeting *ui;
};

#endif // CREATEMEETING_H
