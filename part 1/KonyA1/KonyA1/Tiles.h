#pragma once
#include <iostream>
#include "Player.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include<stack>

class Tiles
{
public:

	//int BDurability;
	//int UDurability;
	//int BRewardPoints;
	//int UnitRewardPoints;

	Tiles();
	virtual ~Tiles();

	int getTilesTotal();
	bool getIsBuilding(); //to check if builing; it is SET initially, and can't be set again once it is reversed.
	bool getIsUnit(); // to check if Unit; it is SET within ReverseTile() method.
	std::string getFace(); // to see if it is a bulding or a unit.
	std::string getRewardType(); // it is fixed and no need to SET

	void SetTilesTotal(int newTotal);
	void getInfo();
	virtual void ReverseTile() {}; // convert a building into a Unit; i.e SET a UNIT
	std::vector <Tiles> shuffleTiles(std::vector <Tiles> tls);

protected:
	std::string name;
	bool IsBuilding; // set initially true
	bool IsUnit; // set initially false
	int TilesTotal; //total nummber of a tile
	int rewards; //reward a tile gives
	std::string rewardType; // would be a victory, life, or energy.
	int durability; // in order to be destroyed

};

class HighRise1 : virtual public Tiles {
public:
	HighRise1();
	virtual ~HighRise1();
	virtual void ReverseTile();
};

class HighRise2 : virtual public Tiles {
public:
	HighRise2();
	virtual ~HighRise2();
	virtual void ReverseTile();
};

class Hospital2 : virtual public Tiles {
public:
	Hospital2();
	virtual ~Hospital2();
	virtual void ReverseTile();
};

class Factory2 : virtual public Tiles {
public:
	Factory2();
	virtual ~Factory2();
	virtual void ReverseTile();
};

class HighRise3 : virtual public Tiles {
public:
	HighRise3();
	virtual ~HighRise3();
	virtual void ReverseTile();
};

class Hospital3 : virtual public Tiles {
public:
	Hospital3();
	virtual ~Hospital3();
	virtual void ReverseTile();
};

class Factory3 : virtual public Tiles {
public:
	Factory3();
	virtual ~Factory3();
	virtual void ReverseTile();
};