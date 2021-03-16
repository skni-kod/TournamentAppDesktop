#ifndef GALLERYTHUMBNAIL_H
#define GALLERYTHUMBNAIL_H
#include "QGraphicsItem"
#include "QPainter"
#include "QPointF"


class GalleryThumbnail : public QGraphicsItem
{
public:
    GalleryThumbnail();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setThumbnailImage(QString path);
    QImage thumbnailImage;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GALLERYTHUMBNAIL_H
