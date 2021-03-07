#ifndef PLAYER_H
#define PLAYER_H
#include "QString"


class Player
{
    QString firstName;
    QString lastName;
    short rating;   //note: the minimum value that can be entered by the user is 0, and the maximum is 30000
    short rang;
public:
    Player();
    QString getFirstName()const;
    QString getLastName()const;
    short getRating()const;
    short getRang()const;
    void setFirstName(QString str);
    void setLastName(QString str);
    void setRating(short n);
    void setRang(short n);
    friend bool operator<(const Player& a, const Player&b); //operator function used for qSort();
};

#endif // PLAYER_H
