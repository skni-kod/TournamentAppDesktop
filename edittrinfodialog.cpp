#include "edittrinfodialog.h"
#include "ui_edittrinfodialog.h"

EditTrInfoDialog::EditTrInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditTrInfoDialog)
{
    ui->setupUi(this);
}

EditTrInfoDialog::~EditTrInfoDialog()
{
    delete ui;
}
