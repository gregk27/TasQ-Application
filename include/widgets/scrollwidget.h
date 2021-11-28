//
// Created by Greg on 2021-11-27.
//

#ifndef TASQ_APPLICATION_SCROLLWIDGET_H
#define TASQ_APPLICATION_SCROLLWIDGET_H

#include <QFrame>


QT_BEGIN_NAMESPACE
namespace Ui { class ScrollWidget; }
QT_END_NAMESPACE

class ScrollWidget : public QFrame {
    Q_OBJECT

public:
    explicit ScrollWidget(QWidget *parent = nullptr);

    ~ScrollWidget() override;

    bool event(QEvent *e) override;

public slots:
    void clearContent();
    void addWidget(QWidget *widget);

private:
    Ui::ScrollWidget *ui;
};


#endif //TASQ_APPLICATION_SCROLLWIDGET_H
