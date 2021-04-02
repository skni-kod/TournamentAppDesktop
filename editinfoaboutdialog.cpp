#include "editinfoaboutdialog.h"
#include "ui_editinfoaboutdialog.h"
#include "tournamentinfo.h"
#include "QDebug"
#include "QMessageBox"

EditInfoAboutDialog::EditInfoAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInfoAboutDialog)
{
    ui->setupUi(this);
}

EditInfoAboutDialog::~EditInfoAboutDialog()
{
    delete ui;
}

void EditInfoAboutDialog::on_cancelSettingsButton_clicked()
{
    reject();
}

void EditInfoAboutDialog::on_saveSettingsButton_clicked()
{
    TournamentInfo tmpTournament;
    bool isDataIncorrect = false;
    QString message = "";

    // Reading text from edit fields
    tmpTournament.setTournamentAddress(ui->addressTextEdit->toPlainText());
    tmpTournament.setTournamentDate((ui->dateTimeEdit->dateTime()).toString()); // Format: "Tue Sep 14 00:55:00 2021"
    qDebug() << tmpTournament.getTournamentDate();
    tmpTournament.setMaxMembersLimit(ui->membersSpinBox->value());
    qDebug() << tmpTournament.getMaxMembersLimit();
    tmpTournament.setMinCategory(ui->minCategoryComboBox->currentText());
    qDebug() << tmpTournament.getMinCategory();
    tmpTournament.setMaxCategory(ui->maxCategoryComboBox->currentText());
    qDebug() << tmpTournament.getMaxCategory();
    tmpTournament.setWinPointsAssignment(ui->winPointsAssignmentSpinBox->value());
    qDebug() << tmpTournament.getWinPointsAssignment();
    tmpTournament.setLosePointsAssignment(ui->losePointsAssignmentSpinBox->value());
    qDebug() << tmpTournament.getLosePointsAssignment();
    tmpTournament.setDrawPointsAssignment(ui->drawPointsAssignmentSpinBox->value());
    qDebug() << tmpTournament.getDrawPointsAssignment();
    tmpTournament.setByePointsAssignment(ui->byePointsAssignmentSpinBox->value());
    qDebug() << tmpTournament.getByePointsAssignment();
    tmpTournament.setPairingSystem(ui->roundRobinRadioButton->isChecked(), ui->radioButton_2->isChecked());
    if(tmpTournament.getTournamentAddress().length() == 0){
        message += "Address is required\n";
        isDataIncorrect = true;
    }
    if(tmpTournament.getWinPointsAssignment() == 0){
        message += "Win points are required\n";
        isDataIncorrect = true;
    }

    if(tmpTournament.getPairingSystem() == "Unknown"){
        message += "Pairing System is required\n";
        isDataIncorrect = true;
    }

    if(ui->maxCategoryComboBox->currentIndex() > ui->minCategoryComboBox->currentIndex()){ // cose the indexes are the other way around than category
        message += "Choose good Category range";
        isDataIncorrect = true;
    }

    if(isDataIncorrect)
    {
        QMessageBox messageBox1 (QMessageBox::Warning, "Incorrect data", message);
        messageBox1.exec();
    }

    if(!isDataIncorrect)
    {
        accept();
    }
}
