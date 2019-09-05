#pragma once
#include "Monsters.h"
#include "Vertex.h"
#include "Tokens.h"
#include "Dice.h"
#include "EnergyCubes.h"
#include "Cards.h"
class Dice;

using namespace std;

class Player
{
public:

	Player();
	//When loading from a file that has all the player information stored in it
	//Player(int id, [type] monster, Vertex reg, vector <Dice> die, vector <Type Cards> cards, int nrg, int vp, int lp);

	friend class Dice;
	// MUTATORS
	void setPlayerId(int id);
	void setMonster(Monsters mons);
	void setLifePoints(int lp);
	void setVictoryPoints(int vp);
	//void setEnergyPoints(int nrg);
	void setRegion(Vertex reg);
	void setBlDice(vector <Dice> bl);
	void setGrDice(vector <Dice> gr);
	void setTokens(vector <Tokens> tok);
	void setEnergyCubes(EnergyCubes cubes);
	void setCards(vector <Cards> crds);



	//ACCESSORS
	int getPlayerId();
	Monsters getMonster();
	string getMonsterName();
	int getLifePoints();
	int getVictoryPoints();
	//int getEnergyPoints();
	Vertex getRegion();
	vector <Dice> getBlDice();
	vector <Dice> getGrDice();
	vector <Tokens> getTokens();
	EnergyCubes getEnergyCubes();
	vector <Cards> getCards();


	// METHODS

	void move();
	void buyCards();

	//Monster Related
	void chooseMonster();
	void displayMonsterStats();

	//Dice Related
	void displayDice(vector <Dice> vDie);
	void resolveDice(vector <Dice> vDie);
	void rollDice(vector <Dice> vDie);

	//Game Piece related

	void displayTokens();
	void displayCards();
	void displayCubes();

	//Members for future functionalities
	int rollCounter;
	bool isTurn;


private:

	int playerId;
	Monsters monster;
	Vertex ownsRegion;
	int lifePoints;
	int victoryPoints;
	//int energyPoints;

	vector <Dice> blackDice;
	vector <Dice> greenDice;
	vector <Tokens> tokens;
	EnergyCubes energyCubes;
	vector <Cards> cards;

};