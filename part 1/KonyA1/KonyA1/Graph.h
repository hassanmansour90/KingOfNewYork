#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<iostream> 
#include<list> 
#include "Vertex.h"


class Graph
{
	
public:
	Graph();
	Graph(vector<Vertex>allRegions, vector<Vertex>allZones);
	void addEdges();
	void DFS(int v);
	string findNameRegionZone(int id);
	void createListEdges();

	vector <Vertex> getZones();
	vector <Vertex> getRegions();
	vector <Edge> getEdges();
	
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

	vector <Vertex> zones;
	vector <Vertex> regions;
	vector <Edge> edges;

	~Graph();
	
};

