#ifndef DIALOGTOURNAMENTVIEW_H
#define DIALOGTOURNAMENTVIEW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class DialogTournamentView;
}

class DialogTournamentView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTournamentView(QWidget *parent = nullptr);
    ~DialogTournamentView();
    void setDb(QSqlDatabase *temp,int id);

signals:
    void clicked();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogTournamentView *ui;
    QSqlDatabase *db;
    int ID=-1;
};

#endif // DIALOGTOURNAMENTVIEW_H
