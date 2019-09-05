#include "Player.h"

using namespace std;


//CONSTRUCTORS
Player::Player()
{
	playerId;
	monster;
	ownsRegion;
	//energyPoints;
	blackDice;
	greenDice;
	tokens;
	energyCubes;
	cards;

	Dice blackOne;
	Dice blackTwo;
	Dice blackThree;
	Dice blackFour;
	Dice blackFive;
	Dice blackSix;

	blackDice.push_back(blackOne);
	blackDice.push_back(blackTwo);
	blackDice.push_back(blackThree);
	blackDice.push_back(blackFour);
	blackDice.push_back(blackFive);
	blackDice.push_back(blackSix);

	Dice greenOne;
	Dice greenTwo;

	greenDice.push_back(greenOne);
	greenDice.push_back(greenTwo);


	//isTurn = false;
}


/*Eventually when loading from file
Player::Player(int id, Monsters mons, Vertex ownsReg, int nrg, vector <Dice> blDice, vector <Dice> grDice, vector <Cards> crds, vector <Tokens> tok, vector <EnemeyCubes> nme, bool turn)
{
playerId = id;
monster = mons;
ownsRegion = ownsReg;

energyPoints = nrg;
blackDice = blDice;
greenDice = grDice;
tokens = tok;
enemyCubes = nme;
cards = crds;
isTurn = turn;

}*/

// MUTATORS
void Player::setPlayerId(int id)
{
	playerId = id;
}
void Player::setMonster(Monsters mons)
{
	monster = mons;
}
void Player::setLifePoints(int lp)
{
	monster.setLPoints(lp);
}
void Player::setVictoryPoints(int vp)
{
	monster.setVPoints(vp);
}
//void Player::setEnergyPoints(int nrg)
//{
//	energyPoints = nrg;
//}
void Player::setBlDice(vector <Dice> bl)
{
	blackDice = bl;
}
void Player::setGrDice(vector <Dice> gr)
{
	greenDice = gr;
}
void Player::setRegion(Vertex reg)
{
	ownsRegion = reg;
}
void Player::setTokens(vector <Tokens> tok)
{
	tokens = tok;
}
void Player::setEnergyCubes(EnergyCubes nmeCubes)
{
	energyCubes = nmeCubes;
}
void Player::setCards(vector <Cards> crds)
{
	cards = crds;
}


//ACCESSORS
int Player::getPlayerId()
{
	return playerId;
}
Monsters Player::getMonster()
{
	return monster;
}
string Player::getMonsterName()
{
	return monster.getMonsName();
}
int Player::getLifePoints()
{
	return monster.getLPoints();
}
int Player::getVictoryPoints()
{
	return monster.getVPoints();
}
//int Player::getEnergyPoints()
//{
//	return energyPoints;
//}
vector <Dice> Player::getBlDice()
{
	return blackDice;
}
vector <Dice> Player::getGrDice()
{
	return greenDice;
}
Vertex Player::getRegion()
{
	return ownsRegion;
}

vector <Tokens> Player::getTokens()
{
	return tokens;
}
EnergyCubes Player::getEnergyCubes()
{
	return energyCubes;
}
vector <Cards> Player::getCards()
{
	return cards;
}


//										MONSTER RELATED
void Player::chooseMonster()
{
	static vector <string> monstersOptions = { "Captain Fish", "Mantis", "Rob", "Kong", "Drakonis", "Sheriff" };
	int value;
	int size = monstersOptions.size();

	cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << endl << i + 1 << ". " << monstersOptions[i];
	}
	cout << endl;
	cin >> value;

	if (size == 6)
	{
		while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5) && (value != 6))
		{
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number." << endl;
			cin >> value;
			cout << endl;
		}
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
	}
	if (size == 5)
	{
		while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5))
		{
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number." << endl;
			cin >> value;
			cout << endl;
		}
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
	}
	if (size == 4)
	{
		while ((value != 1) && (value != 2) && (value != 3) && (value != 4))
		{
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number." << endl;
			cin >> value;
			cout << endl;
		}
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
	}
	if (size == 3)
	{
		while ((value != 1) && (value != 2) && (value != 3))
		{
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number." << endl;
			cin >> value;
			cout << endl;
		}
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
	}
	if (size == 2)
	{
		while ((value != 1) && (value != 2))
		{
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number." << endl;
			cin >> value;
			cout << endl;
		}
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
	}
	if (size == 1)
	{
		cout << endl << "You will be " << monstersOptions[value - 1] << "!" << endl;

		Monsters mon(monstersOptions[value - 1]);
		setMonster(mon);
	}

}

void Player::displayMonsterStats()
{
	cout << endl << getMonsterName();

	cout << endl << "Life points: ";

	cout << getLifePoints();

	cout << endl << "Victory points: ";

	cout << getVictoryPoints() << endl;
}

//												DICE RELATED

