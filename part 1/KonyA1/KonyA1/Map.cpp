#include "Map.h"
using namespace std;

Map::Map()
{
	players;
	regions;
	zones;
	connections;
}

Map::Map(Graph grph, vector <Player> plyrs)
{
	graph = grph;
	players = plyrs;
	initializeVectors();
}

//MUTATORS
void Map::setGraph(Graph grph)
{
	graph = grph;
}
void Map::setPlayers(vector <Player> plyrs)
{
	players = plyrs;
}
void Map::setRegions(vector <Vertex> rgns)
{
	regions = rgns;
}
void Map::setZones(vector <Vertex> zns)
{
	zones = zns;
}
void Map::setEdges(vector <Edge> cons)
{
	connections = cons;
}

//ACCESSORS
Graph Map::getGraph()
{
	return graph;
}
vector <Player> Map::getPlayers()
{
	return players;
}
vector <Vertex> Map::getRegions()
{
	return regions;
}
vector <Vertex> Map::getZones()
{
	return zones;
}
vector <Edge> Map::getConnections()
{
	return connections;
}

//METHODS
void Map::showPlayers()
{
	for (int i = 0; i < players.size(); i++)
	{
		//cout << players[i].getMonsterName() << endl;
		players[i].displayMonsterStats();
		cout << endl;
	}
}
void Map::showRegions()
{
	for (int i = 0; i < regions.size(); i++)
	{
		cout << regions[i].getName();
		cout << endl;
	}
}
void Map::showZones()
{
	for (int i = 0; i < zones.size(); i++)
	{
		cout << zones[i].getName();
		cout << endl;
	}
}
void Map::showConns()
{
	for (int i = 0; i < regions.size(); i++)
	{
		cout << regions[i].getName() << endl;
		regions[i].showEdges();
		cout << endl;
	}
	for (int i = 0; i < zones.size(); i++)
	{
		cout << zones[i].getName() << endl;
		zones[i].showEdges();
		cout << endl;
	}

}

void Map::initializeVectors() {
	for (int i = 0; i < graph.regions.size(); i++)
	{
		regions.push_back(graph.regions.at(i));
	}
	for (int i = 0; i < graph.zones.size(); i++)
	{
		zones.push_back(graph.zones.at(i));
	}
	for (int i = 0; i < graph.edges.size(); i++)
	{
		connections.push_back(graph.edges.at(i));
	}
}

Map::~Map()
{
}
