#include "editinfoaboutdialog.h"
#include "ui_editinfoaboutdialog.h"

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
