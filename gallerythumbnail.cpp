#include "gallerythumbnail.h"
#include "qdebug.h"

GalleryThumbnail::GalleryThumbnail()
{

}

QRectF GalleryThumbnail::boundingRect() const
{
    return QRectF(0,0,200,100);
}

void GalleryThumbnail::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QPointF point1(0,0);
    painter->drawImage(point1, thumbnailImage, rec);
}

void GalleryThumbnail::setThumbnailImage(QString path)
{
    thumbnailImage.load(path);
    thumbnailImage = thumbnailImage.scaled(200,100,Qt::KeepAspectRatio);
}

void GalleryThumbnail::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
    qDebug() << "pressed";
}
