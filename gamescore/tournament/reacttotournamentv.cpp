
#include "edgetotournamentv.h"
#include "reacttotournamentv.h"
#include "tournamentview.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <qdebug.h>
/*!
 * \brief The Status enum
 */
enum Status{NOGAME=0,WIN_PLAYER2=2,WIN_PLAYER1=1,DRAW=3};
/*!
 * \brief ReactToTournamentV::ReactToTournamentV
 * \param graphWidget
 */
ReactToTournamentV::ReactToTournamentV(TournamentView *graphWidget)
    : graph(graphWidget)
{
    mainText= std::unique_ptr<QGraphicsTextItem>(new QGraphicsTextItem(this));
    playersOrignal<<"Pierwszy"<<"Drugi";
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    players.push_back(new QFont(playersOrignal.at(0), 12));
    players.push_back(new QFont(playersOrignal.at(1), 12));
    setAcceptHoverEvents(true);
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());
    mainText->setPos(25,0);
    id=typid++;
}


/*!
 * \brief ReactToTournamentV::addEdge
 * Dodaje krawędzie
 * \param edge
 */
void ReactToTournamentV::addEdge(EdgeToTournamentV *edge)
{
    edgeList << edge;
    edge->calcTheLength();
}
/*!
 * \brief ReactToTournamentV::edges
 * Zwraca listę krawędzi
 * \return
 */
QList<EdgeToTournamentV *> ReactToTournamentV::edges() const
{
    return edgeList;
}
/*!
 * \brief ReactToTournamentV::changeStatus
 * Zmiana statusu osoby na wygraną.
 * \param player 0-pierwszy gracz,1-drugi gracz
 */
void ReactToTournamentV::changeStatus(bool player)
{
    players.at(0)->setFamily(playersOrignal.at(0));
    players.at(1)->setFamily(playersOrignal.at(1));
    players[player]->setFamily("<b>"+playersOrignal.at(player)+"</b>");
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());

}
/*!
 * \brief ReactToTournamentV::getId
 * \return Zwraca id kwadratu
 */
int ReactToTournamentV::getId()
{
    return id;
}
/*!
 * \brief ReactToTournamentV::boundingRect
 * \return
 */
QRectF ReactToTournamentV::boundingRect() const
{

    return QRectF(0, 0, 80, 80);
}
/*!
 * \brief ReactToTournamentV::shape
 * \return
 */
QPainterPath ReactToTournamentV::shape() const
{

    QPainterPath path;
    path.addRect(0, 0, 80, 80);
    return path;
}
/*!
 * \brief ReactToTournamentV::paint
 * Rysuje nam kwadrat
 * \param painter
 * \param option
 */
void ReactToTournamentV::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::DotLine);
    painter->setBrush(Qt::NoBrush);
    //const QRect rectangle = QRect(25, 0, 80, 80);
    //painter->drawText(rectangle,players[0]+"\nvs\n"+players[1]);
    painter->drawRect(0, 0, 80, 80);

}
/*!
 * \brief ReactToTournamentV::mousePressEvent
 * W pzypadku kliknięcia kwadratu emituje on sygnał,który przekazuje id tego kwadratu.
 * \param event
 */
void ReactToTournamentV::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        emit clicked(idSQL);
    }



}

/*!
 * \brief ReactToTournamentV::hoverEnterEvent
 * W przypadku gdy najedziemy myszką,chowają sie dane i pokazują inne.
 * \param event
 */
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
/*!
 * \brief ReactToTournamentV::hoverLeaveEvent
 * Wraca do poprzednich danych,gdy zjedziemy z naszego kwadratu.
 * \param event
 */
void ReactToTournamentV::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (coordinateText) {
        coordinateText->setVisible(false);
        mainText->setVisible(true);

    }
    update();
    QGraphicsItem::hoverEnterEvent(event);
}
/*!
 * \brief ReactToTournamentV::setPlayers
 * Ustawia nazwy graczy.
 * \param player1 Imie pierwszego gracza.
 * \param player2 Imie drugiego gracz.
 */
void ReactToTournamentV::setPlayers(QString player1, QString player2)
{

    players[0]->setFamily(player1);
    players[1]->setFamily(player2);
    playersOrignal.replace(0,player1);
    playersOrignal.replace(1,player2);
    mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());
    update();
}
/*!
 * \brief ReactToTournamentV::setId
 * Ustaw id eventu.
 * \param id
 */
void ReactToTournamentV::setId(int id)
{
    idSQL=id;
}
/*!
 * \brief ReactToTournamentV::getIdSql
 * Otrzymaj id jaki reprezentuje nasz kwadrat.
 * \return
 */
int ReactToTournamentV::getIdSql()
{
    return idSQL;
}
/*!
 * \brief ReactToTournamentV::getWin
 * Otrzymaj nr wygranego.
 * \return 1-Pierwszy gracz,2-Drugi gracz
 */
int ReactToTournamentV::getWin()
{
    return win;
}
/*!
 * \brief ReactToTournamentV::getPlayer1
 * \return Imie Pierwszego gracza.
 */
QString ReactToTournamentV::getPlayer1()
{
    return playersOrignal[0];
}
/*!
 * \brief ReactToTournamentV::getPlayer2
 * \return Imie drugiego gracza.
 */
QString ReactToTournamentV::getPlayer2()
{
    return playersOrignal[1];
}
/*!
 * \brief ReactToTournamentV::setWin
 * Ustaw wygrango i zaktualizuj dane
 * \param win
 */
void ReactToTournamentV::setWin(int win)
{

    if(win>NOGAME&&win<DRAW){

        this->win=win;
        this->changeStatus(win-1);
    }
    else{
        players.at(0)->setFamily(playersOrignal.at(0));
        players.at(1)->setFamily(playersOrignal.at(1));
        mainText->setHtml(players[0]->family()+"<p>vs<p>"+players[1]->family());
    }
}
/*!
 * \brief ReactToTournamentV::getWinner
 * \return  Nazwe wygranego lub "" gdy nikt jeszcze nie wygrał.
 */
QString ReactToTournamentV::getWinner()
{

    return (win>NOGAME&&win<DRAW?playersOrignal[win-1]:"");
}

/*!
 * \brief ReactToTournamentV::setInfo
 * Ustawia nam określone informacje.
 * \param info Info
 */
void ReactToTournamentV::setInfo(QString info)
{
    infoAboutEvent=info;
    update();
}
