#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addplayerdialog.h"
#include "modifyplayerdialog.h"
#include "editinfoaboutdialog.h"
#include "tournamentinfo.h"
#include "playerbase.h"
#include "QMessageBox"
#include "QDebug"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->playersButton_0->setStyleSheet("background-color: rgb(46, 46, 46); color: rgb(255,255,255);");
    ui->photosButton_1->setStyleSheet("background-color: rgb(46, 46, 46); color: rgb(255,255,255);");
    ui->gameScoreButton_2->setStyleSheet("background-color: rgb(46, 46, 46); color: rgb(255,255,255);");
    ui->tournamentInfoButton_3->setStyleSheet("background-color: rgb(46, 46, 46); color: rgb(255,255,255);");
    //block resize
    this->statusBar()->setSizeGripEnabled(false);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);


    //setting up the tableWidget
    ui->tableWidget->setColumnCount(7);
    //creating horizontal labels
    QStringList labels;
    labels.append("First Name");
    labels.append("Last Name");
    labels.append("Sex");
    labels.append("Rating");
    labels.append("Categories");
    labels.append("Country");
    labels.append("Club");
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //this disables edit of cells in the table
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);   //changing selection behavior (whole row will be selected instead of individual cells)
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //only one item can be selected

    //loading players from file
    playerBase::Get().load();

    //updating the tableWidget
    this->updateTableWidget();
//gamescore
    roundrobin=new TabWidgetRoundRobin(this);
    tournament=new TournamentView(this);
    ui->verticalLayout->addWidget(roundrobin);
    ui->horizontalLayout_16->addWidget((tournament));
    ui->stackedWidget_2->setCurrentIndex(1);
    //will be error cuz widgets conne,in the future we will connect only once after logging in
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    //handling player addition
    AddPlayerDialog addDialog1;
    addDialog1.setModal(true);
    connect(&addDialog1, SIGNAL(accepted()), this, SLOT(on_AddPlayerDialogAccepted()));
    if(addDialog1.exec() == QDialog::Accepted)
        wereChangesMade = true;
}

void MainWindow::on_editButton_clicked()
{
    if(ui->tableWidget->currentRow() == -1)
    {
        QMessageBox messageBox1(QMessageBox::Information, "No player selected", "No player selected");
        messageBox1.exec();
        return;
    }
    //handling player edit
    ModifyPlayerDialog modifyPlayerDialog1;
    modifyPlayerDialog1.setModal(true);
    modifyPlayerDialog1.setSelectedRow(ui->tableWidget->currentRow());
    modifyPlayerDialog1.fillLineEdits();
    connect(&modifyPlayerDialog1, SIGNAL(accepted()), this, SLOT(on_EditPlayerDialogAccepted()));
    if(modifyPlayerDialog1.exec() == QDialog::Accepted)
        wereChangesMade = true;
}

void MainWindow::on_EditPlayerDialogAccepted()
{
    this->updateTableWidget();
}

void MainWindow::on_AddPlayerDialogAccepted()
{
    this->updateTableWidget();
}

void MainWindow::on_removeButton_clicked()
{
    //displaying an error message if no player is selected
    if(ui->tableWidget->currentRow() == -1)
    {
        QMessageBox messageBox1(QMessageBox::Information, "No player selected", "No player selected");
        messageBox1.exec();
        return;
    }
    int decision;
    //asking the user whether he is sure that he wants to delete the player from the data base
    QMessageBox messageBox2(QMessageBox::Warning, "Player deletion","Do you want to remove selected player?", QMessageBox::Yes | QMessageBox::No);
    messageBox2.setDefaultButton(QMessageBox::No);
    decision = messageBox2.exec();
    if(decision == QMessageBox::Yes)
    {
        playerBase::Get().remove(ui->tableWidget->currentRow());
        this->updateTableWidget();
        wereChangesMade = true;
    }
}

void MainWindow::on_saveButton_clicked()
{
    playerBase::Get().save();
    wereChangesMade = false;
}

void MainWindow::on_restoreButton_clicked()
{
    int decision = 0;
    QMessageBox messageBox1(QMessageBox::Warning, "Restoring data", "Restoring the database will remove all unsaved modifications. Do you want to continue?",
                            QMessageBox::Yes | QMessageBox::No);
    if(wereChangesMade)
        decision = messageBox1.exec();
    if (decision == QMessageBox::Yes)
    {
        playerBase::Get().load();
        this->updateTableWidget();
        wereChangesMade = false;
    }
}

void MainWindow::updateTableWidget()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(playerBase::Get().get_playerCount());
    int i = 0;
    int j = 0;
    while(j < playerBase::Get().get_playerCount())
    {
        ui->tableWidget->setItem(j,0,playerBase::Get().itemPlayerStorage.value(i));
        ui->tableWidget->setItem(j,1,playerBase::Get().itemPlayerStorage.value(i+1));
        ui->tableWidget->setItem(j,2,playerBase::Get().itemPlayerStorage.value(i+2));
        ui->tableWidget->setItem(j,3,playerBase::Get().itemPlayerStorage.value(i+3));
        ui->tableWidget->setItem(j,4,playerBase::Get().itemPlayerStorage.value(i+4));
        ui->tableWidget->setItem(j,5,playerBase::Get().itemPlayerStorage.value(i+5));
        ui->tableWidget->setItem(j,6,playerBase::Get().itemPlayerStorage.value(i+6));
        i+=7;
        j++;
    }
}


//this function is responsible for Edit Info button
void MainWindow::on_editInfoAboutTButton_clicked()
{
    //handling player addition
    EditInfoAboutDialog editAboutDialog;
    editAboutDialog.setModal(true);
    connect(&editAboutDialog, SIGNAL(accepted()), this, SLOT(on_EditPlayerDialogAccepted()));
    if(editAboutDialog.exec() == QDialog::Accepted)
        wereChangesMade = true;
}


//these functions handle movement between pages in the UI (there are 4 pages, each contain 4 button ("Player", "Game Score", "Tournament Info", "Photos"))
void MainWindow::on_playersButton_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_playersButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_playersButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_playersButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_photosButton_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_photosButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_photosButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_photosButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_gameScoreButton_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gameScoreButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gameScoreButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_gameScoreButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tournamentInfoButton_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tournamentInfoButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tournamentInfoButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tournamentInfoButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
