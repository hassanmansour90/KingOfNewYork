/*#include "Player.h"

using namespace std;

int main()
{
//////									CREATE PLAYERS, CHOOSE AND ASSIGN MONSTERS
cout << "This following creates the players, asks them to choose a monster assigns the monster to them." << endl;

int numPlayers;
cout << "How many people are playing? (Minimum 2 players, Maximum 6 players)" << endl;
cin >> numPlayers;
cout << endl;

while ((numPlayers != 2) && (numPlayers != 3) && (numPlayers != 4) && (numPlayers != 5) && (numPlayers != 6))
{
cout << endl << "That is an invalid entry." << endl
<< "You must enter a valid number between 2-6" << endl;
cin >> numPlayers;
cout << endl;
}
//Here we will eventually call a function that will ask the players to roll a single die
//this die will determine which player goes first
//the players will be inserted into a vector list to keep track of their order

//The following will be implemeneted better with a for loop for the next iteration of the project

Player player1;
Player player2;
Player player3;
Player player4;
Player player5;
Player player6;

if (numPlayers == 2)
{
player1.setPlayerId(1);
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.chooseMonster();
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.displayMonsterStats();

player2.setPlayerId(2);
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.chooseMonster();
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.displayMonsterStats();
cout << endl << "All players have succesfully been created!" << endl;

}
if (numPlayers == 3)
{
player1.setPlayerId(1);
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.chooseMonster();
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.displayMonsterStats();

player2.setPlayerId(2);
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.chooseMonster();
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.displayMonsterStats();

player3.setPlayerId(3);
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.chooseMonster();
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.displayMonsterStats();
cout << endl << "All players have succesfully been created!" << endl;
}
if (numPlayers == 4)
{
player1.setPlayerId(1);
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.chooseMonster();
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.displayMonsterStats();

player2.setPlayerId(2);
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.chooseMonster();
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.displayMonsterStats();

player3.setPlayerId(3);
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.chooseMonster();
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.displayMonsterStats();

player4.setPlayerId(4);
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.chooseMonster();
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.displayMonsterStats();
cout << endl << "All players have succesfully been created!" << endl;

}
if (numPlayers == 5)
{
player1.setPlayerId(1);
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.chooseMonster();
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.displayMonsterStats();

player2.setPlayerId(2);
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.chooseMonster();
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.displayMonsterStats();

player3.setPlayerId(3);
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.chooseMonster();
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.displayMonsterStats();

player4.setPlayerId(4);
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.chooseMonster();
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.displayMonsterStats();

player5.setPlayerId(5);
cout << endl << "Player " << player5.getPlayerId() << ": ";
player5.chooseMonster();
cout << endl << "Player " << player5.getPlayerId() << ": ";
player5.displayMonsterStats();
cout << endl << "All players have succesfully been created!" << endl;
}

if (numPlayers == 6)
{
player1.setPlayerId(1);
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.chooseMonster();
cout << endl << "Player " << player1.getPlayerId() << ": ";
player1.displayMonsterStats();

player2.setPlayerId(2);
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.chooseMonster();
cout << endl << "Player " << player2.getPlayerId() << ": ";
player2.displayMonsterStats();

player3.setPlayerId(3);
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.chooseMonster();
cout << endl << "Player " << player3.getPlayerId() << ": ";
player3.displayMonsterStats();

player4.setPlayerId(4);
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.chooseMonster();
cout << endl << "Player " << player4.getPlayerId() << ": ";
player4.displayMonsterStats();

player5.setPlayerId(5);
cout << endl << "Player " << player5.getPlayerId() << ": ";
player5.chooseMonster();
cout << endl << "Player " << player5.getPlayerId() << ": ";
player5.displayMonsterStats();

player6.setPlayerId(6);
cout << endl << "Player " << player6.getPlayerId() << ": ";
player6.chooseMonster();
cout << endl << "Player " << player6.getPlayerId() << ": ";
player6.displayMonsterStats();
cout << endl << "All players have succesfully been created!" << endl;
}


//										PLAYER OWNS REGION FUNCTION

cout << endl << "This section creates a region, gives ownership a player and display the region they currently own." << endl;
Vertex sampleRegion("Bronx", 2);
player1.setRegion(sampleRegion);
cout << endl << "Player 1 owns: " << player1.getRegion().getName() << endl;

//										PLAYER DICE
cout << endl << "This section asks a player to roll their dice, display dice objects, then resolve them" << endl;
player1.rollDice(player1.getBlDice());

//										OTHER PLAYER FUNCTIONS

cout << endl << "This section is to demonstrate the call to the move() and buyCards() functions." << endl << endl;

player1.move();
player1.buyCards();



//										PLAYER OWNS TOKENS


cout << endl << "This section creates a token of each type, assigns them a player and displays them." << endl;
Web web;
Souvenir souv;
Carapace car;
Jinx jin;
vector <Tokens> tok;
tok.push_back(web);
tok.push_back(souv);
tok.push_back(car);
tok.push_back(jin);

player1.setTokens(tok);

cout << endl << "Player 1:" << endl;
player1.displayTokens();


//											ENEMY CUBES
cout << endl << "This section creates energy cubes and assigns them to a player." << endl;
EnergyCubes enm(100);
player1.setEnergyCubes(enm);
cout << endl << "Player 1: ";
player1.displayCubes();

//											CARDS
cout << endl << "This section creates game cards, assigns them to a player, then displays them." << endl;
LongNeck c1;
TrashThrower c2;
TrophyHuner c3;
StatueOfLiberty c4;
Superstar c5;
vector <Cards> crds;
crds.push_back(c1);
crds.push_back(c2);
crds.push_back(c3);
crds.push_back(c4);
crds.push_back(c5);

player1.setCards(crds);
player1.displayCards();


system("pause");



return 0;

}*/

