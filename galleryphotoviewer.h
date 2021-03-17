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
    explicit GalleryPhotoViewer(unsigned int imageIndex, QString previewImagePath,QWidget *parent = nullptr);
    ~GalleryPhotoViewer();

private slots:
    void on_nextButton_clicked();

    void on_previousButton_clicked();

private:
    Ui::GalleryPhotoViewer *ui;
    QString previewImagePath;
    int imageIndex;
    QPixmap *pixmapImage;
    QGraphicsScene *viewerScene;
};

#endif // GALLERYPHOTOVIEWER_H
