#ifndef GALLERYPHOTOVIEWER_H
#define GALLERYPHOTOVIEWER_H

#include <QDialog>
#include "QGraphicsScene"

namespace Ui {
class GalleryPhotoViewer;
}

class GalleryPhotoViewer : public QDialog
{
    Q_OBJECT

public:
    explicit GalleryPhotoViewer(unsigned int imageIndex, int totalImageCount,QString previewImagePath,QWidget *parent = nullptr);
    ~GalleryPhotoViewer();

private slots:
    void on_nextButton_clicked();

    void on_previousButton_clicked();

    void on_zoomButton_clicked();

private:
    Ui::GalleryPhotoViewer *ui;
    QString previewImagePath; //path to the currently displayed image
    int imageIndex; //displayed image index
    QImage fullResImage; //full resolution copy of the displayed image
    QImage lowResImage; //720p copy of the displayed image (default displayed image size)
    QPixmap *pixmapImage;
    bool isZoomEnabled = false; //zoom flag
    QGraphicsScene *viewerScene;
    int totalImageCount; //total amount of images in gallery
};

#endif // GALLERYPHOTOVIEWER_H
