#include <iostream>
#include"game.h"


using namespace std;

int main()
{
    Game game;
    game.welcome();
    cout << "Press Enter to Continue";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    game.showAllPlayers();
    cout << "Press Enter to Continue";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    game.selectPlayers();
    game.displayTeamPlayers();
     cout << "Press Enter to toss";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

    game.toss();
    game.startFirstInnings();


    return 0;
}
