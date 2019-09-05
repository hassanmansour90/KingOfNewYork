#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Graph.h"

Graph::Graph()
{}
Graph::Graph(vector<Vertex>allRegions, vector<Vertex>allZones)
{
	regions = allRegions;
	zones = allZones;
}

//ACCESSORS
vector <Vertex> Graph::getZones()
{
	return zones;
}

vector <Vertex> Graph::getRegions()
{
	return regions;
}

vector <Edge> Graph::getEdges()
{
	return edges;
}
void Graph::addEdges()
{
	createListEdges();
	V = edges.size();
	adj = new list<int>[V];
	for (int i = 0; i < edges.size(); i++)
	{
		adj[edges.at(i).getIDFrom()].push_back(edges.at(i).getIDTo());
	}
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	cout << endl << findNameRegionZone(v) << " -> ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	DFSUtil(v, visited);
}

string Graph::findNameRegionZone(int id) {

	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == id) {
			return regions.at(i).getNameByID(id);
		}
	}
	for (size_t i = 0; i < zones.size(); i++)
	{
		if (zones.at(i).getID() == id) {
			return zones.at(i).getNameByID(id);
		}
	}
}

void Graph::createListEdges() {
	for (int i = 0; i < zones.size(); i++)
	{
		for (size_t j = 0; j < zones.at(i).getEdges().size(); j++)
		{
			edges.push_back(zones.at(i).getEdges().at(j));
		}
	}
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getName().compare("Manhattan") != 0) {
			for (size_t j = 0; j < regions.at(i).getEdges().size(); j++)
			{
				edges.push_back(regions.at(i).getEdges().at(j));
			}
		}
	}
}

Graph::~Graph()
{
}
