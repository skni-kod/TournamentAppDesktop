#ifndef GALLERYTHUMBNAIL_H
#define GALLERYTHUMBNAIL_H
#include "QGraphicsItem"
#include "QPainter"
#include "QPointF"
#include "galleryphotoviewer.h"


class GalleryThumbnail : public QGraphicsItem
{
public:
    GalleryThumbnail();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setThumbnailImage(QString path);
    void setFullResImagePath(QString path);
    void setImageIndex(unsigned int index);
protected:
    QImage thumbnailImage;
    QString fullResImagePath;
    unsigned int imageIndex;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GALLERYTHUMBNAIL_H
