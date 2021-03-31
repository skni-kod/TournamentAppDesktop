QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addplayerdialog.cpp \
#    dialogtournamentview.cpp \
#    edgetotournamentv.cpp \
    editinfoaboutdialog.cpp \
#    gamescore/roundrobin/tabwidgetroundrobin.cpp \
#    gamescore/tournament/edgetotournamentv.cpp \
#    gamescore/tournament/editevent/dialogtournamentview.cpp \
#    gamescore/tournament/reacttotournamentv.cpp \
#    gamescore/tournament/tournamentview.cpp \
    gamescore/roundrobin/tabwidgetroundrobin.cpp \
    gamescore/tournament/edgetotournamentv.cpp \
    gamescore/tournament/editevent/dialogtournamentview.cpp \
    gamescore/tournament/reacttotournamentv.cpp \
    gamescore/tournament/tournamentview.cpp \
    main.cpp \
    mainwindow.cpp \
    modifyplayerdialog.cpp \
    player.cpp \
    playerbase.cpp \
#    reacttotournamentv.cpp \
#    tabwidgetroundrobin.cpp \
    tournamentinfo.cpp \
#    tournamentview.cpp

HEADERS += \
    addplayerdialog.h \
#    dialogtournamentview.h \
#    edgetotournamentv.h \
    editinfoaboutdialog.h \
#    gamescore/roundrobin/tabwidgetroundrobin.h \
#    gamescore/tournament/edgetotournamentv.h \
#    gamescore/tournament/editevent/dialogtournamentview.h \
#    gamescore/tournament/reacttotournamentv.h \
#    gamescore/tournament/tournamentview.h \
    gamescore/roundrobin/tabwidgetroundrobin.h \
    gamescore/tournament/edgetotournamentv.h \
    gamescore/tournament/editevent/dialogtournamentview.h \
    gamescore/tournament/reacttotournamentv.h \
    gamescore/tournament/tournamentview.h \
    mainwindow.h \
    modifyplayerdialog.h \
    player.h \
    playerbase.h \
#    reacttotournamentv.h \
#    tabwidgetroundrobin.h \
    tournamentinfo.h \
#    tournamentview.h

FORMS += \
    addplayerdialog.ui \
    dialogtournamentview.ui \
    editinfoaboutdialog.ui \
    mainwindow.ui \
    modifyplayerdialog.ui \
    tabwidgetroundrobin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
