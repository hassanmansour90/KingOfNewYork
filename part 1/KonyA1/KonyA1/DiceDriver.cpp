/*#include "Dice.h"
#include "Monsters.h"

using namespace std;

int main()
{

//										ROLL A SINGLE DIE
cout << endl << "This section will create 2 dice, roll them, then display their roll results." << endl;
Dice die1;
Dice die2;
bool rollIt = true;
while (rollIt != false)
{
srand(time(0));
die1.roll();
die2.roll();
rollIt = false;
}

cout << endl << "Die 1: " << die1.getResult() << endl;
cout << endl << "Die 2: " << die2.getResult() << endl;

//											ROLLDICE &  RESOLVE DICE

//1) one can request from 1 to 6 dice being rolled
//2) that the container returns the right symbol of values
//3) that no value outside of the 1 - 6 dice symbols range is ever returned
//4) that there is an equal share of 1 - 6 values returned and
//5)that every dice rolling facility object maintains all individual values rolled up to now.
//NOTE: All these criteria are met in the rollDice() function implemented in Player.cpp
//Dice is a friend class to Player class therefore the player has access to all its members and attributes.

Monsters mons("Drakonis");
Player player1;
player1.setMonster(mons);

cout << endl << "This is an example of all 6 player dice being rolled and resolved for 1 player." << endl;

cout << endl << "Let's roll!" << endl << "Players can roll up to a maximum of 3 rolls per turn." << endl;
cout << endl << player1.getMonsterName() << ": ";
player1.rollDice(player1.getBlDice());





system("pause");
return 0;
}*/