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
    if(image.size().width() > 1280 || image.size().height() > 720)
        image = image.scaled(1280, 720, Qt::KeepAspectRatio);
    pixmapImage =  new QPixmap;
    *pixmapImage = QPixmap::fromImage(image);
    viewerScene = new QGraphicsScene;
    viewerScene->addPixmap(*pixmapImage);
    ui->graphicsView->setScene(viewerScene);
}

GalleryPhotoViewer::~GalleryPhotoViewer()
{
    delete ui;
}

void GalleryPhotoViewer::on_nextButton_clicked()
{
    if(imageIndex < (totalImageCount-1))
    {
        imageIndex++;
        previewImagePath.clear();
        previewImagePath.append("Images/");
        previewImagePath.append(QString::number(imageIndex));
        previewImagePath.append(".jpg");
        QImage image(previewImagePath);
        if(image.size().width() > 1280 || image.size().height() > 720)
            image = image.scaled(1280, 720, Qt::KeepAspectRatio);
        *pixmapImage = QPixmap::fromImage(image);
        delete viewerScene;
        viewerScene = new QGraphicsScene;
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
}

void GalleryPhotoViewer::on_previousButton_clicked()
{
    if(imageIndex > 0)
    {
        imageIndex--;
        previewImagePath.clear();
        previewImagePath.append("Images/");
        previewImagePath.append(QString::number(imageIndex));
        previewImagePath.append(".jpg");
        QImage image(previewImagePath);
        if(image.size().width() > 1280 || image.size().height() > 720)
            image = image.scaled(1280, 720, Qt::KeepAspectRatio);
        *pixmapImage = QPixmap::fromImage(image);
        delete viewerScene;
        viewerScene = new QGraphicsScene;
        viewerScene->addPixmap(*pixmapImage);
        ui->graphicsView->setScene(viewerScene);
    }
}
