#ifndef TOURNAMENTINFO_H
#define TOURNAMENTINFO_H
#include "QString"

class TournamentInfo
{
    QString tournamentAddress;
    QString tournamentDate;
    qint16 maxMembersLimit;
    QString minCategory;
    QString maxCategory;
    float winPointsAssignment;
    float losePointsAssignment;
    float drawPointsAssignment;
    float byePointsAssignment;
    QString pairingSystem;

public:
    TournamentInfo();
    QString getTournamentAddress();
    QString getTournamentDate();
    qint16 getMaxMembersLimit();
    QString getMinCategory();
    QString getMaxCategory();
    float getWinPointsAssignment();
    float getLosePointsAssignment();
    float getDrawPointsAssignment();
    float getByePointsAssignment();
    QString getPairingSystem();

    void setTournamentAddress(QString str);
    void setTournamentDate(QString str);
    void setMaxMembersLimit(qint16 number);
    void setMinCategory(QString str);
    void setMaxCategory(QString str);
    void setWinPointsAssignment(float points);
    void setLosePointsAssignment(float points);
    void setDrawPointsAssignment(float points);
    void setByePointsAssignment(float points);
    void setPairingSystem(bool roundRubin, bool other);
};

#endif // TOURNAMENTINFO_H
