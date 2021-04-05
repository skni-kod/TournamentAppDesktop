
#include "edgetotournamentv.h"
#include "reacttotournamentv.h"
#include "tournamentview.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <qdebug.h>

enum Status{NOGAME=0,WIN_PLAYER2=2,WIN_PLAYER1=1,DRAW=3};
ReactToTournamentV::ReactToTournamentV(TournamentView *graphWidget)
    : graph(graphWidget)
{
    mainText= std::unique_ptr<QGraphicsTextItem>(new QGraphicsTextItem(this));

    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    players.push_back(new QFont("Pierwszy", 12));
    players.push_back(new QFont("Drugi", 12));
    setAcceptHoverEvents(true);
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());
    mainText->setPos(25,0);
    id=typid++;
}



void ReactToTournamentV::addEdge(EdgeToTournamentV *edge)
{
    edgeList << edge;
    edge->calcTheLength();
}

QList<EdgeToTournamentV *> ReactToTournamentV::edges() const
{
    return edgeList;
}

void ReactToTournamentV::changeStatus(bool player)
{

    players[player]->setFamily("<s>"+players[player]->family()+"</s>");
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());

}

int ReactToTournamentV::getId()
{
    return id;
}
QRectF ReactToTournamentV::boundingRect() const
{

    return QRectF(0, 0, 80, 80);
}
QPainterPath ReactToTournamentV::shape() const
{

    QPainterPath path;
    path.addEllipse(0, 0, 80, 80);
    return path;
}

void ReactToTournamentV::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::DotLine);
    painter->setBrush(Qt::NoBrush);
    //const QRect rectangle = QRect(25, 0, 80, 80);
    //painter->drawText(rectangle,players[0]+"\nvs\n"+players[1]);
    painter->drawRect(0, 0, 80, 80);

}

void ReactToTournamentV::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        emit clicked(idSQL);
    }



}


void ReactToTournamentV::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    if (!coordinateText) {
        coordinateText= std::unique_ptr<QGraphicsTextItem>(new QGraphicsTextItem(this));
        coordinateText->setPlainText(infoAboutEvent);
        coordinateText->setPos(2,2);
    }
    mainText->setVisible(false);
    coordinateText->setVisible(true);
    update();
    QGraphicsItem::hoverEnterEvent(event);

}

void ReactToTournamentV::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (coordinateText) {
        coordinateText->setVisible(false);
        mainText->setVisible(true);

    }
    update();
    QGraphicsItem::hoverEnterEvent(event);
}

void ReactToTournamentV::setPlayers(QString player1, QString player2)
{

    players[0]->setFamily(player1);
    players[1]->setFamily(player2);
    playersOrignal=players;
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());
    update();
}

void ReactToTournamentV::setId(int id)
{
    idSQL=id;
}

int ReactToTournamentV::getIdSql()
{
    return idSQL;
}

int ReactToTournamentV::getWin()
{
    return win;
}

QString ReactToTournamentV::getPlayer1()
{
    return players[0]->family();
}

QString ReactToTournamentV::getPlayer2()
{
    return players[1]->family();
}

void ReactToTournamentV::setWin(int win)
{

    if(win>NOGAME&&win<DRAW){

        this->win=win;
        this->changeStatus(win-1);
    }
    else{
        players=playersOrignal;
    }
}


void ReactToTournamentV::setInfo(QString info)
{
    infoAboutEvent=info;
    update();
}
