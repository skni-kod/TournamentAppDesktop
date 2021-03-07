#ifndef MODIFYPLAYERDIALOG_H
#define MODIFYPLAYERDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyPlayerDialog;
}

class ModifyPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPlayerDialog(QWidget *parent = nullptr);
    ~ModifyPlayerDialog();
    void setSelectedRow (int row); //sets the value of selectedRow
    void fillLineEdits(); //fills LineEdits with previous player data

private slots:
    void on_modifyButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ModifyPlayerDialog *ui;
    int selectedRow = -1;
};

#endif // MODIFYPLAYERDIALOG_H
