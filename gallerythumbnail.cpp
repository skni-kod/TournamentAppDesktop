#include "gallerythumbnail.h"
#include "qdebug.h"

GalleryThumbnail::GalleryThumbnail()
{
    thumbnailPoint.setX(0);
    thumbnailPoint.setY(0);
}

QRectF GalleryThumbnail::boundingRect() const
{
    return QRectF(0,0,220,165);
}

void GalleryThumbnail::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    painter->drawImage(thumbnailPoint, thumbnailImage, rec);
}

void GalleryThumbnail::setThumbnailImage(QString path)
{
    thumbnailImage.load(path);
    thumbnailImage = thumbnailImage.scaled(220,165,Qt::KeepAspectRatio);
}

void GalleryThumbnail::setFullResImagePath(QString path)
{
    fullResImagePath = path;
}

void GalleryThumbnail::setImageIndex(unsigned int index)
{
    imageIndex = index;
}

int GalleryThumbnail::getThumbnailWidth()
{
    return thumbnailImage.size().width();
}

int GalleryThumbnail::getThumbnailHeight()
{
    return thumbnailImage.size().height();
}

void GalleryThumbnail::setThumbnailPoint(qreal x, qreal y)
{
    thumbnailPoint.setX(x);
    thumbnailPoint.setY(y);
    update();
}

void GalleryThumbnail::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    GalleryPhotoViewer viewer1(imageIndex,fullResImagePath);
    viewer1.exec();
}
