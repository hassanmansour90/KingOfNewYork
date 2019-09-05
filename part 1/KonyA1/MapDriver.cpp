
#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "FileIO.h"

using namespace std;

int main()
{
	//Create intial vertex done with file io
	cout << "This section reads a .txt file to create a graph, and shows the edge list for each region." << endl;
	FileIO file("FileIO.txt");
	file.readFile();

	cout << endl << "Brooklyn edge list: " << endl;
	file.regions.at(0).showEdges();

	cout << endl << "Bronx edge list: " << endl;
	file.regions.at(3).showEdges();

	cout << endl << "Staten Island edge list: " << endl;
	file.regions.at(2).showEdges();

	cout << endl << "Queens edge list: " << endl;
	file.regions.at(1).showEdges();

	cout << endl << "Lower-Zone|2-4 edge list: " << endl;
	file.zones.at(0).showEdges();

	cout << endl << "Lower-Zone|5-6 edge list: " << endl;
	file.zones.at(1).showEdges();

	cout << endl << "Midtown-Zone|2-4 edge list: " << endl;
	file.zones.at(2).showEdges();

	cout << endl << "Midtown-Zone|5-6 edge list: " << endl;
	file.zones.at(3).showEdges();

	cout << endl << "Upper-Zone|2-4 edge list: " << endl;
	file.zones.at(4).showEdges();

	cout << endl << "Upper-Zone|5-6 edge list: " << endl;
	file.zones.at(5).showEdges();


	cout << endl << "This section creates the map object." << endl;
	
	//create 2 players, place in a vector
	Player player1, player2;
	vector <Player> pl;
	Monsters mon1("Drakonis");
	Monsters mon2("Mantis");
	player1.setMonster(mon1);
	player2.setMonster(mon2);
	pl.push_back(player1);
	pl.push_back(player2);

	Graph graph(file.regions, file.zones);
	graph.addEdges();

	Map KonyMap(graph, pl);
	
	cout << "Traversing the graph in the map." << endl;
	KonyMap.getGraph().DFS(1);
	cout << endl << "Displaying the players." << endl;
	KonyMap.showPlayers();
	cout << endl << "Displaying the regions." << endl;
	KonyMap.showRegions();
	cout << endl << "Displaying the zones." << endl;
	KonyMap.showZones();
	cout << endl << "Displaying the connections between regions/zones." << endl;
	KonyMap.showConns();

	system("pause");
	return 0;


}
