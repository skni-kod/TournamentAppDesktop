#include "tournamentview.h"
#include <math.h>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>
#include <QMenu>
#include <QAction>
int ReactToTournamentV::typid=0;
// it s prototype,after adding the login panel, half of the functions will be transferred
TournamentView::TournamentView(QWidget *parent)
    : QGraphicsView(parent)
{
    dialogedit= new DialogTournamentView(this);

    this->setContextMenuPolicy(Qt::CustomContextMenu);

    const int Numbersofplayers=9;//temporary
    int temp=Numbersofplayers/2;
    int hight=80;
    int weight=80;
    int mul=ceil(temp/2.0);
    int logNumber=ceil(log2(Numbersofplayers));
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-500, -500, 2*Numbersofplayers*hight, 2*Numbersofplayers*weight);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    {

        int weight_2=0;
        int log_temp=Numbersofplayers;
        for(int i=0,step=1,iter=0;i<=logNumber;i++,step*=2,log_temp/=2){
            if(i>0)weight_2=80;
            for(int j=1;j<=step&&iter<Numbersofplayers-1;j++,iter++){

                react.push_back(new ReactToTournamentV(this));
                scene->addItem(react.last());
                react.last()->setPlayers(QString::number(react.last()->getId()),"");
                if(iter%2==0) react.last()->setPos(2*mul*hight-i*120,2*mul*weight/2-weight_2);
                else  react.last()->setPos(2*mul*hight-i*120,2*mul*weight/2+weight_2);
                if((j%2==0))weight_2+=80*log_temp;
            }
        }
    }
    for(int i=1;i<3;i++)
        if(i<react.size()){
            edge.push_back(new EdgeToTournamentV(react.at(0),react.at(i)));
            scene->addItem(edge.last());
        }

    for(int i=0,step=2,step_2=4;i<logNumber-2;i++,step*=2,step_2*=2)
        for(int j=1,temp=step,temp_2=step_2;j<step;j+=2,temp+=2,temp_2+=4){
            if(temp_2<react.size())
            {edge.push_back(new EdgeToTournamentV(react.at(temp),react.at(temp_2)));
                scene->addItem(edge.last());

            }
            if(temp_2+2<react.size())
            {
                edge.push_back(new EdgeToTournamentV(react.at(temp),react.at(temp_2+2)));
                scene->addItem(edge.last());
            }
        }
    for(int i=0,step=2,step_2=4;i<logNumber-2;i++,step*=2,step_2*=2)
        for(int j=1,temp=step-1,temp_2=step_2-1;j<step;j+=2,temp+=2,temp_2+=4){
            if(temp_2<react.size())
            {edge.push_back(new EdgeToTournamentV(react.at(temp),react.at(temp_2)));
                scene->addItem(edge.last());

            }
            if(temp_2+2<react.size())
            {
                edge.push_back(new EdgeToTournamentV(react.at(temp),react.at(temp_2+2)));
                scene->addItem(edge.last());
            }
        }


    int idy=0;

    const QString idTurn="tabela1";//temporary use static id
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("qtt");
    db.setHostName("localhost");
    db.setPassword("");
    db.setPort(3306);
    db.setUserName("root");
    if(db.open()){

        QSqlQuery query(db);
        query.prepare("CREATE TABLE IF NOT EXISTS "+idTurn+" (id int not null primary key, graczjeden text,graczdwa text,wynik text,info text)");
        query.exec();
        QList <QString> Players={"Witek","Adam","Mati","Czeslaw","Ewa","Maciek","Madzia","Tymek","lop"};//temporary use of the list

        if(db.isOpen())

            for(int mainloop=0,i=0;mainloop<Numbersofplayers/2;mainloop++){
                query.prepare("INSERT INTO "+idTurn+" (id, graczjeden, graczdwa) "
                          "VALUES (:id, :forename, :surname)");
                query.bindValue(":id", ++idy);//dodaj
                query.bindValue(":forename", Players[i++]);
                query.bindValue(":surname",Players[i++]);
                query.exec();
            }
        for(int mainloop=0;mainloop<Numbersofplayers-Players.size()/2-1;mainloop++){

            query.prepare("INSERT INTO "+idTurn+" (id, graczjeden, graczdwa) "
                      "VALUES (:id, :forename, :surname)");
            query.bindValue(":id", ++idy);//dodaj
            query.bindValue(":forename", "");
            query.bindValue(":surname","");
            query.exec();
        }

        foreach(ReactToTournamentV * temp, react) {
            connect(temp, &ReactToTournamentV::clicked,this,[&](int id){IdManaged=id;});


        }
        fillTheLeader();
    }
    connect(dialogedit,SIGNAL(clicked()),this,SLOT( fillTheLeader()));
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));

}



void TournamentView::wheelEvent(QWheelEvent *event)
{
    QPointF pos = mapToScene(event->pos());
    float delta = 1.0f + event->angleDelta().y() / 1200.0f;
    QTransform form = transform();
    form.translate(pos.x(), pos.y()); // origin to spot
    form.scale(delta, delta); // scale
    form.translate(-pos.x(), -pos.y()); // spot to origin
    setTransform(form);
    update();
}


void TournamentView::drawBackground(QPainter *painter, const QRectF &rect)
{

    QRectF sceneRect = this->sceneRect();

    painter->setBrush(Qt::NoBrush);
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Turniej nr.xxx"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);

}

void TournamentView::ShowContextMenu(QPoint pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    // QList<EdgeToTournamentV *> tempListEdge;


    QMenu myMenu;
    myMenu.addAction("Edytuj event");
    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem&&IdManaged!=-1)
    {
        dialogedit->setDb(&db,IdManaged);
        dialogedit->show();
        //        foreach(EdgeToTournamentV * temp,edge){
        //            if(temp->getTarget()->getId()==IdManaged)
        //                if(temp->getTarget()->getWin())temp->getSource()->setPlayers()
        //        }

    }
    else
    {

    }
    IdManaged=-1;

}

void TournamentView::fillTheLeader()
{
    if(db.open()){

        QSqlQuery query("SELECT * FROM tabela1",db);
        for(auto iter=react.size(),i=0;(query.next())&&iter>=0;)
        {
            QString player1 = query.value("graczjeden").toString();
            QString player2 = query.value("graczdwa").toString();
            int wynik=query.value("wynik").toInt();
            QString info=query.value("info").toString();


            react.at(--iter)->setPlayers(player1,player2);
            react.at(iter)->setId(i++);
            react.at(iter)->setWin(wynik);
            react.at(iter)->setInfo({info});
            // qDebug()<<react.at(iter)->getWin();
        }
    }

    update();
}

void TournamentView::refresh()
{
    fillTheLeader();
    delete dialogedit;
    dialogedit=new DialogTournamentView(this);
}





