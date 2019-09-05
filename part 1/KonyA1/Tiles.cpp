#include "Tiles.h"



Tiles::Tiles()
{
	IsBuilding = true;
	IsUnit = false;
}

Tiles::~Tiles()
{
}

int Tiles::getTilesTotal() {
	return TilesTotal;
}

void Tiles::SetTilesTotal(int newTotal) {
	TilesTotal = newTotal;
}

bool Tiles::getIsBuilding() {
	return (IsBuilding == true);
}

bool Tiles::getIsUnit() {
	return (IsUnit = true);
}

std::string Tiles::getFace() {
	if (IsBuilding)
		return "Building";
	return "Unit";
}

std::string Tiles::getRewardType() {
	return rewardType;
}

std::vector <Tiles> Tiles::shuffleTiles(std::vector <Tiles> tls) {
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(tls.begin(), tls.end());
	return tls;

}

HighRise1::HighRise1() {
	name = "High Rise";
	TilesTotal = 22;
	rewards = 1;
	durability = 1;
	rewardType = "victory";
}

HighRise1::~HighRise1() {

}

void HighRise1::ReverseTile() {
	name = "Infantry";
	IsBuilding = false;
	IsUnit = true;
	durability = 2;
	rewardType = "life";
}


HighRise2::HighRise2() {
	name = "High rise";
	TilesTotal = 8;
	rewards = 2;
	durability = 2;
	rewardType = "victory";
}

HighRise2::~HighRise2() {

}

void HighRise2::ReverseTile() {
	name = "Jet";
	IsBuilding = false;
	IsUnit = true;
	durability = 3;
	rewardType = "energy";
}


Hospital2::Hospital2() {
	name = "Hospital";
	TilesTotal = 3;
	rewards = 2;
	durability = 2;
	rewardType = "life";
}

Hospital2::~Hospital2() {

}

void Hospital2::ReverseTile() {
	name = "Jet";
	IsBuilding = false;
	IsUnit = true;
	durability = 3;
	rewardType = "energy";
}


Factory2::Factory2() {
	name = "Factory";
	TilesTotal = 3;
	rewards = 2;
	durability = 2;
	rewardType = "energy";
}

Factory2::~Factory2() {

}

void Factory2::ReverseTile() {
	name = "Jet";
	IsBuilding = false;
	IsUnit = true;
	durability = 3;
	rewardType = "energy";
}

HighRise3::HighRise3() {
	name = "High rise";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "victory";
}

HighRise3::~HighRise3() {

}

void HighRise3::ReverseTile() {
	name = "Tank";
	IsBuilding = false;
	IsUnit = true;
	durability = 4;
	rewardType = "victory";
}

Hospital3::Hospital3() {
	name = "Hospital";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "life";
}

Hospital3::~Hospital3() {

}

void Hospital3::ReverseTile() {
	name = "Tank";
	IsBuilding = false;
	IsUnit = true;
	durability = 4;
	rewardType = "victory";
}

Factory3::Factory3() {
	name = "Factory";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "energy";
}

Factory3::~Factory3() {

}

void Factory3::ReverseTile() {
	name = "Tank";
	IsBuilding = false;
	IsUnit = true;
	durability = 4;
	rewardType = "victory";
}


/*
std::vector<Tiles> Tiles::createTiles() {
vector<Tiles> myTiles;
HighRise1 hr1; //22
HighRise2 hr2; //8
HighRise3 hr3; //3
Hospital2 hos2; //3
Hospital3 hos3; //3
Factory2 fac2; //3
Factory3 fac3; //3
for (int i = 0; i < 22; i++) {
myTiles.push_back(hr1);
}
for (int i = 1; i <= 8; i++) {
myTiles.push_back(hr2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hr3);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hos2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hos3);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(fac2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(fac3);
}
return myTiles;
}

void Tiles::print() {
vector<Tiles> t;
t = Tiles::createTiles();
for (int i = 0; i < t.size(); i++)
cout << t.at(i).getInfo() << endl;
}

*/

void Tiles::getInfo() {
	cout << "a " << name << ", it has " << rewards << " " << getRewardType() << " and " << durability << " durability. \n" << endl;

	//ReverseTile();
	//return "a" +name+ ", it has " +rewards; !!
	//cout<<"On the other face, it is \" " + name + ", it has "<<rewards <<" " + getRewardType() + " and "<<durability<<" durability." << endl;

}