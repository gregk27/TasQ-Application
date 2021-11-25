#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QWidget>
#include <QFrame>

namespace models {
    class Event;
}

namespace Ui {
class ListView;
}

class ListView : public QWidget
{
    Q_OBJECT

public:
    explicit ListView(QWidget *parent = nullptr);
    ~ListView();

    void generateUI(std::unordered_map<QString, models::Event*> events);
private:

    Ui::ListView *ui;
    QFrame *createFrameForDate(QDate date);
    QFrame *createFrameForEvent(models::Event *e);

public slots:
    void onEventsChanged();
};

#endif // LISTVIEW_H
