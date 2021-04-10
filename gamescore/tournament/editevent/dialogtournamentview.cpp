#include "dialogtournamentview.h"
#include "ui_dialogtournamentview.h"
#include <QRadioButton>
/*!
 * \brief The Status enum
 */
enum Status{NOGAME=0,WIN_PLAYER2=2,WIN_PLAYER1=1,DRAW=3};
/*!
 * \brief DialogTournamentView::DialogTournamentView
 * \param parent
 */
DialogTournamentView::DialogTournamentView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTournamentView),buttonGroup(new QButtonGroup(this))
{
    ui->setupUi(this);
    buttonGroup->addButton(ui->radioButton,WIN_PLAYER1);
    buttonGroup->addButton(ui->radioButton_3,DRAW);
    buttonGroup->addButton(ui->radioButton_2,WIN_PLAYER2);


    connect(ui->radioButton,&QRadioButton::clicked,this,[&](){win=WIN_PLAYER1;});
    connect(ui->radioButton_2,&QRadioButton::clicked,this,[&](){win=WIN_PLAYER2;});
    connect(ui->radioButton_3,&QRadioButton::clicked,this,[&](){win=DRAW;});
    // connect(buttonGroup,&QButtonGroup::buttonClicked,this,[&](int id){win=id;});
}
/*!
 * \brief DialogTournamentView::~DialogTournamentView
 */
DialogTournamentView::~DialogTournamentView()
{
    delete ui;
}
/*!
 * \brief DialogTournamentView::setDb
 * \param temp Baza danych
 * \param id Id naszego kwadrau
 */
void DialogTournamentView::setDb(QSqlDatabase *temp,int id)

{
    ID=id;
    this->db=temp;
    if(db->open()){
        QSqlQuery query("SELECT * FROM tabela12",*db);
        query.exec();
        query.seek(ID,false);
        QString player1 = query.value("graczjeden").toString();
        QString player2 = query.value("graczdwa").toString();
        QString info = query.value("info").toString();



        QAbstractButton* checked = buttonGroup->checkedButton();
        if (checked)
        {
            buttonGroup->setExclusive(false);
            checked->setChecked(false);
            buttonGroup->setExclusive(true);
        }



        ui->lineEdit->setText(player1);
        ui->lineEdit_2->setText(player2);
        ui->lineEdit_3->setText(info);
    }
}

/*!
 * \brief DialogTournamentView::on_buttonBox_accepted
 * W przypadku kliknięcia zaktualizuj dane i emituj sygnał.
 */
void DialogTournamentView::on_buttonBox_accepted()
{
    if(db->open()){
        QSqlQuery query("SELECT * FROM tabela12",*db);
        query.exec();
        query.seek(ID,false);
        QString player1 = query.value("graczjeden").toString();
        QString player2 = query.value("graczdwa").toString();
        QString info = query.value("info").toString();
        int wynik = query.value("wynik").toInt();

        QString fromLine[2]={ui->lineEdit->text(),ui->lineEdit_2->text()};
        QString fromLineInfo=ui->lineEdit_3->text();

        if(player1!=fromLine[0]||player2!=fromLine[1]||fromLineInfo!=info||wynik!=win){
            QSqlQuery querytemp(*db);

            querytemp.prepare("UPDATE tabela12 SET graczjeden=:one,graczdwa=:two,info=:info,wynik=:w WHERE id=:ID");
            querytemp.bindValue(":one",fromLine[0]);
            querytemp.bindValue(":two",fromLine[1]);
            querytemp.bindValue(":info",fromLineInfo);
            querytemp.bindValue(":w",win);
            querytemp.bindValue(":ID",ID+1);
            querytemp.exec();
        }

        fromLine->clear();
        info.clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();

        emit clicked();
    }


}