#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>

namespace Ui {
class AddPlayerDialog;
}

class AddPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerDialog(QWidget *parent = nullptr);
    ~AddPlayerDialog();

private slots:
    void on_addButton_clicked();   //"Add" button clicked() slot

    void on_cancelButton_clicked(); //"Cancel" button clicked() slot

private:
    Ui::AddPlayerDialog *ui;
};

#endif // ADDPLAYERDIALOG_H
