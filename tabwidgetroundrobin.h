#ifndef TABWIDGETROUNDROBIN_H
#define TABWIDGETROUNDROBIN_H

#include <QTabWidget>
#include <QTableView>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <algorithm>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QVBoxLayout>

namespace Ui {
class TabWidgetRoundRobin;
}

class TabWidgetRoundRobin : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidgetRoundRobin(QWidget *parent = nullptr);
    ~TabWidgetRoundRobin();


private:
    int Numbersofplayers=6;
    Ui::TabWidgetRoundRobin *ui;
    QVector<QTableView> listOfPages;
    void geneSQL();//temp
    QSqlDatabase db;
    void fillingTable();
    QVector< QTableView * > tableView;
    QVector< QSqlQueryModel * > sqlModelToTable;

};

#endif // TABWIDGETROUNDROBIN_H
