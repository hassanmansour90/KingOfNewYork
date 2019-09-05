#pragma once
#include "Player.h"
#include "Graph.h"

class Map
{
public:
	Map();
	Map(Graph grph, vector <Player> plyrs);
	~Map();

	//MUTATORS
	void setGraph(Graph grph);
	void setPlayers(vector <Player> plyrs);
	void setRegions(vector <Vertex> rgns);
	void setZones(vector <Vertex> zns);
	void setEdges(vector <Edge> cons);

	//ACCESSORS
	Graph getGraph();
	vector <Player> getPlayers();
	vector <Vertex> getRegions();
	vector <Vertex> getZones();
	vector <Edge> getConnections();

	//METHODS
	void showPlayers();
	void showRegions();
	void showZones();
	void showConns();
	void initializeVectors();


private:
	Graph graph;
	vector <Player> players;
	vector <Vertex> regions;
	vector <Vertex> zones;
	vector <Edge> connections;

};

