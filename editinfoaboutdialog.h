#ifndef EDITINFOABOUTDIALOG_H
#define EDITINFOABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class EditInfoAboutDialog;
}

class EditInfoAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditInfoAboutDialog(QWidget *parent = nullptr);
    ~EditInfoAboutDialog();

private:
    Ui::EditInfoAboutDialog *ui;
};

#endif // EDITINFOABOUTDIALOG_H
