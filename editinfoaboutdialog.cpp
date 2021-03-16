#include "editinfoaboutdialog.h"
#include "ui_editinfoaboutdialog.h"
#include "tournamentinfo.h"
#include "QDebug"

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

    // TODO:
    //      Adding to file
    //      Adding validation
}
