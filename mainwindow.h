#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gallery.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_removeButton_clicked();

    void on_saveButton_clicked();

    void on_restoreButton_clicked();

    void on_playersButton_clicked();

    void on_photosButton_clicked();

    void on_gameScoreButton_clicked();

    void on_tournamentInfoButton_clicked();

    void on_editInfoAboutTButton_clicked();

public slots:
    void on_AddPlayerDialogAccepted();
    void on_EditPlayerDialogAccepted();

private:
    Gallery gallery1;
    bool wereChangesMade = false; //changes value to true if data modifications took place (player added, edited, removed etc.)
    Ui::MainWindow *ui;
    void updateTableWidget();   //updates the table widget with players
};
#endif // MAINWINDOW_H
