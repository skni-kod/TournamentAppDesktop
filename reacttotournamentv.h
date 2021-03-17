#ifndef reactrorournamentr_H
#define reactrorournamentr_H

#include <QGraphicsItem>
#include <QList>
#include <memory>

class EdgeToTournamentV;
class TournamentView;


class ReactToTournamentV : public QGraphicsItem
{
public:
    ReactToTournamentV(TournamentView *graphWidget);

    void addEdge(EdgeToTournamentV *edge);
    QList<EdgeToTournamentV *> edges() const;



    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
     std::unique_ptr<QGraphicsTextItem>coordinateText;
signals:
    void hovered();

private:
    QList<EdgeToTournamentV *> edgeList;
    QPointF newPos;
    TournamentView *graph;
    QString *oko;
};


#endif
