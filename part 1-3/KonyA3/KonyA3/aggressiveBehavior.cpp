
#include "aggressiveBehavior.h"
#include <iostream>
class Player;
class Map;
using namespace std;

aggressiveBehavior::aggressiveBehavior()
{
}

void aggressiveBehavior::setFirstPosition(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "choose region");
	vector<Vertex> regionsVisited = p->getRegionsVisited(myMap->getPlayers());
	vector<int> regAvail = myMap->graph.availableRegions(regionsVisited);
	for (int i = 0; i < regAvail.size(); i++)
	{
		cout << "(" << regAvail.at(i) << ") ";
		for (int j = 0; j < myMap->graph.regions.size(); j++)
		{
			if (myMap->graph.regions.at(j).getID() == regAvail.at(i))
			{
				//cout << myMap->regions.at(j).getNameByID(regAvail.at(i)) << endl;
				cout << myMap->graph.regions.at(j).getName();
				break;
			}
		}
	}
	int destination;
	bool wrongNumber = true;
	do {
		//cin >> destination;
		for (int i = 0; i < regAvail.size(); i++)
		{
			destination = regAvail[i];
			if (destination == regAvail.at(i))
			{
				wrongNumber = false;
			}
		}
		if (wrongNumber) {
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number" << endl;
		}
	} while (wrongNumber);
	p->setRegion(myMap->graph.findVertexById(destination));
	myMap->graph.visitNodeFirstTime(destination);
}
void aggressiveBehavior::chooseMonster(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "choose monster");
	vector <Monsters*> mnstr = myMap->getMonsters();
	static vector <string> monstersOptions = { "Drakonis", "Mantis", "Rob", "Sheriff", "Kong", "Captain Fish" };
	int value;
	string name;
	size_t size = monstersOptions.size();

	if (size == 6)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		//dont need this for aggressive player
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5) && (value != 6))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 5)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 4)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 3)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		/*while ((value != 1) && (value != 2) && (value != 3))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 2)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		/*while ((value != 1) && (value != 2))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 1)
	{
		cout << endl << "You will be " << monstersOptions[0] << "!" << endl;
		name = monstersOptions[0];
		for (int i = 0; i < mnstr.size(); i++)
		{
			if (name == mnstr[i]->getMonsName())
				p->setMonster(mnstr[i]);
		}
		//setMonster(mnstr[value - 1]);
		//monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
}
//            DICE RELATED

void aggressiveBehavior::rollDice(Player* p)
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	NotifyPhase(p->getPlayerId(), "roll dice");
	int rollCount = 1;
	int keepTracker = 0;
	char input = NULL;
	while ((keepTracker != 6) && (rollCount != 4))
	{
		//srand(time_t(0));
		//player observer here?
		cout << endl << endl << "**ROLLING DICE**" << endl;
		cout << endl << "Roll " << rollCount << endl << "You rolled: ";
		for (size_t i = 0; i < p->blackDice.size(); i++)
		{
			if (rollCount == 1)
			{
				p->blackDice[i].roll();
				cout << endl << "Dice " << i + 1 << ": " << p->blackDice[i].getResult();
			}
			else
			{
				if (p->blackDice[i].getRollAgain() == true)
				{
					p->blackDice[i].roll();
					cout << endl << "New roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult();
				}
				if (p->blackDice[i].getRollAgain() == false)
				{
					cout << endl << "Previous roll - Dice " << i + 1 << ": "
						<< p->blackDice[i].getResult();
				}
			}
		}
		cout << endl;


		for (size_t i = 0; i < p->blackDice.size(); i++)
		{
			if (rollCount == 3)
			{
				cout << endl << "This was your final roll, therefore you must keep this set of dice." << endl;
				displayDice(p);
				cout << endl;
				break;
			}
			cout << endl << "Would you like to keep Dice " << i + 1 << ": " << p->blackDice[i].getResult() << "?";
			cout << endl << "Enter Y or N" << endl << endl;
			if ((p->blackDice[i].getResult() == "Attack") || (p->blackDice[i].getResult() == "Destruction"))
			{
				input == 'y';
				cout << endl << "Y";
				cout << endl << "Keep - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
				p->blackDice[i].setRollAgain(false);
				keepTracker++;
			}
			else
			{
				input == 'n';
				cout << endl << "N";
				cout << endl << "Re-roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
				p->blackDice[i].setRollAgain(true);
			}
			/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
			{
			cout << endl << "That is an invalid entry." << endl
			<< "Please enter Y or N" << endl << endl;
			cin >> input;
			}*/
			/*if ((input == 'y') || (input == 'Y'))
			{
			cout << "Keep - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
			p->blackDice[i].setRollAgain(false);
			keepTracker++;
			}*/
			/*if ((input == 'n') || (input == 'N'))
			{
			cout << "Re-roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
			p->blackDice[i].setRollAgain(true);
			}*/
		}
		if (keepTracker == 6)
		{
			cout << endl << "You decided to keep all your dice!" << endl << endl;
			displayDice(p);
			cout << endl;
			continue;
		}

		rollCount++;
	}
	//return vDie;
}

