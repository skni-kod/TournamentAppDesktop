#ifndef GALLERY_H
#define GALLERY_H
#include "gallerythumbnail.h"
#include "QGraphicsScene"


class Gallery
{
    int thumbnailsCount;    //amount of images in the gallery
    GalleryThumbnail *thumbnails;
    QGraphicsScene *galleryScene;
    void arrangeThumbnails();
public:
    Gallery();
    void load();
    QGraphicsScene* getScene();
};

#endif // GALLERY_H
