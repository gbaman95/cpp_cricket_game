#include"game.h"

using namespace std;
void Game::welcome()
{
    cout<<"\t\t\t\t========CRIC-IN========"<<endl;
    cout<<"\n \n \n "<<endl;
    cout<<"\t\t\t\t=======Instructions======="<<endl;
    cout<<"\n"<<endl;
    cout<<" 1. Create two teams (Team A and Team B with 4 players in each team.) \n 2. Lead the toss and decide the choice of play. \n ";
    cout<<"3. Each innings will be of 6 balls. \n";



}

Game::Game()
{
    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;
    players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

    isFirstInnings = false;
    teamA.name= "Team-A";
    teamB.name = "Team-B";
}
void Game:: showAllPlayers()
{
    cout<<"=========Pool of Players========="<<endl;
    cout<<"\n \n";
    for(int i = 0; i<10;i++)
    {
        cout<<"["<<i<<"]"<<"\t"<<players[i]<<endl;
    }
}
int Game::takeIntegerInput()
{
    int n;
    while(!(cin>>n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
    }
    return n;
}
bool Game::validateSelectedPlayer(int index)
{
    int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
        	return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }

    return true;
}
void Game::selectPlayers()
{
    cout<<"========Create Team A and Team B========="<<"\n \n"<<endl;
    int i=0;
    //Team A
    for(i=0;i<4;i++)
    {
        teamASelection:
        cout<<"Select player "<<i+1<<"\t of Team A -"<<endl;
        int playerIndexTeamA = takeIntegerInput();
        if(playerIndexTeamA<0 || playerIndexTeamA>10)
        {
            cout<<"\n Please select from the given players"<<endl;
            goto teamASelection;
        }
        else if(!validateSelectedPlayer(playerIndexTeamA))
        {
            cout<<"\n Player has already been selected.Please select other player." <<endl;
            goto teamASelection;
        }
        else

        {
            Player teamAPlayer;
            teamAPlayer.id = playerIndexTeamA;
            teamAPlayer.name = players[playerIndexTeamA];
            teamA.players.push_back(teamAPlayer);
        }

    }
    //Team B
    for(i=0;i<4;i++)
    {
        teamBSelection:
        cout<<"Select player "<<i+1<<"\t of Team B -"<<endl;
        int playerIndexTeamB = takeIntegerInput();
         if(playerIndexTeamB<0 || playerIndexTeamB>10)
        {
            cout<<"\n Please select from the given players"<<endl;
            goto teamBSelection;
        }
        else if(!validateSelectedPlayer(playerIndexTeamB))
        {
            cout<<"\n Player has already been selected.Please select other player." <<endl;
            goto teamBSelection;
        }
        else
        {
            Player teamBPlayer;
            teamBPlayer.id = playerIndexTeamB;
            teamBPlayer.name = players[playerIndexTeamB];
            teamB.players.push_back(teamBPlayer);
        }

    }
}

void Game:: displayTeamPlayers()
{
vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}

void Game::toss()
{
    cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "|========== Let's Toss  ==========|" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Tossing the coin..." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2;	// 0 or 1

    switch (randomValue) {
		case 0:
			cout << "Team-A won the toss" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the toss" << endl << endl;
			tossChoice(teamB);
			break;
    }
}
void Game::tossChoice(Team tossWinnerTeam)
{

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game::startFirstInnings()
{
    cout<<"\t \t ||| First Innings Starts |||"<<endl<<endl;
    isFirstInnings = true;
    initializePlayers();
    playInnings();
}

void Game:: initializePlayers()
{
    // Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game:: playInnings()
{
    for (int i=0; i<maxBalls;i++)
    {
        cout<< "Press enter to bowl: "<<endl<<endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        cout<<"Bowling....."<< endl<<endl;
        bat();

        if(!validateInningsScore())
        {
            break;
        }

    }
}

void Game:: bat()
{
    srand(time(NULL));
    int runsScored = rand()%7;
    // Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;
    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];

    }
}

bool Game:: validateInningsScore()
{
   if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}

	} else {	// Else 2nd innings

	}

	return true;
}

void Game:: showGameScorecard()
{
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<battingTeam->name<<"\t"<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketsLost<<"("<< bowlingTeam->totalBallsBowled<<")";
    cout<<"\t\t"<<"|"<<"\t\t"<<batsman->name<<"\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed<<")";
    cout<<"\t\t"<<bowler->name <<"\t"<<bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<< bowler->wicketsTaken<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
}
