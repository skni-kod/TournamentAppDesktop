#ifndef EDITTRINFODIALOG_H
#define EDITTRINFODIALOG_H

#include <QDialog>

namespace Ui {
class EditTrInfoDialog;
}

class EditTrInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditTrInfoDialog(QWidget *parent = nullptr);
    ~EditTrInfoDialog();

private:
    Ui::EditTrInfoDialog *ui;
};

#endif // EDITTRINFODIALOG_H
