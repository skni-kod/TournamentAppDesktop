#include "edgetotournamentv.h"
#include "reacttotournamentv.h"


#ifndef tournamenttiew_H
#define tournamenttiew_H

#include <QGraphicsView>


class TournamentView : public QGraphicsView
{
    Q_OBJECT

public:
    TournamentView(QWidget *parent = nullptr);

protected:


    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:

};


#endif
