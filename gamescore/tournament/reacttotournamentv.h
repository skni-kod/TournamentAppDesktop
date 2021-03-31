#ifndef reactrorournamentr_H
#define reactrorournamentr_H

#include <QGraphicsObject>
#include <QList>
#include <memory>

class EdgeToTournamentV;
class TournamentView;


class ReactToTournamentV : public  QGraphicsObject
{
    Q_OBJECT
public:
    ReactToTournamentV(TournamentView *graphWidget);
    void addEdge(EdgeToTournamentV *edge);
    QList<EdgeToTournamentV *> edges() const;
    void changeStatus(bool player);
    int getId();
    void setPlayers(QString player1,QString player2);
    void setId(int id);
    int getIdSql();
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    static int typid;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;


    void fillInfoEvent(QList<QString> info);

signals:
    void clicked(int);

private:
    int idSQL=-1;
    int id=0;
    std::unique_ptr<QGraphicsTextItem>coordinateText;
    std::unique_ptr<QGraphicsTextItem>mainText;
    QList<EdgeToTournamentV *> edgeList;
    QPointF newPos;
    TournamentView *graph;
    QList <QFont*> players={};
    QList <QString> infoAboutEvent={};

};
#endif
