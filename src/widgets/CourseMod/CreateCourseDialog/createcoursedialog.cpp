//
// Created by Greg on 2021-11-26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateClassDialog.h" resolved

#include <include/widgets/coursemod/createcoursedialog.h>
#include "ui_CreateCourseDialog.h"
#include <QComboBox>
#include <net/schools.h>
#include <net/auth.h>
#include <regex>
#include <ApplicationController.h>

using namespace std;

CreateCourseDialog::CreateCourseDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::CreateCourseDialog) {
    ui->setupUi(this);
    setModal(true);
    // Set the school combobox to user's school
    // This can't be change, is just a display
    auto user = AuthController::instance()->getLocalUser();
    // TODO: Optimize significantly
    auto schools = *net::schools::getSchools();
    for(auto s : schools){
        if(s.getId() == user->getSchoolId()){
            ui->schoolInput->addItem(s.getName(), s.getId());
            ui->schoolInput->setCurrentIndex(0);
        }
    }
    ui->schoolInput->setDisabled(true);

    // Setup term dropdown, has to be in code to set userdata
    ui->termInput->addItem(models::enums::Term::FALL.toString(), models::enums::Term::FALL.toDB());
    ui->termInput->addItem(models::enums::Term::WINTER.toString(), models::enums::Term::WINTER.toDB());
    ui->termInput->addItem(models::enums::Term::SPRING.toString(), models::enums::Term::SPRING.toDB());
    ui->termInput->addItem(models::enums::Term::SUMMER.toString(), models::enums::Term::SUMMER.toDB());
}

CreateCourseDialog::~CreateCourseDialog() {
    delete ui;
}

void CreateCourseDialog::createCourse(){
    // Match ABCD 1234
    regex codeRegex(R"(\w\w\w\w \d\d\d\d?)");
    if(!regex_match(ui->codeInput->text().toStdString(), codeRegex)){
        ui->errorLabel->setText("Invalid course code");
        return;
    }
    regex yearRegex(R"(\d\d\d\d)");
    if(!regex_match(ui->yearInput->text().toStdString(), yearRegex)){
        ui->errorLabel->setText("Invalid year");
    }
    ui->errorLabel->setText("");

    QJsonObject js;
    js["id"] = "";
    js["name"] = ui->nameInput->text();
    js["code"] = ui->codeInput->text();
    js["year"] = ui->yearInput->text().toInt();
    js["term"] = ui->termInput->currentData().toString();
    js["prof"] = ui->profInput->text();
    js["owner"] = AuthController::instance()->getLocalUID();
    js["school"] = ui->schoolInput->currentData().toString();
    js["modified"] = 0;

    ApplicationController::instance()->addInstance<Course>(new Course(js));
    close();
}

