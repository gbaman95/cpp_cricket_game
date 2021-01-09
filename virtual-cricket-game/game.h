#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
//#include<string>
//#include<vector>
#include"team.h"


class Game
{
public:
    Game();
    int playersPerTeam;
    int maxBalls;
    int totalPlayers;
    std::string players[11];


    bool isFirstInnings;
    Team teamA, teamB;
    Team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;
    void welcome();
    void showAllPlayers();
    int takeIntegerInput();
    void selectPlayers();
    bool validateSelectedPlayer(int);
    void displayTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void bat();
    bool validateInningsScore();
    void showGameScorecard();

};


#endif // GAME_H_INCLUDED
