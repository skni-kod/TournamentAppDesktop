#include "gallery.h"
#include "QDebug"

void Gallery::arrangeThumbnails()
{
    for(int i = 0; i < thumbnailsCount; i++)
    {
        thumbnails[i].setPos(-100 + 220*i,-100);
    }
}

Gallery::Gallery(){}

void Gallery::load()
{
    galleryScene = new QGraphicsScene;
    thumbnailsCount = 3;
    thumbnails = new GalleryThumbnail[thumbnailsCount];
    QString imagePath;
    for(int i = 0; i < thumbnailsCount; i++)
    {
        imagePath.append("thumbnails/");
        imagePath.append(QString::number(i));
        imagePath.append(".jpg");
        thumbnails[i].setThumbnailImage(imagePath);
        imagePath.clear();
        galleryScene->addItem(&thumbnails[i]);
    }
    this->arrangeThumbnails();
}

QGraphicsScene* Gallery::getScene()
{
    return galleryScene;
}
