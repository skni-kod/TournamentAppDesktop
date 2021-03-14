#include "tournamentinfo.h"

TournamentInfo::TournamentInfo()
{

}

QString TournamentInfo::getTournamentAddress()
{
    return tournamentAddress;
}

QString TournamentInfo::getTournamentDate()
{
    return tournamentDate;
}

qint16 TournamentInfo::getMaxMembersLimit()
{
    return maxMembersLimit;
}

QString TournamentInfo::getMinCategory()
{
    return minCategory;
}

QString TournamentInfo::getMaxCategory()
{
    return maxCategory;
}

float TournamentInfo::getWinPointsAssignment()
{
    return winPointsAssignment;
}

float TournamentInfo::getLosePointsAssignment()
{
    return losePointsAssignment;
}

float TournamentInfo::getDrawPointsAssignment()
{
    return drawPointsAssignment;
}

float TournamentInfo::getByePointsAssignment()
{
    return byePointsAssignment;
}

QString TournamentInfo::getPairingSystem()
{
    return pairingSystem;
}

void TournamentInfo::setTournamentAddress(QString str)
{
    tournamentAddress = str;
}

void TournamentInfo::setTournamentDate(QString str)
{
    tournamentDate = str;
}

void TournamentInfo::setMaxMembersLimit(qint16 number)
{
    maxMembersLimit = number;
}

void TournamentInfo::setMinCategory(QString str)
{
    minCategory = str;
}

void TournamentInfo::setMaxCategory(QString str)
{
    maxCategory = str;
}

void TournamentInfo::setWinPointsAssignment(float points)
{
    winPointsAssignment = points;
}

void TournamentInfo::setLosePointsAssignment(float points)
{
    losePointsAssignment = points;
}

void TournamentInfo::setDrawPointsAssignment(float points)
{
    drawPointsAssignment = points;
}

void TournamentInfo::setByePointsAssignment(float points)
{
    byePointsAssignment = points;
}

void TournamentInfo::setPairingSystem(QString str)
{
    pairingSystem = str;
}
