#include "Player.h"
#include "Vertex.h"
#include "Map.h"
using namespace std;

//CONSTRUCTORS
Player::Player()
{
	playerId;
	monster;
	ownsRegion;
	energyPoints = 10;
	blackDice;
	greenDice;
	tokens;
	//energyCubes;
	cards;
	startBlackAmountAttack; //I added
	startGreenAmountAttack;
	totalAttack;
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

	active = true;
	destroy = true;
	firstTurn = true;
	canBuy = true;
	behavior = 0;

}
Player::~Player() {
	//delete monster;
	monster = NULL;
	//delete behavior;
	behavior = NULL;
}
Player::Player(Behavior* beh)
{
	playerId;
	monster;
	ownsRegion;
	energyPoints;
	blackDice;
	greenDice;
	tokens;
	//energyCubes;
	cards;
	//myMap = map;
	startBlackAmountAttack; //I added
	startGreenAmountAttack;
	totalAttack;
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

	active = true;
	destroy = true;
	firstTurn = true;
	canBuy = true;
	behavior = beh;

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
void Player::executeRollDice(Player* p)
{
	return behavior->rollDice(p);
}
void Player::executeResolveDice(Map* myMap, Player* p)
{
	return behavior->resolveDice(myMap, p);
}
void Player::executeMove(Map* myMap, Player* p)
{
	return behavior->move(myMap, p);
}
void Player::executeBuyCards(Map* myMap, Player* p)
{
	return behavior->buyCards(myMap, p);
}
void Player::executeChooseMonster(Map* myMap, Player* p)
{
	return behavior->chooseMonster(myMap, p);
}
void Player::executeSetFirstPosition(Map* myMap, Player* p)
{
	return behavior->setFirstPosition(myMap, p);
}
void Player::setBehavior(Behavior* someBehavior)
{
	behavior = someBehavior;
}
void Player::setCanBuy(bool set)
{
	canBuy = set;
}
bool Player::getCanBuy()
{
	return canBuy;
}
int Player::getRegionId()
{
	return regionId;
}
void Player::setRegionId(int set)
{
	regionId = set;
}
/*void Player::setMap(Map*)
{
Map* getInstance();
}*/
void Player::executeDisplayStats(Player* p)
{
	return behavior->displayStats(p);
}
void Player::displayMonsterStats()
{
	cout << endl << getMonsterName();
	cout << endl << "Life points: ";
	cout << getLifePoints();
	cout << endl << "Victory points: ";
	cout << getVictoryPoints();
	if (!getRegion().getName().empty()) {
		cout << endl << "Region: ";
		cout << getRegion().getName() << endl;
	}
	else {
		cout << endl;
	}

}
void Player::setPlayerId(int id)
{
	playerId = id;
	_subjectPhase = behavior;
	_subjectStats = behavior;
	_subjectPhase->AttachPhase(this, this->getPlayerId());
	_subjectStats->AttachStats(this);
}
void Player::setMonster(Monsters* mons)
{
	monster = mons;
}
void Player::setLifePoints(int lp)
{
	monster->setLPoints(lp);
}
void Player::setVictoryPoints(int vp)
{
	monster->setVPoints(vp);
}
void Player::setEnergyPoints(int nrg)
{
	energyPoints = nrg;
}
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
//void Player::setEnergyCubes(EnergyCubes nmeCubes)
//{
//energyCubes = nmeCubes;
//}
void Player::setCards(vector <Cards> crds)
{
	cards = crds;
}
void Player::setActivity(bool set)
{
	active = set;
}
void Player::setSuperStar(bool set)
{
	superStar = set;
}
void Player::setStatue(bool set)
{
	statue = set;
}
void Player::setDestroy(bool set)
{
	destroy = set;
}
void Player::setFirstTurn(bool turn)
{
	firstTurn = turn;
}
void Player::setBlackcountAttack(vector <Dice> vDice) {
	int countAttack = 0;
	for (size_t i = 0; i < vDice.size(); i++) {
		vDice[i].roll();
		if (vDice[i].getResult() == "Attack") {
			countAttack++;
		}
	}
	cout << "Number of Attacks counted for the 6 Black Dice " << countAttack << endl;
	startBlackAmountAttack = countAttack;
}
void Player::setGreencountAttack(vector <Dice> vDice) {
	int countAttack = 0;
	for (size_t i = 0; i < vDice.size(); i++) {
		vDice[i].roll();
		if (vDice[i].getResult() == "Attack") {
			countAttack++;
		}
	}
	cout << "Number of Attacks counted for the 2 Green Dice " << countAttack << endl;
	startGreenAmountAttack = countAttack;
}
void Player::setTotalAttack(int bAttack, int gAttack) {
	totalAttack = bAttack + gAttack;
}
//ACCESSORS
int Player::getPlayerId()
{
	return playerId;
}
Monsters* Player::getMonster()
{
	return monster;
}
string Player::getMonsterName()
{
	return monster->getMonsName();
}
int Player::getLifePoints()
{
	return monster->getLPoints();
}
int Player::getVictoryPoints()
{
	return monster->getVPoints();
}
int Player::getEnergyPoints()
{
	return energyPoints;
}
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
//EnergyCubes Player::getEnergyCubes()
//{
// return energyCubes;
//}
vector <Cards> Player::getCards()
{
	return cards;
}
bool Player::getActivity()
{
	return active;
}
bool Player::getSuperStar()
{
	return superStar;
}
bool Player::getStatue()
{
	return statue;
}
bool Player::getDestroy()
{
	return destroy;
}
bool Player::getFirstTurn()
{
	return firstTurn;
}
int Player::getBlackcountAttack() {
	return startBlackAmountAttack;
}
int Player::getGreencountAttack() {
	return startGreenAmountAttack;
}
int Player::getTotalAttack() {
	return totalAttack;
}


//          GAME PIECE RELATED

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
	cout << endl << "You have " << energyPoints << " energy cubes." << endl;
}

vector<Vertex> Player::getRegionsVisited(vector<Player*> pls) {
	vector<Vertex> regionsVisited;
	for (int i = 0; i < pls.size(); i++)
	{
		regionsVisited.push_back(pls[i]->getRegion());
	}
	return regionsVisited;
}

void Player::moveToManhattan(Map* myMap, string zoneName)
{
	//string zoneName;
	int destination;
	for (int i = 0; i < myMap->getGraph().getZones().size(); i++)
	{
		if (myMap->getGraph().getZones().at(i).getName().compare(zoneName) == 0)
			destination = myMap->getGraph().getZones().at(i).getID();
	}
	myMap->getGraph().visitNode(destination, this->getRegion().getID());
	this->setRegion(myMap->getGraph().findVertexById(destination));
}
void Player::moveUp(Map* myMap)
{
	int destination = myMap->getGraph().getUpperManhattan(this->getRegion().getID());
	if (destination != 0) {
		this->setRegion(myMap->getGraph().findVertexById(destination));
		myMap->getGraph().visitNode(destination, this->getRegion().getID());
		cout << endl << this->getMonsterName() << " has been placed in " << this->getRegion().getName() << endl;
	}
	else {
		cout << endl << this->getMonsterName() << " is still in " << this->getRegion().getName() << endl;
	}
}
void Player::UpdateStats()
{
	displayMonsterStats();
};
void Player::UpdatePhase(string action)
{
	displayPhase(action);
};
void Player::displayPhase(string action)
{
	cout << "Player " << this->getPlayerId() << " : " << action << " step" << endl;
};

