#ifndef TABNAVIGATOR_H
#define TABNAVIGATOR_H

#include <QWidget>

namespace Ui {
class TabNavigator;
}

class TabNavigator : public QWidget
{
    Q_OBJECT

public:
    explicit TabNavigator(QWidget *parent = nullptr);
    ~TabNavigator();

private:
    Ui::TabNavigator *ui;
};

#endif // TABNAVIGATOR_H
