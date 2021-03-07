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

short Player::getRating()const
{
    return rating;
}

short Player::getRang()const
{
    return rang;
}

void Player::setFirstName(QString str)
{
    firstName = str;
}

void Player::setLastName(QString str)
{
    lastName = str;
}

void Player::setRating(short n)
{
    rating = n;
}

void Player::setRang(short n)
{
    rang = n;
}

bool operator<(const Player& a, const Player&b)
{
    return a.rating > b.rating;
}
