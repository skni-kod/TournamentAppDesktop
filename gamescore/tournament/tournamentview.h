#include "edgetotournamentv.h"
#include "reacttotournamentv.h"
#include "gamescore/tournament/editevent/dialogtournamentview.h"
#include <QSqlDatabase>
#include <QSqlQuery>

#ifndef tournamenttiew_H
#define tournamenttiew_H

#include <QGraphicsView>


class TournamentView : public QGraphicsView
{
    Q_OBJECT

public:
    TournamentView(QWidget *parent = nullptr);

protected:

    void wheelEvent(QWheelEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    //void mousePressEvent(QMouseEvent *event)override;

private:
    QSqlDatabase db;
    QVector <ReactToTournamentV *> react;
    DialogTournamentView * dialogedit;
    int IdManaged=-1;;

private slots:
    void ShowContextMenu(QPoint);
    void fillTheLeader();
private slots:
    void refresh();
};


#endif
/*TO DO
 * ai
 * correct editing of an event
 * fix the scene
 *
*/
