/*#include "Dice.h"
#include "Tiles.h"
#include "Tokens.h"
#include "Monsters.h"
#include "Cards.h"
#include "EnergyCubes.h"


using namespace std;


int main()
{

//Tokens Ceation//////////////////////////
cout << "Creating some tokens...." << endl;
Web web;
Souvenir souv;
Carapace car;
Jinx jin;
vector <Tokens> tok;
tok.push_back(web);
tok.push_back(souv);
tok.push_back(car);
tok.push_back(jin);
cout << "Done! These are the tokens created: \n" << endl;
for (size_t i = 0; i < tok.size(); i++)
cout << i + 1 << ". " << tok.at(i).getTokenName() << "\t";
cout << endl << "--------------------------------" << "\n" << endl;


//EnemyCube Creation////////////////////////
cout << "Creating some Energy Cubes...." << endl;
EnergyCubes enm(1000);
cout << "Done! " << enm.getTotal() << " energy cubes have been created";
cout << endl << "--------------------------------" << "\n" << endl;


//Creating Monsters/////////////////////////
cout << "Creating some Monsters...." << endl;
Monsters H("Hassan");
Monsters R("Rez");
Monsters P("Priscilla");
Monsters S("Stu");
vector <Monsters> mnstr;
mnstr.push_back(H);
mnstr.push_back(R);
mnstr.push_back(P);
mnstr.push_back(S);
cout << "Done! These are our Monsters created: \n" << endl;
for (size_t i = 0; i < mnstr.size(); i++)
cout << i + 1 << ". " << mnstr.at(i).getMonsName() << " ,Has: " << mnstr.at(i).getVPoints() <<
" victory points, " << mnstr.at(i).getLPoints() << " Life points." << "\n";
cout << endl << "--------------------------------" << "\n" << endl;


//Creating Tiles////////////////////////////
cout << "Creating some Tiles...." << endl;
HighRise1 high;
HighRise2 high2;
Hospital2 hos2;
Factory3 fac3;
Hospital3 hos3;
vector<Tiles> t;
t.push_back(high);
t.push_back(high2);
t.push_back(fac3);
t.push_back(hos2);
t.push_back(hos3);
cout << "Done! These are the Tiles created: \n" << endl;
for (size_t i = 0; i < t.size(); i++) {
cout << i + 1 << ". ";
t.at(i).getInfo();
}
//shuffling........
cout << "Now Shuffling the tiles we have... \n" << endl;
Tiles s;
t = s.shuffleTiles(t);
for (size_t i = 0; i < t.size(); i++) {
cout << i + 1 << ". ";
t.at(i).getInfo();
}
cout << endl << "--------------------------------" << "\n" << endl;

//Creating Crads////////////////////////
cout << "Creating some Cards...." << endl;
LongNeck c1;
TrashThrower c2;
TrophyHuner c3;
StatueOfLiberty c4;
Superstar c5;
vector<Cards> crds;
crds.push_back(c1);
crds.push_back(c2);
crds.push_back(c3);
crds.push_back(c4);
crds.push_back(c5);
cout << "Done! These are the Cards created: \n" << endl;
for (size_t i = 0; i < crds.size(); i++) {
cout << i + 1 << ". " << crds.at(i).getCardName() << ", description: " << crds.at(i).getHowToPlay() << "\n" << endl;
}
//shuffling........
cout << "Now Shuffling the Cards we have... \n" << endl;
Cards shufflecrds;
crds = shufflecrds.shuffleCards(crds);
for (size_t i = 0; i < crds.size(); i++) {
cout << i + 1 << ". " << crds.at(i).getCardName() << ", description: " << crds.at(i).getHowToPlay() << "\n" << endl;

}
cout << endl << "--------------------------------" << "\n" << endl;

system("pause");



return 0;

}*/