#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QtDebug"
#include "playerbase.h"

AddPlayerDialog::AddPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayerDialog)
{
    ui->setupUi(this);
}

AddPlayerDialog::~AddPlayerDialog()
{
    delete ui;
}

void AddPlayerDialog::on_addButton_clicked()
{
    Player tempPlayer;
    bool isDataIncorrect = false;

    //Reading text from edit fields
    tempPlayer.setFirstName(ui->lineEditFirstN->text());
    tempPlayer.setLastName(ui->lineEditLastN->text());
    tempPlayer.setSex(ui->radioButtonWoman->isChecked(),ui->radioButtonMan->isChecked());
    tempPlayer.setRating(ui->spinBoxRating->text().toShort());
    tempPlayer.setCategories(ui->comboBox->currentText());
    tempPlayer.setCountry(ui->lineEditCountry->text());
    tempPlayer.setClub(ui->lineEditClub->text());

    //checking whether all fields are filled and displaying a message if something is wrong
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

void AddPlayerDialog::on_cancelButton_clicked()
{
    reject();
}
