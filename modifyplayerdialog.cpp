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
    ui->lineEdit->setText(playerBase::Get().get_player(selectedRow).getFirstName());
    ui->lineEdit_2->setText(playerBase::Get().get_player(selectedRow).getLastName());
    ui->lineEdit_3->setText(QString::number(playerBase::Get().get_player(selectedRow).getRating()));
}

void ModifyPlayerDialog::on_modifyButton_clicked()
{
    Player tempPlayer;
    bool isDataIncorrect = false;
    //Reading text from lineEdit fields
    tempPlayer.setFirstName(ui->lineEdit->text());
    tempPlayer.setLastName(ui->lineEdit_2->text());
    tempPlayer.setRating(ui->lineEdit_3->text().toShort());

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
        playerBase::Get().edit(tempPlayer, selectedRow);
        accept();
    }
}

void ModifyPlayerDialog::on_cancelButton_clicked()
{
    reject();
}
