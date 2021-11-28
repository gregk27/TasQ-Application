#ifndef MONTHCALENDAR_H
#define MONTHCALENDAR_H

#include <QWidget>
#include <QtWidgets>
#include <QGridLayout>

namespace Ui {
    class MonthCalendar;
}

class MonthCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit MonthCalendar(int month, QWidget* parent = nullptr);
    ~MonthCalendar();
    // Function to add assignments for month view
    void AddMAssign(QString classid, QString assign, QString type, QDateTime* due, QString colour);
    // Function to add assignments for term view
    void AddTAssign(QString classid, QString assign, QString type, QDateTime* due, QString colour);
    /**
     * Clear events in the calendar
     */
    void clear();

private:
    Ui::MonthCalendar* ui;
    QVBoxLayout* mdue[31] = {nullptr};   // Layout to hold assignments in month view
    QHBoxLayout* tdue[31] = {nullptr};   // Layout to hold assignments in term view
};

#endif // MONTHCALENDAR_H
