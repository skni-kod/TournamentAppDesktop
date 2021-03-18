#include "gallery.h"
#include "QDebug"

void Gallery::arrangeThumbnails()
{
    //creating a pen for generating the thumbnail border
    QPen thumbnailBorderPen;
    thumbnailBorderPen.setColor(Qt::black);
    thumbnailBorderPen.setWidth(1);

    //variables for storing thumbnail width and height
    int witdh;
    int height;
    int xPosAdjustment;

    //moving thumbnails to appropiate positions in the graphicView;
    for(int i = 0,j = 0; i < thumbnailsCount; i++)
    {
        thumbnails[i].setPos(-515 + 245*(i%3),10 + 180*j);
        galleryScene->addRect(-515 + 245*(i%3),10 + 180*j, 220, 165, thumbnailBorderPen);

        witdh = thumbnails[i].getThumbnailWidth();
        if(witdh < 220)
        {
            xPosAdjustment = (220 - witdh)/2;
            thumbnails[i].setThumbnailPoint(xPosAdjustment,0);
        }

        if(i%3 == 2)
            j++;
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
