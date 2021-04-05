#ifndef DIALOGTOURNAMENTVIEW_H
#define DIALOGTOURNAMENTVIEW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QButtonGroup>

namespace Ui {
class DialogTournamentView;
}

class DialogTournamentView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTournamentView(QWidget *parent = nullptr);
    ~DialogTournamentView();
    void setDb(QSqlDatabase *temp,int id);//ustaw baze danych i zaladuj dane z bazy

signals:
    void clicked();//gdy przycisk zatwierdz

private slots:
    void on_buttonBox_accepted();//gdy przycisk zatwierdz to aktu. baze


private:
    Ui::DialogTournamentView *ui;
    QSqlDatabase *db;
    int ID=-1;//id kwadratu
    int win=0;//kto wygral[0-wydarzenie nie odbylo sie jezscze,1-gracz1,2-gracz2,3-remis]
    QButtonGroup * buttonGroup;//zmienna do grupowania radiobutton
};

#endif // DIALOGTOURNAMENTVIEW_H
