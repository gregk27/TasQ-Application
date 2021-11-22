#include <widgets/schedulelistview.h>
#include <QLabel>
#include "ui_schedulelistview.h"

ScheduleListView::ScheduleListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleListView)
{
    ui->setupUi(this);
    generateUI();
}

ScheduleListView::~ScheduleListView()
{
    delete ui;
}

void ScheduleListView::generateUI(){
    QString days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    auto layout = ui->rootLayout;
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0) {
        delete child;
    }
    for(auto d : days){
        auto dayFrame = new QFrame(this);
        dayFrame->setFrameShape(QFrame::Box);
        dayFrame->setFrameShadow(QFrame::Plain);
        dayFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        auto dayLayout = new QHBoxLayout(dayFrame);
        dayLayout->setContentsMargins(0, 0, 0, 0);
        dayLayout->setSpacing(0);
        { // Day Name
            auto dayNameFrame = new QFrame();
            dayNameFrame->setFrameShape(QFrame::NoFrame);
            dayNameFrame->setFrameShadow(QFrame::Plain);
            dayNameFrame->setLayout(new QHBoxLayout(dayNameFrame));
            dayNameFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
            dayNameFrame->setMinimumSize(150, 0);
            dayNameFrame->setContentsMargins(0, 5, 0, 0);

            auto label = new QLabel(d);
            label->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
            dayNameFrame->layout()->addWidget(label);
            dayLayout->addWidget(dayNameFrame);
        } // Day Name
        { // Events
            auto dayEventsFrame = new QFrame();
            dayEventsFrame->setFrameShape(QFrame::NoFrame);
            dayEventsFrame->setFrameShadow(QFrame::Plain);
            dayEventsFrame->setLayout(new QVBoxLayout(dayEventsFrame));
            dayEventsFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            dayEventsFrame->layout()->setContentsMargins(0, 0, 0, 0);
            dayEventsFrame->layout()->setSpacing(0);
            for(int i=0; i<3; i++){
                auto eventFrame = new QFrame();
                eventFrame->setFrameShape(QFrame::Box);
                eventFrame->setFrameShadow(QFrame::Plain);
                eventFrame->setLayout(new QHBoxLayout(eventFrame));
                eventFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                eventFrame->setMinimumSize(100, 40);
                eventFrame->layout()->setContentsMargins(0, 0, 0, 0);
                eventFrame->layout()->setSpacing(0);

                auto eventTime = new QLabel(QString::fromStdString("Timestamp "+ std::to_string(i)));
                eventTime->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
                eventTime->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
                eventTime->setMinimumSize(100, 0);
                eventTime->setContentsMargins(0, 2, 0, 2);
                eventFrame->layout()->addWidget(eventTime);

                auto colourBox = new QFrame();
                colourBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
                colourBox->setFrameShape(QFrame::NoFrame);
                colourBox->setFrameShadow(QFrame::Plain);
                colourBox->setStyleSheet("background-color: rgb("+QString::fromStdString(std::to_string(127*i))+", 0, 0);");
                colourBox->setMinimumSize(20, 0);
                eventFrame->layout()->addWidget(colourBox);

                auto eventInfo = new QLabel("COURSE CODE\nEVENT NAME");
                eventInfo->setContentsMargins(15, 2, 0, 2);
                eventInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                eventFrame->layout()->addWidget((eventInfo));

                dayEventsFrame->layout()->addWidget(eventFrame);
            }
            dayLayout->addWidget(dayEventsFrame);
        } // Events
        dayFrame->setLayout(dayLayout);
        layout->addWidget(dayFrame);
    }
}

