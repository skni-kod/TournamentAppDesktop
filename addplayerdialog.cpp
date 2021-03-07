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

    //Reading text from line Edit fields
    tempPlayer.setFirstName(ui->lineEdit->text());
    tempPlayer.setLastName(ui->lineEdit_2->text());
    tempPlayer.setRating(ui->lineEdit_3->text().toShort());

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
    if(tempPlayer.getRating() < 0 || tempPlayer.getRating()> 30000)
    {
        message+= "Rating must be in range: 0 - 30000";
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
