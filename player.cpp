#include "player.h"
#include "QDebug"

Player::Player()
{
    ;
}

QString Player::getFirstName()const
{
    return firstName;
}

QString Player::getLastName()const
{
    return lastName;
}

QString Player::getSex() const
{
    return sex;
}
short Player::getRating()const
{
    return rating;
}

short Player::getRang()const
{
    return rang;
}

QString Player::getCategories() const
{
    return categories;
}

QString Player::getCountry() const
{
    return country;
}

QString Player::getClub() const
{
    return club;
}

void Player::setFirstName(QString str)
{
    firstName = str;
}

void Player::setLastName(QString str)
{
    lastName = str;
}

void Player::setSex(bool woman, bool man)
{
    if(woman) sex = "Woman";
    else if(man) sex = "Man";
    else sex = "Unknown";
}

void Player::setSextoBase(QString str)
{
    sex = str;
}
void Player::setRating(short n)
{
    rating = n;
}

void Player::setRang(short n)
{
    rang = n;
}

void Player::setCategories(QString str)
{
    categories = str;
}
void Player::setCountry(QString str)
{
    country = str;
}

void Player::setClub(QString str)
{
    club = str;
}

bool operator<(const Player& a, const Player&b)
{
    return a.rating > b.rating;
}
