#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"
using namespace std;

class Vertex
{
public:
	Vertex();
	Vertex(string nom, int ID);
	Vertex(string nom, int ID, vector <Vertex> owns);
	~Vertex();

	string getName();
	int getID();
	void setID(int id);
	void addEdge(Edge edge);
	void addEdges(vector <Edge> edge);
	void showEdges();
	vector <Edge> getEdges();
	void owns(Vertex has);
	void showOwner();
	vector <Vertex> getOwner();
	string getNameByID(int id);

private:

	string name;
	vector <Vertex> owner;
	vector <Edge> edges;
	int ID;
};

