#include <widgets/listview.h>
#include <QLabel>
#include <QTimeZone>
#include <models/Event.h>
#include <utils.h>
#include "ui_listview.h"
#include <ApplicationController.h>

using namespace std;

ListView::ListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
}

ListView::~ListView()
{
    delete ui;
}

void ListView::clear(){
    if(ui->rootLayout) utils::clearLayout(ui->rootLayout);
    ui->rootLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void ListView::addEvent(Event *e){
    auto layout = ui->rootLayout;
    auto dateTime = QDateTime::fromSecsSinceEpoch(e->getDatetime(), QTimeZone::systemTimeZone());
    auto date = dateTime.date();
    QFrame *frame = nullptr;
    int i=0;
    for(auto d : ui->root->children()){
        QFrame *f;
        if((f = qobject_cast<QFrame*>(d))){
            if(f->property("date").toDate() == date){
                frame = f;
                break;
            } else if (f->property("date").toDate() > date){
                break;
            }
            i++;
        }
    }


    if(!frame){
        frame = createFrameForDate(date);
        layout->insertWidget(i, frame);
    }

    i=0;
    for(auto d : frame->findChild<QFrame*>("events")->children()){
        QFrame *f;
        if((f = qobject_cast<QFrame*>(d))){
            if (f->property("datetime").toDateTime() > dateTime){
                break;
            }
            i++;
        }
    }

    auto event = createFrameForEvent(e);
    qobject_cast<QVBoxLayout*>(frame->findChild<QFrame*>("events")->layout())->insertWidget(i, event);
}

QFrame *ListView::createFrameForDate(QDate date){
    auto dayFrame = new QFrame(ui->root);
    dayFrame->setObjectName(date.toString());
    dayFrame->setFrameShape(QFrame::Box);
    dayFrame->setFrameShadow(QFrame::Plain);
    dayFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    dayFrame->setProperty("date", date);
    auto dayLayout = new QHBoxLayout(dayFrame);
    dayLayout->setContentsMargins(0, 0, 0, 0);
    dayLayout->setSpacing(0);
    { // Day Name
        auto dayNameFrame = new QFrame(dayFrame);
        dayNameFrame->setFrameShape(QFrame::NoFrame);
        dayNameFrame->setFrameShadow(QFrame::Plain);
        dayNameFrame->setLayout(new QHBoxLayout(dayNameFrame));
        dayNameFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        dayNameFrame->setMinimumSize(150, 0);
        dayNameFrame->setContentsMargins(0, 5, 0, 0);

        auto label = new QLabel(date.toString());
        label->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
        dayNameFrame->layout()->addWidget(label);
        dayLayout->addWidget(dayNameFrame);
    } // Day Name
    { // Events
        auto dayEventsFrame = new QFrame(dayFrame);
        dayEventsFrame->setObjectName("events");
        dayEventsFrame->setFrameShape(QFrame::NoFrame);
        dayEventsFrame->setFrameShadow(QFrame::Plain);
        dayEventsFrame->setLayout(new QVBoxLayout(dayEventsFrame));
        dayEventsFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        dayEventsFrame->layout()->setContentsMargins(0, 0, 0, 0);
        dayEventsFrame->layout()->setSpacing(0);

        dayLayout->addWidget(dayEventsFrame);
    } // Events
    dayFrame->setLayout(dayLayout);
    return dayFrame;
}

QFrame *ListView::createFrameForEvent(models::Event *e) {
    auto dateTime = QDateTime::fromSecsSinceEpoch(e->getDatetime(), QTimeZone::systemTimeZone());
    auto eventFrame = new QFrame();
    eventFrame->setFrameShape(QFrame::Box);
    eventFrame->setFrameShadow(QFrame::Plain);
    eventFrame->setProperty("datetime", dateTime);
    eventFrame->setLayout(new QHBoxLayout(eventFrame));
    eventFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    eventFrame->setMinimumSize(100, 40);
    eventFrame->layout()->setContentsMargins(0, 0, 0, 0);
    eventFrame->layout()->setSpacing(0);

    auto eventTime = new QLabel(dateTime.toString("h:mm ap"));
    eventTime->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    eventTime->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    eventTime->setMinimumSize(100, 0);
    eventTime->setContentsMargins(0, 2, 0, 2);
    eventFrame->layout()->addWidget(eventTime);

    auto colourBox = new QFrame();
    colourBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    colourBox->setFrameShape(QFrame::NoFrame);
    colourBox->setFrameShadow(QFrame::Plain);
    colourBox->setStyleSheet(utils::getColourForCourse(e->getCourseId()));
    colourBox->setMinimumSize(20, 0);
    eventFrame->layout()->addWidget(colourBox);

    auto eventInfo = new QLabel(e->getCourseId()+"\n"+e->getName());
    eventInfo->setContentsMargins(15, 2, 0, 2);
    eventInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    eventFrame->layout()->addWidget((eventInfo));

    return eventFrame;
}