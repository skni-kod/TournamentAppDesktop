#include "galleryphotoviewer.h"
#include "ui_galleryphotoviewer.h"
#include "QGraphicsPathItem"
#include "QDebug"

GalleryPhotoViewer::GalleryPhotoViewer(unsigned int imageIndex, int totalImageCount,QString previewImagePath,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleryPhotoViewer)
{
    this->totalImageCount = totalImageCount;
    this->previewImagePath = previewImagePath;
    ui->setupUi(this);
    this->imageIndex = imageIndex;
    QImage image(previewImagePath);
    fullResImage = image;
    if(image.size().width() > 1280 || image.size().height() > 720) //scalling images down if necessary
        image = image.scaled(1280, 720, Qt::KeepAspectRatio);
    lowResImage = image;
    pixmapImage =  new QPixmap;
    *pixmapImage = QPixmap::fromImage(image);
    viewerScene = new QGraphicsScene;
    viewerScene->addPixmap(*pixmapImage);
    ui->graphicsView->setScene(viewerScene);
}

GalleryPhotoViewer::~GalleryPhotoViewer()
{
    delete ui;
    delete viewerScene;
    delete pixmapImage;
}

void GalleryPhotoViewer::on_nextButton_clicked()
{
    //moving to the next image in gallery
    if(imageIndex < (totalImageCount-1))
    {
        isZoomEnabled = false;
        imageIndex++;
        previewImagePath.clear();
        previewImagePath.append("Images/");
        previewImagePath.append(QString::number(imageIndex));
        previewImagePath.append(".jpg");
        QImage image(previewImagePath);
        fullResImage = image;
        if(image.size().width() > 1280 || image.size().height() > 720)
            image = image.scaled(1280, 720, Qt::KeepAspectRatio);
        lowResImage = image;
        *pixmapImage = QPixmap::fromImage(image);
        delete viewerScene;
        viewerScene = new QGraphicsScene;
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
}

void GalleryPhotoViewer::on_previousButton_clicked()
{
    //moving to the previous image
    if(imageIndex > 0)
    {
        isZoomEnabled = false;
        imageIndex--;
        previewImagePath.clear();
        previewImagePath.append("Images/");
        previewImagePath.append(QString::number(imageIndex));
        previewImagePath.append(".jpg");
        QImage image(previewImagePath);
        fullResImage = image;
        if(image.size().width() > 1280 || image.size().height() > 720)
            image = image.scaled(1280, 720, Qt::KeepAspectRatio);
        lowResImage = image;
        *pixmapImage = QPixmap::fromImage(image);
        delete viewerScene;
        viewerScene = new QGraphicsScene;
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
}

void GalleryPhotoViewer::on_zoomButton_clicked()
{
    isZoomEnabled = !isZoomEnabled;
    if(isZoomEnabled)
    {
        *pixmapImage = QPixmap::fromImage(fullResImage);
        delete viewerScene;
        viewerScene = new QGraphicsScene; //creating a new scene every time someone zooms in or out probably isn't a great idea... but it centers the image
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
    else
    {
       *pixmapImage = QPixmap::fromImage(lowResImage);
        delete viewerScene;
        viewerScene = new QGraphicsScene;
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
}
