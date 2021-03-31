#ifndef EdgeToTournamentV_H
#define EdgeToTournamentV_H

#include <QGraphicsObject>

class ReactToTournamentV;


class EdgeToTournamentV : public QGraphicsObject
{
    Q_OBJECT
public:
    EdgeToTournamentV(ReactToTournamentV *SourceReactToTournamentV, ReactToTournamentV *TargetReactToTournamentV);
    void calcTheLength();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    ReactToTournamentV *source, *target;

    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize = 10;
};


#endif
