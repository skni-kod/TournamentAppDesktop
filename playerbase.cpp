#include "playerbase.h"
#include "QDebug"
#include <algorithm>

//initializing static member
playerBase playerBase::s_Instance;

playerBase::~playerBase()
{
    //freeing memory allocated for tableWidget items
    for(int i = 0; i < playerCount; i++)
        delete itemPlayerStorage[i];
}

void playerBase::load()
{
    //clearing all data and loading unmodified data from file
    for(int i = 0; i < playerCount; i++)
        delete itemPlayerStorage[i];
    itemPlayerStorage.clear();
    playerStorage.clear();
    playerCount = 0;
    //opening file
    QFile dataBase("TempDataBase.txt");
    dataBase.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&dataBase);
    while(!in.atEnd())
    {
        Player tempPlayer;
        //reading one line from file and spliting it into three strings
        //syntax of a given line in the file: player_firstName\tplayer_lastName\tplayer_rating (fields separated by \t)
        QList<QString> playerDataList = in.readLine().split("\t");
        tempPlayer.setFirstName(playerDataList[0]);
        tempPlayer.setLastName(playerDataList[1]);
        tempPlayer.setRating(playerDataList[2].toShort());
        playerStorage.append(tempPlayer);
        playerCount++;
    }
    dataBase.close();
    this->sort();

    //adding players to itemPlayerStorage vector used by tableWidget to display player data
    for(int i = 0; i < playerCount; i++)
    {
        QTableWidgetItem* tempItem;

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getFirstName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getLastName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getRating());
        itemPlayerStorage.append(tempItem);
    }
}

void playerBase::save()
{
    //Opening file
    QFile dataBase("TempDataBase.txt");
    dataBase.open(QFile::WriteOnly | QFile::Text);

    //Writing data to file
    for(int i = 0; i < playerCount; i++)
    {
        QTextStream out(&dataBase);
        out << playerStorage.value(i).getFirstName() << "\t" << playerStorage.value(i).getLastName() <<"\t" << playerStorage.value(i).getRating() <<"\n";
    }
    //Closing the file
    dataBase.flush();
    dataBase.close();

}

void playerBase::add(Player player)
{
    playerStorage.append(player);
    playerCount++;
    this->sort();
    //clearing previous itemPlayerStorage vector and freeing allocated memory
    for(int i = 0; i < (playerCount - 1); i++)
    {
        delete itemPlayerStorage[i];
    }
    itemPlayerStorage.clear();

    //generating new itemPlayerStorage vector based on new sorted data
    for(int i = 0; i < playerCount; i++)
    {
        QTableWidgetItem* tempItem;

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getFirstName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getLastName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getRating());
        itemPlayerStorage.append(tempItem);
    }
}

void playerBase::remove(int row)
{

    playerStorage.remove(row);
    playerCount--;

    this->sort();

    //clearing previous itemPlayerStorage vector and freeing allocated memory
    for(int i = 0; i < (playerCount + 1); i++)
    {
        delete itemPlayerStorage[i];
    }
    itemPlayerStorage.clear();

    //generating new itemPlayerStorage vector based on new sorted data
    for(int i = 0; i < playerCount; i++)
    {
        QTableWidgetItem* tempItem;

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getFirstName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getLastName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getRating());
        itemPlayerStorage.append(tempItem);
    }
}

//for reasons unknown this method doesn't work
void playerBase::edit(Player player, int row)
{
    playerStorage[row].setFirstName(player.getFirstName());
    playerStorage[row].setLastName(player.getLastName());
    playerStorage[row].setRating(player.getRating());
    this->sort();

    //clearing previous player table items
    for(int i = 0; i < (playerCount); i++)
    {
        delete itemPlayerStorage[i];
    }
    itemPlayerStorage.clear();

    //generating new player storage items
    for(int i = 0; i < playerCount; i++)
    {
        QTableWidgetItem* tempItem;

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getFirstName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getLastName());
        itemPlayerStorage.append(tempItem);

        tempItem = new QTableWidgetItem;
        (*tempItem).setData(0, playerStorage.value(i).getRating());
        itemPlayerStorage.append(tempItem);
    }
}

int playerBase::get_playerCount()
{
    return playerCount;
}

Player playerBase::get_player(int row)
{
    Player tempPlayer;
    tempPlayer.setFirstName(playerStorage.value(row).getFirstName());
    tempPlayer.setLastName(playerStorage.value(row).getLastName());
    tempPlayer.setRating(playerStorage.value(row).getRating());
    return tempPlayer;
}

void playerBase::sort()
{
    qSort(playerStorage);
    for(int i = 0; i < playerCount; i++)
    {
        playerStorage.value(i).setRang(i+1);
    }
}
