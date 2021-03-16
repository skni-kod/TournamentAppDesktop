#include "tabwidgetroundrobin.h"
#include "ui_tabwidgetroundrobin.h"
//PROTYPE UNTIL I GET REST API
TabWidgetRoundRobin::TabWidgetRoundRobin(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidgetRoundRobin)
{
    ui->setupUi(this);
    geneSQL();
    fillingTable();
}

TabWidgetRoundRobin::~TabWidgetRoundRobin()
{
    delete ui;
    for (auto &temp:tableView)delete temp;
    for (auto &temp:sqlModelToTable)delete temp;
}

void TabWidgetRoundRobin::geneSQL()
{
    const int Numbersofplayers=10;//temporary
    const QString idTurn="tabela";//temporary use static id
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qtt");
    db.setHostName("localhost");
    db.setPassword("");
    db.setPort(3306);
    db.setUserName("root");db.open();
    QSqlQuery query(db);
    query.prepare("CREATE TABLE IF NOT EXISTS "+idTurn+" (id int not null primary key, graczjeden text,graczdwa text,wynik text)");
    query.exec();
    QList <QString> Players={"Witek","Adam","Mati","Czeslaw","Ewa","Maciek","Madzia","Tymek" ,"Memento","Mori"};//temporary use of the list
    QVector<QVector<QString>> tempArray (2, QVector<QString> (Numbersofplayers/2, ""));
    if(db.isOpen())
        for(int mainloop=0,id=0;mainloop<Numbersofplayers-1;mainloop++){
            for(int i=0;i<2;i++){
                std::copy_n(Players.begin()+(i*Numbersofplayers/2),(Numbersofplayers/2),tempArray[i].begin());
            }
            //  for(auto &cd:tempArray)qDebug()<<cd[0]<<" "<<cd[1]<<cd[2]<<"\n";
            std::reverse(tempArray[1].begin(),tempArray[1].end());
            //  for(auto &cd:tempArray)qDebug()<<cd[0]<<" "<<cd[1]<<cd[2]<<"\n";
            for(int i=0;i<Numbersofplayers/2;i++){
                query.prepare("INSERT INTO "+idTurn+" (id, graczjeden, graczdwa) "
                                  "VALUES (:id, :forename, :surname)");
                query.bindValue(":id", ++id);//dodaj
                query.bindValue(":forename", tempArray[0][i]);
                query.bindValue(":surname",tempArray[1][i]);
                query.exec();
            }

            for(int j=Numbersofplayers-1;j>1;j--){
                std::swap(Players[j],Players[j-1]);
            }

            std::reverse(tempArray[1].begin(),tempArray[1].end());

        }


}

void TabWidgetRoundRobin::fillingTable()
{
    int Numbersofplayers=10;


    ;
    if(db.isOpen())
        for(int i=0,id=1;i<(Numbersofplayers-1);i++,id=id+(Numbersofplayers/2)){

            tableView.push_back(new QTableView(this));

            sqlModelToTable.push_back(new QSqlQueryModel(this));

            QSqlQuery query;
            query.prepare("SELECT `graczjeden`,`graczdwa`,`wynik` FROM `tabela` WHERE `id` BETWEEN "+QString::number(id)+" and "+QString::number(id+(Numbersofplayers/2)-1)+"");
            query.exec();
            //qDebug()<<query.lastError().text();
            sqlModelToTable[i]->setQuery(query);
            sqlModelToTable[i]->setHeaderData(0, Qt::Horizontal, QObject::tr("Gracz nr.1"));
            sqlModelToTable[i]->setHeaderData(1, Qt::Horizontal, QObject::tr("Gracz nr.2"));
            sqlModelToTable[i]->setHeaderData(2, Qt::Horizontal, QObject::tr("Wynik"));
            tableView[i]->setModel(sqlModelToTable[i]);
            this->addTab(tableView[i],QString::number(i));

        }
    tableView.push_back(new QTableView(this));
    sqlModelToTable.push_back(new QSqlQueryModel(this));
    QSqlQuery query;
    query.prepare("SELECT `graczjeden`,`graczdwa`,COUNT(`wynik`) FROM `tabela` GROUP BY `graczjeden` ORDER BY `COUNT(``wynik``)` DESC ");
    query.exec();
    sqlModelToTable.last()->setQuery(query);
    tableView.last()->setModel(sqlModelToTable.last());
    this->addTab(tableView.last(),"Podsumowanie");
    sqlModelToTable.last()->setHeaderData(0, Qt::Horizontal, QObject::tr("Gracz nr.1"));
    sqlModelToTable.last()->setHeaderData(1, Qt::Horizontal, QObject::tr("Gracz nr.2"));
    sqlModelToTable.last()->setHeaderData(2, Qt::Horizontal, QObject::tr("Wynik"));





}