void aggressiveBehavior::resolveDice(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "resolve dice");
	vector <Player*> plVect = myMap->players;
	cout << endl << "***RESOLVE YOUR DICE***" << endl;
	string res;
	cout << endl << "**DICE EFFECTS**" << endl;
	cout << "Energy - One green cube is obtained for energy you rolled." << endl;
	cout << "Attack - Lose one heart Point.If you are Mahattan, damages all the monster outside Manhattan.If your are not in Manhattan, amges all the monster on Mahattan" << endl;
	cout << "Heal - Gain one lifeline" << endl;
	cout << "Destruction - Gain a point to destroy a building" << endl;
	cout << "Celebrity - Gain a point to get acess to a superstar card" << endl;
	cout << "Ouch! - Suffer 1 damage per unit tile on your borough" << endl;
	int energyCount = 0, attackCount = 0, healCount = 0, desCount = 0, celebCount = 0, ouchCount = 0;
	char input;
	for (size_t i = 0; i < p->blackDice.size(); i++)
	{
		res = p->blackDice[i].getResult();
		if (res == "Energy")
			energyCount++;
		if (res == "Attack")
			attackCount++;
		if (res == "Heal")
			healCount++;
		//can't go over 10 heart points, as well can't gain any lifepoints on Manhattan.
		if (res == "Destruction")
			desCount++;
		if (res == "Celebrity")
			celebCount++;
		if (res == "Ouch")
			ouchCount++;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < p->cards.size(); i++) {
		string cardname = p->cards.at(i).getCardName();
		if (cardname == "Stomp") {
			desCount++;
		}
		if (cardname == "Overload") {
			int points = p->getEnergyPoints();
			points++;
			p->setEnergyPoints(points);
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool allResolved = false;
	cout << endl << "**MONSTER STATS**";
	p->displayMonsterStats();
	p->displayCards();
	p->displayCubes();
	cout << endl << "**YOUR DICE**" << endl;
	cout << "DICE TYPE # OF DICE" << endl;
	if (energyCount != 0)
		cout << "Energy Dice:  " << energyCount << endl;
	if (attackCount != 0)
		cout << "Attack Dice:  " << attackCount << endl;
	if (desCount != 0)
		cout << "Destruction Dice: " << desCount << endl;
	if (healCount != 0)
		cout << "Heal Dice:  " << healCount << endl;
	if (celebCount != 0)
		cout << "Celebrity Dice:  " << celebCount << endl;
	if (ouchCount != 0)
		cout << "Ouch! Dice:  " << ouchCount << endl;

	while (allResolved == false)
	{
		cout << endl << "Which dice would you like to resolve?" << endl
			<< "Enter 'E' for Energy, 'A' for Attack, 'D' for Destruction, 'H' for Heal, 'C' for Celebrity or 'O' for Ouch!" << endl;
		//cin >> input;
		if (attackCount != 0)
		{
			input = 'a';
			cout << endl << "A";
		}
		if (desCount != 0)
		{
			input = 'd';
			cout << endl << "D";
		}
		if (healCount != 0)
		{
			input = 'h';
			cout << endl << "H";
		}
		if (energyCount != 0)
		{
			input = 'e';
			cout << endl << "E";
		}
		if (ouchCount != 0)
		{
			input = 'o';
			cout << endl << "O";
		}
		if (celebCount != 0)
		{
			input = 'c';
			cout << endl << "C";
		}
		/*while ((input != 'e') && (input != 'E') && (input != 'a') && (input != 'A') && (input != 'd') && (input != 'D') && (input != 'h') && (input != 'H') && (input != 'c') && (input != 'C') && (input != 'o') && (input != 'O'))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "Enter 'E' for Energy, 'A' for Attack, 'D' for Destruction, 'H' for Heal, 'C' for Celebrity or 'O' for Ouch!" << endl;
		cin >> input;
		cout << endl;
		}*/
		///////////////////////////////////////////////////////////////////////////////////////////////////////////
		string cardname;
		int cardEffect = 0;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (input)
		{
		case 'e': case 'E':
			if (energyCount == 0)
			{
				cout << "You do not have any Energy dice." << endl;
				break;
			}
			//DONE
			cout << endl << "ENERGY!" << endl;
			addEnergy(p, energyCount);
			p->displayCubes();
			energyCount = 0;
			break;
		case 'a': case 'A':
			if (p->getFirstTurn() == true)
			{
				cout << endl << "You cannot attack on the first turn, these dice will have no effect." << endl;
			}
			if (p->getFirstTurn() != true)
			{
				if (attackCount == 0)
				{
					cout << "You do not have any Attack dice." << endl;
					break;
				}
				//if monster is in manhattan, inflict damage on all other players NOT in manhattan
				cout << endl << "ATTACK!" << endl;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < p->cards.size(); i++)
				{
					cardname = p->cards.at(i).getCardName();
					if (cardname == "TrashThrower")
					{
						cardEffect = 1;
						p->setVictoryPoints(p->getVictoryPoints() - 1);
					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////////
				if (p->getRegion().getName().find("Zone") != string::npos)
				{
					int plcount = 0;
					//vector <Player*> plVect = p->myMap->getPlayers();
					cout << endl << p->getMonsterName() << " you are in Manhattan, therefore you will attack every monster outside of Manhattan." << endl;
					for (int i = 0; i < plVect.size(); i++)
					{
						if (plVect[i]->getRegion().getName().find("Zone") == string::npos)
						{
							if (plVect[i]->getRegion().getName() != "Manhattan")
							{
								int points = plVect[i]->getLifePoints();
								////////////////////////////////////////////////////////////////////////////////////////////
								for (int j = 0; j < plVect[j]->cards.size(); i++)
								{
									//int points = plVect[j]->getLifePoints();//
									string aCard = plVect[j]->cards.at(j).getCardName();
									if (aCard == "Drain")
									{
										plVect[j]->setEnergyPoints(plVect[j]->getEnergyPoints() + 2);
									}
									//points = points - (attackCount);////////////////////////////////////////////////////////////////
									//plVect[j]->setLifePoints(points);//
								}
								////////////////////////////////////////////////////////////////////////////////////////////
								points = points - (attackCount);////////////////////////////////////////////////////////////////
								plVect[i]->setLifePoints(points);
								if (plVect[i]->getMonsterName() != p->getMonsterName())
								{
									cout << plVect[i]->getMonsterName() << ": -" << attackCount
										<< " : " << plVect[i]->getLifePoints() << " life points remaining" << endl;
								}
								plcount++;
							}
						}
						if (plcount == 0)
							cout << endl << "There are no other players currently in Manhattan." << endl;
					}
					//}
					//if monster is not in manhattan AND there are monsters in manhattan, inflict damage on monsters in manhattan
					//if (p->getRegion().getName().find("Zone") == string::npos)
				}
				else
				{
					int plcount = 0;
					cout << endl << p->getMonsterName() << " You are not in Manhattan, therefore you will attack every monster inside of Manhattan." << endl;
					for (int i = 0; i < myMap->getPlayers().size(); i++)
					{
						if (plVect[i]->getRegion().getName().find("Zone") == string::npos)
						{
							if (plVect[i]->getRegion().getName() == "Manhattan")
							{
								int points = plVect[i]->getLifePoints();//
																		////////////////////////////////////////////////////////////////////////////////////////////
								for (int j = 0; j < plVect[j]->cards.size(); i++)
								{
									//int points = plVect[j]->getLifePoints();//
									string aCard = plVect[j]->cards.at(j).getCardName();
									if (aCard == "Drain")
									{
										plVect[j]->setEnergyPoints(plVect[j]->getEnergyPoints() + 2);
									}
									//points = points - (attackCount);////////////////////////////////////////////////////////////////////////////
									//plVect[j]->setLifePoints(points);
								}
								////////////////////////////////////////////////////////////////////////////////////////////
								//int points = plVect[i]->getLifePoints();
								points = points - (attackCount);////////////////////////////////////////////////////////////////////////////
								plVect[i]->setLifePoints(points);
								if (plVect[i]->getMonsterName() != p->getMonsterName())
								{
									cout << plVect[i]->getMonsterName() << ": -" << attackCount
										<< " : " << plVect[i]->getLifePoints() << " life points remaining" << endl;
								}
								plcount++;
							}
						}
					}
					if (plcount == 0)
						cout << endl << "There are no monsters in Manhattan." << endl;
					//}

				}
			}
			attackCount = 0;
			break;

		case 'h': case 'H':
			if (healCount == 0)
			{
				cout << "You do not have any Heal dice." << endl;
				break;
			}
			cout << endl << "HEAL!" << endl;
			//if player is NOT in manhattan AND lifepoints!=10,  lifepoints++
			if ((p->getRegion().getName().find("Zone") == string::npos) || (p->getLifePoints() != 10))
			{
				//if monster lifepoints ==10, cout << "You are already at max life points";

				if (p->getLifePoints() == 10)
				{
					cout << endl << "You are already at maximum health!" << endl
						<< "(You cannot go over the 10 life point maximum)" << endl;
				}
				else
				{
					int lifePoints = p->getLifePoints() + healCount;
					p->setLifePoints(lifePoints);
					if (p->getLifePoints() > 10)
					{
						int life = p->getLifePoints() - 10;
						p->setLifePoints(p->getLifePoints() - life);
						cout << endl << "You have reached maximum health!" << endl
							<< "(You cannot go over the 10 life point maximum)" << endl;
					}
				}
				cout << endl << "You have " << p->getLifePoints() << " life points." << endl;
			}
			//if monster is in manhattan, cout << "You cannot increase lifepoint when you are in manhattan";
			if ((p->getRegion().getName().find("Zone") != string::npos))
			{
				cout << endl << p->getMonsterName() << " you are in Manhattan, therefore you cannot increase life points!" << endl;
			}
			healCount = 0;
			break;
		case 'c': case 'C':
			if (celebCount == 0)
			{
				cout << "You do not have any Celebrity dice." << endl;
				break;
			}
			cout << endl << "CELEBRITY!" << endl;
			//if celebCount less than 3 AND has no superstar card, nothing happens
			if ((celebCount < 3) && (p->getSuperStar() == false))
			{
				cout << endl << "You have less than 3 celebrity dice, therefore these dice perform no actions." << endl;
			}
			//if has superstar Card, celebCount *= 2;
			if (p->getSuperStar() == true)
			{
				int victoryPoints = p->getVictoryPoints() + (celebCount * 2);
				p->setVictoryPoints(victoryPoints);
				cout << endl << "You currently posses the Superstar Card, therefore for every Celebrity Dice you roll you get double the victory points!" << endl;
				cout << endl << "You have " << p->getVictoryPoints() << " victory points." << endl;
			}
			//if celebCount >= 3 AND has no superstarCard, take superstar card
			if ((celebCount >= 3) && (p->getSuperStar() == false))
			{
				for (int i = 0; i < plVect.size(); i++)
				{
					if (plVect[i]->getSuperStar() == true)
					{
						plVect[i]->setSuperStar(false);
						cout << endl << plVect[i]->getMonsterName() << " looses the Superstar Card!" << endl;
					}
				}
				p->setSuperStar(true);
				int celCount = celebCount - 3;
				int victoryPoints = p->getVictoryPoints() + (celCount * 2);
				p->setVictoryPoints(victoryPoints);
				cout << endl << "You took possesion of the Superstar Card!" << endl
					<< "This will double your victory points for every Celebrity Dice you roll in your future turns" << endl
					<< "[Cost of Superstar Card = 3 Celebrity Dice, all remaining dice (X 2) are added to your victory points]" << endl;
				cout << endl << "You have " << p->getVictoryPoints() << " victory points." << endl;
			}
			celebCount = 0;
			break;
		case 'o': case 'O':
			if (ouchCount == 0)
			{
				cout << "You do not have any Ouch! dice." << endl;
				break;
			}
			cout << endl << "OUCH!" << endl;
			//getMilitaryUnitTiles() in borough player is in (getRegion())
			// for each military unit tile in the region, -1 lifepoint
			if ((p->getRegion().getUnits().size() == 0))
			{
				cout << endl << "There are no unit tiles in this region to be destroyed." << endl;
			}
			if ((p->getRegion().getUnits().size() != 0))
			{
				if (ouchCount == 1)
				{
					int damage = p->getRegion().getUnits().size();
					int lifePoints = p->getLifePoints() - damage;
					p->setLifePoints(lifePoints);
					cout << endl << "Only " << p->getMonsterName() << " looses life points!" << endl;
					cout << endl << p->getMonsterName() << ": ";
					cout << endl << "- " << p->getLifePoints() << " life points!" << endl;
					p->displayMonsterStats();
				}
				//getMilitaryUnitTiles() in borough player is in (getRegion())
				//for each military unit tile in the region, -1 lifepoint from all players in the region
				//for loop through player vector, pl[i].getRegion()
				//if region is == to the region current player is in
				//pl[i].getLifepoints(), lifepoints -1 for each military unit tile in borough
				if (ouchCount == 2)
				{
					cout << endl << "All monsters suffer damage from the military units in their region!" << endl;
					int damage = p->getRegion().getUnits().size();
					int life;
					for (int i = 0; i < plVect.size(); i++)
					{
						life = plVect[i]->getLifePoints() - damage;
						plVect[i]->setLifePoints(life);
						cout << endl << p->getMonsterName() << ": ";
						cout << endl << "- " << life << " life points!" << endl;
						plVect[i]->displayMonsterStats();
					}
				}
				//if ouchCount == 3
				//all players get attacked by the military unit tiles in their borough
				//-1 lifepoint for each unit tile in the players bourough
				// player becomes defender of the city
				//player obtains statueOfLibertyCard
				//+3 celebrity
				if (ouchCount == 3)
				{
					cout << endl << "All monsters suffer damage from all military units!" << endl;
					int damage = 0;
					for (int j = 0; j < myMap->graph.regions.at(j).getUnits().size(); j++)
					{
						damage = damage + myMap->graph.regions.at(j).getUnits().size();
					}
					int life;
					for (int i = 0; i < plVect.size(); i++)
					{
						life = plVect[i]->getLifePoints() - damage;
						plVect[i]->setLifePoints(life);
						cout << endl << "- " << life << " life points!" << endl;
						plVect[i]->displayMonsterStats();
					}
					if (p->getStatue() == false)
					{
						p->setStatue(true);
						int lifePoints = p->getLifePoints() + 3;
						p->setLifePoints(lifePoints);
						cout << endl << "You took posseion of the Statue Of Liberty Card!" << endl;
						if (p->getLifePoints() > 10)
						{
							int life = p->getLifePoints() - 10;
							p->setLifePoints(p->getLifePoints() - life);
							cout << endl << "You have reached maximum health!" << endl
								<< "(You cannot go over the 10 life point maximum)" << endl;
						}
						cout << endl << "+ " << life << " life points!" << endl;
						p->displayMonsterStats();
					}
					if (p->getStatue() == true)
					{
						int lifePoints = p->getLifePoints() + 3;
						p->setLifePoints(lifePoints);
						cout << endl << "You currently have the Statue Of Liberty Card!" << endl;
						if (p->getLifePoints() > 10)
						{
							int life = p->getLifePoints() - 10;
							p->setLifePoints(p->getLifePoints() - life);
							cout << endl << "You have reached maximum health!" << endl
								<< "(You cannot go over the 10 life point maximum)" << endl;
						}
						cout << endl << "+ " << life << " life points!" << endl;
						p->displayMonsterStats();
					}
				}
			}
			ouchCount = 0;
			break;

case 'd': case 'D':
	//desCount = 0; //destruction tiles still needs to be fixed
	if (desCount <= 0)
	{
		cout << "You do not have any Destruction dice." << endl;
	}
	else
	{
		if (desCount > 0)
		{
			int canDorE = 0; //can destroy or eleminate any tile?
			for (int i = 0; i < myMap->graph.regions.size(); i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (desCount >= myMap->graph.regions.at(i).tiles.at(j).back()->getDurability())
					{
						canDorE++;
					}
				}
			}
			if (canDorE == 0)
			{
				cout << "You can't destroy any available building with the number of destruction dice you have!" << endl;
				cout << endl << "Your destruction dice are useless, sorry!\n" << endl;
			}
			/*You can use DES to destroy Buildings or eliminate Units. The Durability of a Building or Unit indicates the number of
			you have to roll in order to destroy it on your turn. When you apply as many Destruction points as the Unit or
			Building's durability, it is destroyed, and you earn as many (for High-Rises or Tanks), (for Power Plants or Jets), or (for
			Hospitals or Infantries) as indicated on the tile. When you destroy a Building, turn it over to its Unit side, and
			place it in the same borough. If there are still Buildings in the stack, this will reveal a new one, and you can even destroy it
			immediately if you have enough remaining. When you destroy a Unit, take it and put it in front of you. You cannot destroy a Unit on the
			same turn that it appears. If you have enough to destroy a Building or a Unit, you must to do so; however you are not
			required to optimize your*/
			else
			{
				while (desCount > 0)
				{
					cout << endl << "DESTRUCTION!" << endl;
					cout << endl << "Which region would you like to attack?" << endl
						<< "'M' for Manhattan\n'X' for Brooklyn\n'S' for Staten-Island\n'Q' for Queens\n'Y' for Bronx" << endl;
					//cin >> input;
					/*while (!(input == 'm') && !(input == 'M') && !(input == 'x') && !(input == 'X') && !(input == 'y') && !(input == 'Y') && !(input == 's') && !(input == 'S') && !(input == 'q') && !(input == 'Q'))
					{
					cout << endl << "That is an invalid entry." << endl
					<< "Please enter 'M' for Manhattan, 'X' for Brooklyn, 'S' for Staten-Island, 'Q' for Queens, 'Y' Bronx" << endl << endl;
					cin >> input;
					}*/
					//input = 'm'; // always automatically choose manhattan
					//for (int i = 0; i < myMap->graph.regions.size(); i++) // go through all regions
					//{
					bool selectAgain = true;
					while (selectAgain == true)
					{
						int count = 0; ////////////////////////////////////////////////////////
						for (int j = 0; j < 3; j++)// check all region stacks
						{
							if ((myMap->graph.regions.at(4).tiles.at(j).size() != 0) || (myMap->graph.regions.at(4).getUnits().size() != 0))
							{
								if (myMap->graph.regions.at(4).tiles.at(j).back()->getDurability() <= desCount)
								{
									count++;
								}
								else
								{
									for (int i = 0; i < myMap->graph.regions.at(4).getUnits().size(); i++)
									{
										if (myMap->graph.regions.at(4).getUnits().at(i).getDurability() <= desCount)
										{
											count++;
										}
									}
								}
							}
							if (count > 0) {
								input = 'm';
								//cout << endl << "M" << endl;
								selectAgain = false;
							}
							else
							{
								if ((myMap->graph.regions.at(3).tiles.at(j).size() != 0) || (myMap->graph.regions.at(3).getUnits().size() != 0))
								{
									if (myMap->graph.regions.at(3).tiles.at(j).back()->getDurability() <= desCount)
									{
										count++;
									}
									else
									{
										for (int i = 0; i < myMap->graph.regions.at(3).getUnits().size(); i++)
										{
											if (myMap->graph.regions.at(3).getUnits().at(i).getDurability() <= desCount)
											{
												count++;
											}
										}
									}
								}
								if (count > 0) {
									input = 'x';
									//cout << endl << "M" << endl;
									selectAgain = false;
								}
								else
								{
									if ((myMap->graph.regions.at(2).tiles.at(j).size() != 0) || (myMap->graph.regions.at(2).getUnits().size() != 0))
									{
										if (myMap->graph.regions.at(2).tiles.at(j).back()->getDurability() <= desCount)
										{
											count++;
										}
										else
										{
											for (int i = 0; i < myMap->graph.regions.at(2).getUnits().size(); i++)
											{
												if (myMap->graph.regions.at(2).getUnits().at(i).getDurability() <= desCount)
												{
													count++;
												}
											}
										}
									}
									if (count > 0) {
										input = 's';
										//cout << endl << "M" << endl;
										selectAgain = false;
									}
									else
									{
										if ((myMap->graph.regions.at(1).tiles.at(j).size() != 0) || (myMap->graph.regions.at(1).getUnits().size() != 0))
										{
											if (myMap->graph.regions.at(1).tiles.at(j).back()->getDurability() <= desCount)
											{
												count++;
											}
											else
											{
												for (int i = 0; i < myMap->graph.regions.at(1).getUnits().size(); i++)
												{
													if (myMap->graph.regions.at(1).getUnits().at(i).getDurability() <= desCount)
													{
														count++;
													}
												}
											}
										}
										if (count > 0) {
											input = 'q';
											//cout << endl << "M" << endl;
											selectAgain = false;
										}
										else
										{
											if ((myMap->graph.regions.at(0).tiles.at(j).size() != 0) || (myMap->graph.regions.at(0).getUnits().size() != 0))
											{
												if (myMap->graph.regions.at(0).tiles.at(j).back()->getDurability() <= desCount)
												{
													count++;
												}
												else
												{
													for (int i = 0; i < myMap->graph.regions.at(0).getUnits().size(); i++)
													{
														if (myMap->graph.regions.at(0).getUnits().at(i).getDurability() <= desCount)
														{
															count++;
														}
													}
												}
											}
											if (count > 0) {
												input = 'y';
												//cout << endl << "M" << endl;
												selectAgain = false;
											}
											else
											{
												cout << endl << "You don't have enough dice to destroy any buildings or units." << endl;
												desCount = 0;
											}
										}

									}
								}
							}
						}
						cout << endl << input << endl;
					}

					if ((input == 'm') || (input == 'M'))
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							if (myMap->graph.regions.at(i).getName() == "Manhattan")
							{
								cout << endl << "You chose Manhattan!" << endl;
								p->setRegionId(i);
							}
						}
					}
					if ((input == 'x') || (input == 'X'))
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							if (myMap->graph.regions.at(i).getName() == "Brooklyn")
							{
								cout << endl << "You chose Brooklyn!" << endl;
								p->setRegionId(i);
							}
						}
					}
					if ((input == 'y') || (input == 'Y'))
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							if (myMap->graph.regions.at(i).getName() == "Bronx")
							{
								cout << endl << "You chose Bronx!" << endl;
								p->setRegionId(i);
							}
						}
					}
					if ((input == 'q') || (input == 'Q'))
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							if (myMap->graph.regions.at(i).getName() == "Queens")
							{
								cout << endl << "You chose Queens!" << endl;
								p->setRegionId(i);
							}
						}
					}
					if ((input == 's') || (input == 'S'))
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							if (myMap->graph.regions.at(i).getName() == "Staten-Island")
							{
								cout << endl << "You chose Staten-Island!" << endl;
								p->setRegionId(i);
							}
						}
					}
					cout << "\nTo destroy a building enter \"b\", to eliminate a unit enter \"u\": ";
					int canDestroyOrEleminate = 0;
					string choice;
					//cin >> choice;
					int stackTrack = 0;
					selectAgain = true;
					while (selectAgain == true)
					{
						for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).tiles.size(); j++)
						{
							if ((myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0))
							{
								stackTrack++;
							}
						}
						if ((myMap->graph.regions.at(p->getRegionId()).getUnits().size() != 0) && (stackTrack == 0)) //no stack, yes units
						{
							choice = 'u';
							cout << endl << "U" << endl;
							selectAgain == false;
							break;
						}
						else if (((myMap->graph.regions.at(p->getRegionId()).getUnits().size() == 0) && (stackTrack >= 0))) // no units, yes stacks
						{
							choice = 'b';
							cout << endl << "B" << endl;
							selectAgain == false;
							break;
						}
						else
						{
							cout << endl << "There are no buildings or units to destroy in this region." << endl
								<< "Please select another region." << endl;
							selectAgain == true;
							break;
						}
					}
					/*while (!(choice == "b") && !(choice == "B") && !(choice == "u") && !(choice == "U"))
					{
					cout << "\nTo destroy a building enter \"b\", to eleminate a unit enter \"u\": ";
					cin >> choice;
					}*/
					//int check[3];

					if (choice == "b" || choice == "B") {
						for (int j = 0; j < 3; j++)
						{
							if (desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability())
							{
								canDestroyOrEleminate++;
							}
						}
						if (canDestroyOrEleminate == 0) {
							cout << "Sorry, you can't destroy any building here with the number of destruction dice you have!" << endl;
							cout << endl << "Please choose another region to attack!\n" << endl;
						}
						else {
							cout << endl << "These are the buildings you can destroy with the number of Destruction Dice you have on " << myMap->graph.regions.at(p->getRegionId()).getName() << ": \n" << endl;
							int check[3]; // to check if there is available buildings a player can destroy in that specific region
							for (int j = 0; j < 3; j++)
							{
								if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() == 0)
								{
									cout << endl << "Stack " << j + 1 << ": " << "There are no more buildings to destroy!" << endl;
									check[j] = 1;
								}

								if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0)
								{
									if (desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability())
									{
										cout << endl << "Stack number \"" << j + 1 << "\": " << myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getName();
									}
									else {
										cout << endl << "Stack number \"" << j + 1 << "\": " << "you can't destroy its buildings (it requires more destruction dices than you have!)";
										check[j] = 1;
									}
								}
							}
							//choose building they want to destroy
							int in;
							cout << endl << "Please select the building you'd like to destroy( enter its number):" << endl << endl;
							//cin >> in;
							in = 1;
							/*while (!(in == 1) && !(in == 2) && !(in == 3))
							{
							cout << endl << "That is an invalid entry." << endl
							<< "Please enter '1', '2' or '3'" << endl << endl;
							cin >> in;
							}*/
							while (check[in - 1] == 1)
							{
								cout << "Sorry, this is an empty stack, choose another!";
								//cin >> in;
								in++;
							}
							Tiles* ptr;
							//iterate through vector of vector of tiles
							if (desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability())
							{
								//Tiles temp;
								cout << endl << "You destroyed: " << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
								ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();

								//award players
								if (ptr->name == "High Rise")
								{
									//high rise, 1 durability, 1 victory point
									if (ptr->getDurability() == 1)
									{
										desCount = desCount - (ptr->getDurability());

										int points = p->getVictoryPoints() + 1;
										p->setVictoryPoints(points);
										cout << endl << " + 1 victory points!";
										//p->displayMonsterStats();
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
										//desCount = desCount - (ptr->getDurability());
										if (desCount <= 0)
										{
											desCount = 0;
											p->setDestroy(false);
										}
										ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
										myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
										cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
										cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();

										/*desCount = desCount - (ptr.getDurability());
										if (desCount <= 0)
										{
										desCount = 0;
										p->setDestroy(false);
										}*/
									}
									else {
										//high rise, 2 durability, 2 victory point
										if (ptr->getDurability() == 2)
										{
											desCount = desCount - (ptr->getDurability());
											int points = p->getVictoryPoints() + 2;
											p->setVictoryPoints(points);
											cout << endl << " + 2 victory points!" << endl;
											p->displayMonsterStats();
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
											//desCount = desCount - (ptr->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
											myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
											cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
											cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
											/*desCount = desCount - (ptr.getDurability());
											if (desCount <= 0)
											{
											desCount = 0;
											p->setDestroy(false);
											}*/
										}
										//high rise, 3 durability, 3 victory point
										else {
											if (ptr->getDurability() == 3)
											{
												desCount = desCount - (ptr->getDurability());
												int points = p->getVictoryPoints() + 3;
												p->setVictoryPoints(points);
												cout << endl << " + 3 victory points!" << endl;
												p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());
												if (desCount <= 0)
												{
													desCount = 0;
													p->setDestroy(false);
												}
												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												/*desCount = desCount - (ptr.getDurability());
												if (desCount <= 0)
												{
												desCount = 0;
												p->setDestroy(false);
												}*/
											}
										}
									}
								}
								if (ptr->name == "Factory")
								{
									//factory, 2 durability, 2 energy point
									if (ptr->getDurability() == 2)
									{
										desCount = desCount - (ptr->getDurability());
										addEnergy(p, 2);
										cout << endl << " + 2 energy cubes!" << endl;
										cout << endl << "You have " << p->getEnergyPoints() << " energy cubes." << endl;
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
										//desCount = desCount - (ptr->getDurability());
										if (desCount <= 0)
										{
											desCount = 0;
											p->setDestroy(false);
										}
										ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
										myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
										/*desCount = desCount - (ptr.getDurability());
										if (desCount <= 0)
										{
										desCount = 0;
										p->setDestroy(false);
										}*/
									}
									//factory, 3 durability, 3 energy point
									else {
										if (ptr->getDurability() == 3)
										{
											desCount = desCount - (ptr->getDurability());
											addEnergy(p, 3);
											cout << endl << " + 3 energy cubes!" << endl;
											cout << endl << "You have " << p->getEnergyPoints() << " energy cubes." << endl;
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
											//desCount = desCount - (ptr->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
											myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
											/*desCount = desCount - (ptr.getDurability());
											if (desCount <= 0)
											{
											desCount = 0;
											p->setDestroy(false);
											}*/
										}
									}
								}
								if (ptr->name == "Hospital")
								{
									//hospital, 2 durability, 2 life point
									if (ptr->getDurability() == 2)
									{
										desCount = desCount - (ptr->getDurability());
										int points = p->getLifePoints() + 2;
										p->setLifePoints(points);
										cout << endl << " + 2 life points!" << endl;
										if (p->getLifePoints() > 10)
										{
											int life = p->getLifePoints() - 10;
											p->setLifePoints(p->getLifePoints() - life);
											cout << endl << "You have reached maximum health!" << endl
												<< "(You cannot go over the 10 life point maximum)" << endl;
										}
										p->displayMonsterStats();
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
										//desCount = desCount - (ptr->getDurability());
										if (desCount <= 0)
										{
											desCount = 0;
											p->setDestroy(false);
										}
										ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
										myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
										myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
										/*desCount = desCount - (ptr.getDurability());
										if (desCount <= 0)
										{
										desCount = 0;
										p->setDestroy(false);
										}*/
									}
									//hospital, 3 durability, 3 victory point
									else {
										if (ptr->getDurability() == 3)
										{
											desCount = desCount - (ptr->getDurability());
											int points = p->getLifePoints() + 3;
											p->setLifePoints(points);
											cout << endl << " + 3 life points!" << endl;
											if (p->getLifePoints() > 10)
											{
												int life = p->getLifePoints() - 10;
												p->setLifePoints(p->getLifePoints() - life);
												cout << endl << "You have reached maximum health!" << endl
													<< "(You cannot go over the 10 life point maximum)" << endl;
											}
											p->displayMonsterStats();
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
											//desCount = desCount - (ptr->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
											myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
											myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
											/*desCount = desCount - (ptr.getDurability());
											if (desCount <= 0)
											{
											desCount = 0;
											p->setDestroy(false);
											}*/
										}
									}
								}

								//minus durability from total number or destruction dice
								//desCount = desCount - (ptr->getDurability());
								//if (desCount == 0)
								// setDestroy(false);
								//myMap->graph.regions.at(i).tiles.at(j).at(0)->setFlipCheck(true);
								//ptr->setFlipCheck(true);
								//flip tile
								//if (ptr->getFlipCheck() == true)
								//ptr->ReverseTile();
								//assign to unit vector
								//myMap->graph.regions.at(i).setUnits(ptr);
								//remove tile from old vector
								//myMap->graph.regions.at(i).tiles.at(j).pop_back();
							}
						}
					}
					else {
						if (choice == "u" || choice == "U") {
							int canEliminate = 0;
							if (myMap->graph.regions.at(p->getRegionId()).getUnits().size() == 0) {
								cout << "Sorry, there are NO units to eliminate!" << endl;
							}
							else
							{
								for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++) {
									if (desCount >= myMap->graph.regions.at(p->getRegionId()).getUnits().at(j).getDurability())
									{
										canEliminate++;
									}
								}
								if (canDestroyOrEleminate = 0)
									cout << "Sorry, you can't eliminate any Unit here with the number of destruction dice you have!" << endl;
								else {
									cout << endl << "These are the units you can eliminate with the number of Destruction Dice you have on " << myMap->graph.regions.at(p->getRegionId()).getName() << ": \n" << endl;
									for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++)
									{
										cout << endl << "Stack number \"" << j + 1 << "\": " << myMap->graph.regions.at(p->getRegionId()).getUnits().at(j).getName() << endl;
									}
									//choose unit they want to eleminate
									int countU = myMap->graph.regions.at(p->getRegionId()).getUnits().size();
									int inU;
									int displayNumU = 0;
									cout << endl << "Please select the unit you'd like to eliminate (enter its number):" << endl << endl;
									//cin >> inU;
									inU = 1;
									while (inU<1 || inU>myMap->graph.regions.at(p->getRegionId()).getUnits().size())
									{
										cout << endl << "Please select the unit you'd like to eleminate (enter its number):" << endl << endl;
										inU++;
									}
									Tiles* ptrU;
									//iterate through vector of vector of tiles
									if (desCount >= myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1).getDurability())
									{
										//Tiles temp;
										cout << endl << "You eliminated: " << myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1).getName();
										ptrU = &myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1);

										//award players
										if (ptrU->name == "Jet")
										{
											desCount = desCount - (ptrU->getDurability());
											//jet
											int points = p->getEnergyPoints() + 2;
											p->setEnergyPoints(points);
											cout << endl << " + 2 energy points!";
											if (p->getLifePoints() > 10)
											{
												int life = p->getLifePoints() - 10;
												p->setLifePoints(p->getLifePoints() - life);
												cout << endl << "You have reached maximum health!" << endl
													<< "(You cannot go over the 10 life point maximum)" << endl;
											}
											p->displayMonsterStats();
											//myMap->graph.regions.at(p->getRegionId()).units.pop_back();

											//desCount = desCount - (ptrU->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										}
										//award players
										if (ptrU->name == "Tank")
										{
											desCount = desCount - (ptrU->getDurability());
											//jet
											int points = p->getVictoryPoints() + 3;
											p->setVictoryPoints(points);
											cout << endl << " + 3 victory points!";
											p->displayMonsterStats();
											//myMap->graph.regions.at(p->getRegionId()).units.pop_back();
											//desCount = desCount - (ptrU->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										}
										//award players
										if (ptrU->name == "Infantry")
										{
											desCount = desCount - (ptrU->getDurability());

											//jet
											int points = p->getLifePoints() + 1;
											p->setLifePoints(points);
											cout << endl << " + 1 life points!";
											if (p->getLifePoints() > 10)
											{
												int life = p->getLifePoints() - 10;
												p->setLifePoints(p->getLifePoints() - life);
												cout << endl << "You have reached maximum health!" << endl
													<< "(You cannot go over the 10 life point maximum)" << endl;
											}
											p->displayMonsterStats();
											//myMap->graph.regions.at(p->getRegionId()).units.pop_back();
											//desCount = desCount - (ptrU->getDurability());
											if (desCount <= 0)
											{
												desCount = 0;
												p->setDestroy(false);
											}
											myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										}
									}
									else
									{
										cout << endl << "You don't have enough destruction dice to eliminate this unit." << endl;
									}
								}
							}
						}
					}
					//if (desCount > 0)
					//{
					//cout << endl << "\nYou still have some destruction dice!\n" << endl;
					//}
					//else
					desCount = 0;
				}
			}
		}
	}
  }


		if ((energyCount == 0) && (attackCount == 0) && (desCount == 0) && (healCount == 0) && (celebCount == 0) && (ouchCount == 0))
			allResolved = true;
		else
		{
			cout << endl << "YOUR DICE: " << endl;
			cout << "DICE TYPE # OF DICE" << endl;
			if (energyCount != 0)
				cout << "Energy Dice:  " << energyCount << endl;
			if (attackCount != 0)
				cout << "Attack Dice:  " << attackCount << endl;
			if (desCount > 0)
				cout << "Destruction Dice: " << desCount << endl;
			if (healCount != 0)
				cout << "Heal Dice:  " << healCount << endl;
			if (celebCount != 0)
				cout << "Celebrity Dice:  " << celebCount << endl;
			if (ouchCount != 0)
				cout << "Ouch! Dice:  " << ouchCount << endl;
		}
	}
}

