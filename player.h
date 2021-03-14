#ifndef PLAYER_H
#define PLAYER_H
#include "QString"


class Player
{
    QString firstName;
    QString lastName;
    QString sex;
    short rating;   //note: the minimum value that can be entered by the user is 0, and the maximum is 30000
    short rang;
    QString categories;
    QString country;
    QString club;
public:
    Player();
    QString getFirstName()const;
    QString getLastName()const;
    QString getSex() const;
    short getRating()const;
    short getRang()const;
    QString getCategories()const;
    QString getCountry()const;
    QString getClub()const;
    void setFirstName(QString str);
    void setLastName(QString str);
    void setSex(bool woman, bool man);
    void setSextoBase(QString str);
    void setRating(short n);
    void setRang(short n);
    void setCategories(QString str);
    void setCountry(QString str);
    void setClub(QString str);
    friend bool operator<(const Player& a, const Player&b); //operator function used for qSort();
};

#endif // PLAYER_H
