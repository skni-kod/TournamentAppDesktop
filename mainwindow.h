#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_playersButton_0_clicked();

    void on_playersButton_1_clicked();

    void on_playersButton_2_clicked();

    void on_playersButton_3_clicked();

    void on_photosButton_0_clicked();

    void on_photosButton_1_clicked();

    void on_photosButton_2_clicked();

    void on_photosButton_3_clicked();

    void on_gameScoreButton_0_clicked();

    void on_gameScoreButton_1_clicked();

    void on_gameScoreButton_2_clicked();

    void on_gameScoreButton_3_clicked();

    void on_tournamentInfoButton_0_clicked();

    void on_tournamentInfoButton_1_clicked();

    void on_tournamentInfoButton_2_clicked();

    void on_tournamentInfoButton_3_clicked();

    void on_editInfoButton_clicked();
=======
    void on_pushButton_clicked();
>>>>>>> Stashed changes

public slots:
    void on_AddPlayerDialogAccepted();
    void on_EditPlayerDialogAccepted();

private:
    bool wereChangesMade = false; //changes value to true if data modifications took place (player added, edited, removed etc.)
    Ui::MainWindow *ui;
    void updateTableWidget();   //updates the table widget with players
};
#endif // MAINWINDOW_H