void aggressiveBehavior::move(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "move");
	char input;
	cout << endl << p->getMonsterName() << ", would you like to move?" << endl;
	cout << endl << "Enter Y or N" << endl << endl;
	//automatically move
	input = 'y';
	cout << "Y";
	/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
	{
	cout << endl << "That is an invalid entry." << endl
	<< "Please enter Y or N" << endl << endl;
	cin >> input;
	}*/
	if ((input == 'y') || (input == 'Y'))
	{
		vector <Player*> plVect = myMap->getPlayers();
		cout << p->getMonsterName() << " is in " << p->getRegion().getName() << endl
			<< "You can move to one of the following cities: " << endl;
		vector<int>listNodes = myMap->graph.availableNodes(p->getRegion().getID(), p->getRegionsVisited(plVect));
		int destination;
		bool wrongNumber = true;
		do
		{
			cout << endl << "Where would you like to go? (only numbers on list)" << endl;
			for (int i = 0; i < listNodes.size(); i++)
			{
				destination = listNodes[i]; // always choose first place on list
				if (destination == listNodes.at(i))
				{
					wrongNumber = false;
				}
			}
		} while (wrongNumber);
		myMap->graph.visitNode(destination, p->getRegion().getID());
		p->setRegion(myMap->graph.findVertexById(destination));
		//check conditions if they can/can't move there*/
	}
	if ((input == 'n') || (input == 'N'))
		return;
}


