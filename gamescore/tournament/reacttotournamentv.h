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
    void changeStatus(bool player);//przekresl zawodnika[0-1 gracz,1-2 gracz]
    int getId();//id kwadratu
    int getIdSql();//id w tabeli
    int getWin();//kto wygral
    QString getPlayer1();
    QString getPlayer2();
    void setPlayers(QString player1,QString player2);//ustaw imiona zawodnikow
    void setId(int id);
    void setWin(int win);
    void setInfo(QString info);//ustaw info na temat wydarzen
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    static int typid;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;




signals:
    void clicked(int);

private:
     int win=0;
    int idSQL=-1;
    int id=0;
    std::unique_ptr<QGraphicsTextItem>coordinateText;
    std::unique_ptr<QGraphicsTextItem>mainText;
    QList<EdgeToTournamentV *> edgeList;
    QPointF newPos;
    TournamentView *graph;
    QList <QFont*> players={};
    QList <QFont*> playersOrignal={};
    QString infoAboutEvent={};
     QList<EdgeToTournamentV *> edges() const;

};
#endif
