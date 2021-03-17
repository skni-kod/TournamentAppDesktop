#include "tournamentview.h"
#include <math.h>
#include <QKeyEvent>
#include <QRandomGenerator>


TournamentView::TournamentView(QWidget *parent)
    : QGraphicsView(parent)
{

    int temp=8;
    int hight=80;
    int weight=80;
    int mul=ceil(temp/2.0);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, -0, mul*2*hight, 2*temp*weight);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    scale(qreal(1), qreal(1));
    setMinimumSize(300, 300);
    QVector <ReactToTournamentV *> react;
    for(int i=0,step=1;i<mul;i++,step*=2){

        for(int j=0;j<temp/step;j++){

            react.push_back(new ReactToTournamentV(this));
            scene->addItem(react.last());
            react.last()->setPos(i*2*hight,2*temp*weight-((step*80)+160*step*(j)));
        }}

    for(int i=0,step=1,krok=0,moment=temp;i<mul-1;i++,step*=2){
        for(int j=0;j<temp/step;j++,krok++){

            if(krok%2==0&&krok!=0){
                if(((temp/step)%2!=0)&&(j+1)==temp/step)continue;
                else moment++;
            }scene->addItem(new EdgeToTournamentV(react.at(krok),react.at(moment)));
        }


    }}


void TournamentView::drawBackground(QPainter *painter, const QRectF &rect)
{

    QRectF sceneRect = this->sceneRect();

    painter->setBrush(Qt::NoBrush);
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Turniej nr.xxx"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);

}


