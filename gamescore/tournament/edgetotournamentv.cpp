
#include "edgetotournamentv.h"
#include "reacttotournamentv.h"

#include <QPainter>
#include <QtMath>
#include <QDebug>


EdgeToTournamentV::EdgeToTournamentV(ReactToTournamentV *SourceReactToTournamentV, ReactToTournamentV *TargetReactToTournamentV)
    : source(SourceReactToTournamentV), target(TargetReactToTournamentV)
{
    source->addEdge(this);
    target->addEdge(this);
    calcTheLength();
}

void EdgeToTournamentV::calcTheLength()
{

    QLineF line(mapFromItem(source, 10, 40), mapFromItem(target, 70, 40));
    qreal length = line.length();
    QPointF EdgeToTournamentVOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
    sourcePoint = line.p1() + EdgeToTournamentVOffset;
    destPoint = line.p2() - EdgeToTournamentVOffset;
}

ReactToTournamentV *EdgeToTournamentV::getSource()
{
    return  source;
}

ReactToTournamentV *EdgeToTournamentV::getTarget()
{
    return target;
}

QRectF EdgeToTournamentV::boundingRect() const
{

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()));
}

void EdgeToTournamentV::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QLineF line(sourcePoint, destPoint);

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter->drawLine(line);


}
