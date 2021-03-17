#include "galleryphotoviewer.h"
#include "ui_galleryphotoviewer.h"
#include "QGraphicsPathItem"
#include "QDebug"

GalleryPhotoViewer::GalleryPhotoViewer(unsigned int imageIndex, QString previewImagePath,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GalleryPhotoViewer)
{
    this->previewImagePath = previewImagePath;
    ui->setupUi(this);
    this->imageIndex = imageIndex;
    QImage image(previewImagePath);
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
    imageIndex++;
    previewImagePath.clear();
    previewImagePath.append("Images/");
    previewImagePath.append(QString::number(imageIndex));
    previewImagePath.append(".jpg");
    QImage image(previewImagePath);
    *pixmapImage = QPixmap::fromImage(image);
    delete viewerScene;
    viewerScene = new QGraphicsScene;
    viewerScene->addPixmap(*pixmapImage);
    ui->graphicsView->setScene(viewerScene);
}

void GalleryPhotoViewer::on_previousButton_clicked()
{
    if(imageIndex > 0)
        imageIndex--;
    previewImagePath.clear();
    previewImagePath.append("Images/");
    previewImagePath.append(QString::number(imageIndex));
    previewImagePath.append(".jpg");
    QImage image(previewImagePath);
    *pixmapImage = QPixmap::fromImage(image);
    delete viewerScene;
    viewerScene = new QGraphicsScene;
    viewerScene->addPixmap(*pixmapImage);
    ui->graphicsView->setScene(viewerScene);
}
