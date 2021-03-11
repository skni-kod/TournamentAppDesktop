#include "modifyplayerdialog.h"
#include "ui_modifyplayerdialog.h"
#include "player.h"
#include "playerbase.h"
#include "QMessageBox"


ModifyPlayerDialog::ModifyPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPlayerDialog)
{
    ui->setupUi(this);
}

ModifyPlayerDialog::~ModifyPlayerDialog()
{
    delete ui;
}

void ModifyPlayerDialog::setSelectedRow(int row)
{
    selectedRow = row;
}

void ModifyPlayerDialog::fillLineEdits()
{
    ui->lineEditFirstN->setText(playerBase::Get().get_player(selectedRow).getFirstName());
    ui->lineEditLastN->setText(playerBase::Get().get_player(selectedRow).getLastName());
    if(playerBase::Get().get_player(selectedRow).getSex() == "Woman")
        ui->radioButtonWoman->setChecked(true);
    if(playerBase::Get().get_player(selectedRow).getSex() == "Man")
        ui->radioButtonMan->setChecked(true);
    if(playerBase::Get().get_player(selectedRow).getSex() == "Unknown")
    {
        ui->radioButtonWoman->setChecked(false);
        ui->radioButtonMan->setChecked(false);
    }
    ui->spinBoxRating->setValue(playerBase::Get().get_player(selectedRow).getRating());
    int tmp = ui->comboBox->findText(playerBase::Get().get_player(selectedRow).getCategories());
    ui->comboBox->setCurrentIndex(tmp);
    ui->lineEditCountry->setText(playerBase::Get().get_player(selectedRow).getCountry());
    ui->lineEditClub->setText(playerBase::Get().get_player(selectedRow).getClub());
}

void ModifyPlayerDialog::on_modifyButton_clicked()
{
    Player tempPlayer;
    bool isDataIncorrect = false;
    //Reading text from lineEdit fields
    tempPlayer.setFirstName(ui->lineEditFirstN->text());
    tempPlayer.setLastName(ui->lineEditLastN->text());
    tempPlayer.setSex(ui->radioButtonWoman->isChecked(),ui->radioButtonMan->isChecked());
    tempPlayer.setRating(ui->spinBoxRating->text().toShort());
    tempPlayer.setCategories(ui->comboBox->currentText());
    tempPlayer.setCountry(ui->lineEditCountry->text());
    tempPlayer.setClub(ui->lineEditClub->text());

    QString message;
    if(tempPlayer.getFirstName().length() == 0)
    {
        message += "First name is required\n";
        isDataIncorrect = true;
    }
    if(tempPlayer.getLastName().length() == 0)
    {
        message += "Last name is required\n";
        isDataIncorrect = true;
    }
    if(tempPlayer.getCategories() == "-----")
    {
        message += "Categories is required\n";
        isDataIncorrect = true;
    }
    if(tempPlayer.getCountry().length() == 0)
    {
        message += "Country is required\n";
        isDataIncorrect = true;
    }
    if(tempPlayer.getClub().length() == 0)
    {
        message += "Club is required\n";
        isDataIncorrect = true;
    }
    if(isDataIncorrect)
    {
        QMessageBox messageBox1 (QMessageBox::Warning, "Incorrect data", message);
        messageBox1.exec();
    }
    if(!isDataIncorrect)
    {
        //adding player to playerStorage located in playerBase object
        playerBase::Get().add(tempPlayer);
        accept();
    }
}

void ModifyPlayerDialog::on_cancelButton_clicked()
{
    reject();
}
