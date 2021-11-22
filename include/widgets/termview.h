#ifndef TERMVIEW_H
#define TERMVIEW_H

#include <QWidget>
#include <QGridLayout>
#include "monthcalendar.h"

namespace Ui {
    class TermView;
}

class TermView : public QWidget
{
    Q_OBJECT

public:
    explicit TermView(QWidget* parent = nullptr);
    ~TermView();

private:
    Ui::TermView* ui;
};

#endif // TERMVIEW_H
