#include "dialogtournamentview.h"
#include "ui_dialogtournamentview.h"

DialogTournamentView::DialogTournamentView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTournamentView)
{
    ui->setupUi(this);
    db=nullptr;
}

DialogTournamentView::~DialogTournamentView()
{
    delete ui;
}

void DialogTournamentView::setDb(QSqlDatabase *temp,int id)

{
    ID=id;
    this->db=temp;
}


void DialogTournamentView::on_buttonBox_accepted()
{
    if(db->open()){
        QSqlQuery query("SELECT * FROM tabela1",*db);
        query.exec();
        query.seek(ID,false);
        QString player1 = query.value("graczjeden").toString();
        QString player2 = query.value("graczdwa").toString();

        QString fromLine[2]={ui->lineEdit->text(),ui->lineEdit_2->text()};
        if(player1!=fromLine[0]||player2!=fromLine[1]){
            QSqlQuery querytemp(*db);
            querytemp.prepare("UPDATE tabela1 SET graczjeden=:one,graczdwa=:two WHERE id=:ID");
            querytemp.bindValue(":one",fromLine[0]);
            querytemp.bindValue(":two",fromLine[1]);
            querytemp.bindValue(":ID",ID+1);
            querytemp.exec();
        }
        fromLine->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        emit clicked();
    }


}