void Player::displayDice(vector <Dice> vDie)
{
	for (size_t i = 0; i < vDie.size(); i++) {
		cout << "Dice " << i + 1 << ": " << vDie[i].getResult() << endl;
	}
}



void Player::rollDice(vector <Dice> vDie)
{
	int rollCount = 1;
	int keepTracker = 0;


	while ((keepTracker != 6) && (rollCount != 4))
	{
		srand(time_t(0));

		cout << endl << endl << "Rolling dice!" << endl;
		cout << endl << "Roll " << rollCount << endl << "You rolled: ";
		for (size_t i = 0; i < vDie.size(); i++)
		{
			if (rollCount == 1)
			{
				vDie[i].roll();
				cout << endl << "Dice " << i + 1 << ": " << vDie[i].getResult();
			}
			else
			{
				if (vDie[i].getRollAgain() == true)
				{
					vDie[i].roll();
					cout << endl << "New roll - Dice " << i + 1 << ": " << vDie[i].getResult();
				}
				if (vDie[i].getRollAgain() == false)
				{
					cout << endl << "Previous roll - Dice " << i + 1 << ": "
						<< vDie[i].getResult();
				}
			}

		}
		cout << endl;


		char input;

		for (size_t i = 0; i < vDie.size(); i++)
		{
			if (rollCount == 3)
			{
				cout << endl << "This was your final roll, therefore you must keep this set of dice." << endl;
				displayDice(vDie);
				cout << endl;
				break;
			}

			cout << endl << "Would you like to keep Dice " << i + 1 << ": " << vDie[i].getResult() << "?";
			cout << endl << "Enter Y or N" << endl << endl;
			cin >> input;


			while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
			{
				cout << endl << "That is an invalid entry." << endl
					<< "Please enter Y or N" << endl << endl;
				cin >> input;
			}

			if ((input == 'y') || (input == 'Y'))
			{
				cout << "Keep - Dice " << i + 1 << ": " << vDie[i].getResult() << endl;
				vDie[i].setRollAgain(false);
				keepTracker++;
			}

			if ((input == 'n') || (input == 'N'))
			{
				cout << "Re-roll - Dice " << i + 1 << ": " << vDie[i].getResult() << endl;
				vDie[i].setRollAgain(true);
			}
		}

		if (keepTracker == 6)
		{
			cout << endl << "You decided to keep all your dice!" << endl << endl;
			displayDice(vDie);
			cout << endl;

			continue;
		}


		rollCount++;
	}
	resolveDice(vDie);
}

void Player::resolveDice(vector <Dice> vDie)
{
	cout << endl << "This is the ResolveDice() function" << endl << endl;
	string res;
	for (size_t i = 0; i < vDie.size(); i++)
	{
		res = vDie[i].getResult();

		if (res == "Energy")
		{
			cout << "Dice " << i + 1 << ": " << res << " - One green cube is obtained for energy you rolled." << endl;
			// make function
		}
		if (res == "Attack")
		{
			cout << "Dice " << i + 1 << ": " << res << " - Lose one heart Point. If you are Mahattan, damages all the monster outside Manhattan. If your are not in Manhattan, amges all the monster on Mahattan" << endl;
		}
		if (res == "Heal")
		{
			cout << "Dice " << i + 1 << ": " << res << " - Gain one lifeline" << endl;
			//can't go over 10 heart points, as well can't gain any lifepoints on Manhattan.
		}
		if (res == "Destruction")
		{
			cout << "Dice " << i + 1 << ": " << res << " - Gain a point to destroy a building" << endl;
		}
		if (res == "Celebrity")
		{
			cout << "Dice " << i + 1 << ": " << res << " - Gain a point to get acess to a superstar card" << endl;
		}
		if (res == "Ouch")
		{
			cout << "Dice " << i + 1 << ": " << res << " - Suffer 1 damage per unit tile on your borough" << endl;
		}
	}
}


void Player::move()
{
	cout << "move() : This function will allow the player to move." << endl;
	/*cout << "You are in " << ownsRegion.getName << endl
	<< "You can move to one of the following cities: " << endl;
	printNeighbors(neighbors);
	cout << endl << "Where would you like to go?" << endl;
	cin >> destination;

	check if valid entry
	check conditions if they can/can't move there*/
}


void Player::buyCards()
{
	cout << "buyCards() : This function will allow the player to buy cards." << endl;
}



//										GAME PIECE RELATED


void Player::displayTokens()
{
	cout << "You have the following tokens: " << endl;
	for (size_t i = 0; i < tokens.size(); i++)
	{
		cout << tokens[i].getTokenName() << endl;
	}
}

void Player::displayCards()
{
	cout << endl << "You have the following cards: " << endl;
	for (size_t i = 0; i < cards.size(); i++)
	{
		cout << "Card: " << cards[i].getCardName() << " - " << "Description: " << cards[i].getHowToPlay() << endl;
	}
}
void Player::displayCubes()
{
	cout << endl << "You have " << getEnergyCubes().getTotal() << " energy cubes." << endl;

}
