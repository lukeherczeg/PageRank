#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#include "pagerank.h"

template <typename T>
void sort(vector<T> array){
	sort((array).begin(), (array).end());
}

void Graph::insertEdge(string from, string to){
	g[from].push_back(to);
	vertices.insert(to);		// Inserting both to and from will assure all vertices are collected without overlap.
	vertices.insert(from);
}  //inserts new edge in graph


bool Graph::isEdge(string from, string to){
	string i = *(vertices.find(from));      // Automatically dereference returned iterator
	vector<string> j = getAdjacent(i);
	for(string k : j)
		if(k == to)
			return true;
	return false;
}  //returns true if there is an edge between the vertices from and to

vector<string> Graph::getAdjacent(string vertex){
	return g[vertex];
}  //return an array of strings representing vertices adjacent to vertex


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

float Graph::getOutDegree(string vertex){
	return getAdjacent(vertex).size();
}

void Graph::sortVertices(){
	vector<string> temp;
	for(string i : vertices)
		temp.push_back(i);
	sort(temp);
	sortedVertices = temp;
}

void Graph::fillRanks(){
	int n = vertices.size();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(isEdge(sortedVertices[i],sortedVertices[j]))
				rankMatrix[j][i] = 1/getOutDegree(sortedVertices[i]);
}

void Graph::initializeMatrix(){
	int n = vertices.size();
	rankMatrix = new float *[n];
	for(int i = 0; i < n; i++){
		rankMatrix[i] = new float[n];
		for(int j = 0; j < n; j++)
			rankMatrix[i][j] = 0;
	}
}

void Graph::printMatrix(){
	int n = vertices.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("  %.2f", rankMatrix[i][j]);
		cout << endl;
	}
}

void Graph::printSortedVertices(){
	int c = 0;
	for(string i : sortedVertices){
		cout << i << " ";
		c++;
	}
}

int main(){
    string to, fro;
    Graph * g = new Graph();

    fro = "google.com";
    to = "gmail.com";
    g->insertEdge(fro,to);

    fro = "google.com";
	to = "maps.com";
	g->insertEdge(fro,to);

	fro = "facebook.com";
	to = "ufl.edu";
	g->insertEdge(fro,to);

	fro = "ufl.edu";
	to = "google.com";
	g->insertEdge(fro,to);

	fro = "ufl.edu";
	to = "gmail.com";
	g->insertEdge(fro,to);

	fro = "maps.com";
	to = "facebook.com";
	g->insertEdge(fro,to);

	fro = "gmail.com";
	to = "maps.com";
	g->insertEdge(fro,to);

	g->printGraph();
	g->sortVertices();
	g->initializeMatrix();
	g->fillRanks();
	g->printMatrix();



//	for(string i : g->getAdjacent(fro))
//		cout << i << " ";
//	cout << endl;


    return 0;
}
