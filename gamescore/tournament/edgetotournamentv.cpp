
#include "edgetotournamentv.h"
#include "reacttotournamentv.h"

#include <QPainter>
#include <QtMath>
#include <QDebug>

/*!
 * \brief EdgeToTournamentV::EdgeToTournamentV
 * Konstruktor
 * \param SourceReactToTournamentV Źródło naszej krawędzi.
 * \param TargetReactToTournamentV Cel naszej krawędzi
 */
EdgeToTournamentV::EdgeToTournamentV(ReactToTournamentV *SourceReactToTournamentV, ReactToTournamentV *TargetReactToTournamentV)
    : source(SourceReactToTournamentV), target(TargetReactToTournamentV)
{
    source->addEdge(this);
    target->addEdge(this);
    calcTheLength();
}
/*!
 * \brief EdgeToTournamentV::calcTheLength
 * Liczenie długości lini
 */
void EdgeToTournamentV::calcTheLength()
{

    QLineF line(mapFromItem(source, 10, 40), mapFromItem(target, 70, 40));
    qreal length = line.length();
    QPointF EdgeToTournamentVOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
    sourcePoint = line.p1() + EdgeToTournamentVOffset;
    destPoint = line.p2() - EdgeToTournamentVOffset;
}
/*!
 * \brief EdgeToTournamentV::getSource
 * \return Źródło
 */
ReactToTournamentV *EdgeToTournamentV::getSource()
{
    return  source;
}
/*!
 * \brief EdgeToTournamentV::getTarget
 * \return Cel
 */
ReactToTournamentV *EdgeToTournamentV::getTarget()
{
    return target;
}
/*!
 * \brief EdgeToTournamentV::boundingRect
 * \return
 */
QRectF EdgeToTournamentV::boundingRect() const
{

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()));
}
/*!
 * \brief EdgeToTournamentV::paint
 * Narysuj linie
 * \param painter
 */
void EdgeToTournamentV::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    QLineF line(sourcePoint, destPoint);

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter->drawLine(line);


}
