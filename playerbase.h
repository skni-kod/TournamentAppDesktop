#ifndef PLAYERBASE_H
#define PLAYERBASE_H
#include "QVector"
#include "QFile"
#include "player.h"
#include "QTextStream"
#include "QTableWidgetItem"

//this is a singleton class
class playerBase
{
public:
    inline playerBase(const playerBase&) = delete;
    inline static playerBase& Get()
    {
        return s_Instance;
    }
    ~playerBase();
    void load();    //loads player list from file
    void save();    //saves player list to file
    void add(Player player);    //adds player to playerStorage (a vector used for storing player data)
    void remove(int row);   //removes player from a selected row
    void edit(Player player, int row);  //modifies player data (for some reason doesn't currently work)
    int get_playerCount();  //return the amount of players in playerStorage
    Player get_player(int row); //returns player data from a given row
    QVector<QTableWidgetItem*> itemPlayerStorage;   //stores cell data about players for TableWidget
private:
    inline playerBase() {}
    static playerBase s_Instance;
    QVector<Player> playerStorage;  //stores player data
    void sort();    //sorts playerSorage vector (in descending order)
    int playerCount = 0;    //amount of players in playerStorage vector
};

#endif // PLAYERBASE_H
