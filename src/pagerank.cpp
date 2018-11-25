#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#include "pagerank.h"

void Graph::insertEdge(string from, string to, int weight){
	g[from].push_back(pair<int,string>(weight,to));
	vertices.insert(to);		// Inserting both to and from will assure all vertices are collected without overlap.
	vertices.insert(from);
}  //inserts new edge in graph


bool Graph::isEdge(string from, string to){
	for(string i : vertices){
		if(from == i){
			vector<string> j = getAdjacent(i);
			for(string k : j)
				if(k == to)
					return true;
		}
	}
	return false;
}  //returns true if there is an edge between the vertices from and to


int Graph::getWeight(string from, string to){
	if(isEdge(from,to)){
		vector<pair<int,string>> i = g[from];
		for(pair<int,string> j : i)
			if(j.second == to)
				return j.first;
	}
	return -1;
}  //returns the weight of the edge between the vertices from and to


vector<string> Graph::getAdjacent(string vertex){
	vector<string> adjacent;
	vector<pair<int,string>> i = g[vertex];
	for(pair<int,string> j : i)
		adjacent.push_back(j.second);
	return adjacent;
}  //return an array of integers representing vertices adjacent to vertex


void Graph::printGraph(){
	for(string i : vertices){
		vector<string> j = getAdjacent(i);
		if(!j.empty()){
			cout << i << " ";
			for(unsigned int k = 0; k < j.size(); k++){
				cout << j[k];
				if(k+1 < j.size())
					cout << " ";
			}
		}
		else
			cout << i;
		cout << endl;
	}
} //prints graph in a format sorted by ascending vertex and edge list

int Graph::getOutDegree(string vertex){
	return getAdjacent(vertex).size();
}

void Graph::fillRanks(){
	rankMatrix = new int * [vertices.size()];
	int c = 0;
	int k = 0;
	for(string i : vertices){
		rankMatrix[c] = new int[vertices.size()];
		for(string j : vertices){
			if(isEdge(i,j))
				rankMatrix[c][k] = 1/getOutDegree(i);
			else
				rankMatrix[c][k] = 0;
			k++;
		}
		k = 0;
		c++;
	}
}

void Graph::printMatrix(){
	int c = 0;
	int k = 0;
	for(string i : vertices){
		for(string j : vertices){
			cout << rankMatrix[c][k] << " ";
			k++;
		}
		cout << endl;
		k = 0;
		c++;
	}
}

int main()
{
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
    string to, fro;
	int weight;
    Graph g;

    fro = "google.com";
    to = "facebook.com";
    weight = 40;
    g.insertEdge(fro,to,weight);

    fro = "instagram.com";
	to = "facebook.com";
	weight = 150;
	g.insertEdge(fro,to,weight);

	fro = "facebook.com";
	to = "instagram.com";
	weight = 340;
	g.insertEdge(fro,to,weight);

	fro = "facebook.com";
	to = "elfster.com";
	weight = 340;
	g.insertEdge(fro,to,weight);

	g.printGraph();

	g.fillRanks();
	g.printMatrix();


    return 0;
}
