
#include "edgetotournamentv.h"
#include "reacttotournamentv.h"
#include "tournamentview.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>


ReactToTournamentV::ReactToTournamentV(TournamentView *graphWidget)
    : graph(graphWidget)
{
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);

    setAcceptHoverEvents(true);
}

void ReactToTournamentV::addEdge(EdgeToTournamentV *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList<EdgeToTournamentV *> ReactToTournamentV::edges() const
{
    return edgeList;
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
    oko=new QString("Hello\n oko");
    painter->setPen(Qt::DotLine);
    painter->setBrush(Qt::NoBrush);
    const QRect rectangle = QRect(40, 40, 80, 80);
    painter->drawText(rectangle,*oko);
    painter->drawRect(0, 0, 80, 80);

}


void ReactToTournamentV::hoverEnterEvent(QGraphicsSceneHoverEvent * event)
{
    if (!coordinateText) {
        coordinateText= std::unique_ptr<QGraphicsTextItem>(new QGraphicsTextItem(this));

        coordinateText->setPlainText("Info about\nevent");
        coordinateText->setPos(2,2);


    }

    coordinateText->setVisible(true);
    update();
    QGraphicsItem::hoverEnterEvent(event);

}

void ReactToTournamentV::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (coordinateText) {
        coordinateText->setVisible(false);

    }
    update();
    QGraphicsItem::hoverEnterEvent(event);
}
