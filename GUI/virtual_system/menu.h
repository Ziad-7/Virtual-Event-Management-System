#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_create_meeting_clicked();

    void on_show_events_clicked();

    void on_register_meeting_clicked();

    void on_search_for_event_clicked();

    void on_cancel_meeting_clicked();

    void on_postpone_meeting_clicked();

    void on_feedback_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