void aggressiveBehavior::buyCards(Map* myMap, Player* p)
{
	char input;
	do
	{
		//char input;
		NotifyPhase(p->getPlayerId(), "buy cards");
		cout << endl << p->getMonsterName() << ", would you like to buy cards?" << endl;
		cout << endl << "Enter Y or N" << endl << endl;
		input = 'y';
		cout << endl << "Y";
		/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "Please enter Y or N" << endl << endl;
		cin >> input;
		}*/
		if ((input == 'y') || (input == 'Y'))
		{

			int cardNumber;
			cout << "Select one of the following cards: (1, 2, 3 or 4) \n" << endl;
			for (int i = 0; i < 3; i++)
			{
				if (myMap->cards.size() > i)
				{ // to check if we have more than 3 cards on deck
					cout << i + 1 << ". " << myMap->cards.at(i).getCardName();
					if (myMap->cards.at(i).getCardName() == "Overload")
					{
						cout << endl << "Overload ( 0 energy points to buy!)";
						cardNumber = i;
						cout << endl << "You selected Overload" << endl;
					}
					else if (myMap->cards.at(i).getCardName() == "Regeneration")
					{
						cout << endl << "You selected Regeneration" << endl;
						cardNumber = i;
					}
					else if (myMap->cards.at(i).getCardName() == "PhoenixBlood")
					{
						cout << endl << "You selected Phoenix Blood" << endl;
						cardNumber = i;
					}
					else if (myMap->cards.at(i).getCardName() == "ChinaTownRegular")
					{
						cout << endl << "You selected China Town Regular" << endl;
						cardNumber = i;
					}
					else if (myMap->cards.at(i).getCardName() == "TrophyHuner")
					{
						cout << endl << "You selected Trophy Huner" << endl;
						cardNumber = i;
					}
					else if (myMap->cards.at(i).getCardName() == "Drain")
					{
						cout << endl << "You selected Drain" << endl;
						cardNumber = i;
					}
					else
						cardNumber = i;
				}
			}
			//always choose first card
			//cardNumber = 1;
			cout << "4. If you want to discard/reveal new three cards" << endl;
			//cin >> cardNumber;
			/*if (cardNumber == 4)
			{
			// player wanted to discard cards
			int newCnum;
			vector<Cards> newCards;
			if (p->getEnergyPoints() < 2)
			cout << "You don't have enough energy points to discard!";
			else
			{
			if (myMap->cards.size() <= 3)
			{
			cout << "No more cards are available on deck!" << endl;
			}
			else
			{
			p->setEnergyPoints(p->getEnergyPoints() - 2);
			for (int i = 3; i < myMap->cards.size(); i++)
			{
			newCards.push_back(myMap->cards.at(i));
			}
			newCards.push_back(myMap->cards.at(2));
			newCards.push_back(myMap->cards.at(1));
			newCards.push_back(myMap->cards.at(0));
			}
			myMap->setCards(newCards);
			}
			cout << "Select one of the following cards: (1,2 or 3) \n" << endl;
			for (int i = 0; i < 3; i++) {
			if (myMap->cards.size() > i) { // to check if we have more than 3 cards on deck
			cout << i + 1 << ". " << myMap->cards.at(i).getCardName();
			if (myMap->cards.at(i).getCardName() == "Overload") {
			cout << " ( 0 energy points to buy!)";
			}
			cout << endl;
			}
			}
			cin >> newCnum;
			cardNumber = newCnum;
			}*/
			// a loop for discarding cards
			if (cardNumber != 4)
			{ // a player choose a card
				int counttt = 0;
				// means that a player can not buy any availabe card
				//bool haveEnoughEnergyPoints = (p->getEnergyPoints() > myMap->cards.at(cardNumber - 1).getCost());
				/*while (cardNumber > 4)
				{
				cout << "PLEASE choose from the AVAILABLE cards." << endl;
				cin >> cardNumber;
				}*/
				bool haveEnoughEnergyPoints = (p->getEnergyPoints() > myMap->cards.at(cardNumber - 1).getCost());
				while (!haveEnoughEnergyPoints)
				{
					cout << "You don't have enough points to buy this card...please choose another card \n";
					counttt++;
					if (counttt == 3)
					{
						cout << "Sorry but You don't have enough energy points to buy any of the cards!" << endl;
						p->setCanBuy(false);
						break;
					}
					if (cardNumber < 4)
					{
						cardNumber++;
						//if (cardNumber == 4)
						//	cardNumber = 1;
					}
					haveEnoughEnergyPoints = (p->getEnergyPoints() > myMap->cards.at(cardNumber - 1).getCost());
				}
				if (counttt != 3) {
					p->setEnergyPoints(p->getEnergyPoints() - (myMap->cards.at(cardNumber - 1).getCost()));
					if (p->getEnergyPoints() <= 0)
						p->setEnergyPoints(0);
					p->cards.push_back(myMap->cards.at(cardNumber - 1));
					vector<Cards> newC;
					for (int m = 0; m < myMap->cards.size(); m++) {
						if (m != cardNumber - 1)
							newC.push_back(myMap->cards.at(m));
					}
					cout << "\nHere is your new card you got: " << (myMap->cards.at(cardNumber - 1).getCardName()) << endl;
					cout << "Your new energy points now: " << p->getEnergyPoints() << endl;
					myMap->setCards(newC);
				}
			}
		}
	} while (((input == 'y') || (input == 'Y')) && (p->getCanBuy() == true));
}
void aggressiveBehavior::displayStats(Player* p) {
	NotifyStats();
}
aggressiveBehavior::~aggressiveBehavior()
{
}

