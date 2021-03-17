#ifndef EdgeToTournamentV_H
#define EdgeToTournamentV_H

#include <QGraphicsItem>

class ReactToTournamentV;


class EdgeToTournamentV : public QGraphicsItem
{
public:
    EdgeToTournamentV(ReactToTournamentV *SourceReactToTournamentV, ReactToTournamentV *TargetReactToTournamentV);
    void adjust();
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
