#include "gallery.h"
#include "QDebug"

void Gallery::arrangeThumbnails()
{
    for(int i = 0,j = 0; i < thumbnailsCount; i++)
    {
        thumbnails[i].setPos(-530 + 210*(i%3),10 + 120*j);
        if(i%3 == 2)
            j++;
        qDebug() << thumbnails[i].pos();
    }
}

Gallery::Gallery(){}

void Gallery::load()
{
    galleryScene = new QGraphicsScene;
    thumbnailsCount = 10;
    thumbnails = new GalleryThumbnail[thumbnailsCount];
    QString imagePath;

    for(int i = 0; i < thumbnailsCount; i++)
    {
        //setting paths for full scale images
        imagePath.append("Images/");
        imagePath.append(QString::number(i));
        imagePath.append(".jpg");
        thumbnails[i].setFullResImagePath(imagePath);
        imagePath.clear();

        //loading thumbnails
        imagePath.append("Images/thumbnails/");
        imagePath.append(QString::number(i));
        imagePath.append(".jpg");
        thumbnails[i].setThumbnailImage(imagePath);
        imagePath.clear();
        galleryScene->addItem(&thumbnails[i]);

        //setting image indexes
        thumbnails[i].setImageIndex(i);
    }

}

QGraphicsScene* Gallery::getScene()
{
    return galleryScene;
}
