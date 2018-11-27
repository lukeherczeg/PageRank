#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#include "pagerank.h"

template <typename T> 			// Helper function to simplify sorting.
void sort(vector<T> array){
	sort((array).begin(), (array).end());
}

void Graph::insertEdge(string from, string to){
	graph[from].push_back(to);
	vertices.insert(to);		// Inserting both to and from will assure all vertices are collected without overlap.
	vertices.insert(from);
}


bool Graph::isEdge(string from, string to){
	string i = *(vertices.find(from));      // Automatically dereference returned iterator from set.find(item);
	vector<string> j = getAdjacent(i);
	for(string k : j)
		if(k == to)
			return true;
	return false;
}

vector<string> Graph::getAdjacent(string vertex){  // Gets vector of adjacent pages from a vertex.
	return graph[vertex];
}

float Graph::getOutDegree(string vertex){  // Gets the out degree of a vertex using getAdjacent.
	return getAdjacent(vertex).size();
}

void Graph::sortVertices(){
	vector<string> temp;
	for(string i : vertices)
		temp.push_back(i);
	sort(temp);
	sortedVertices = temp;
}


void Graph::initRankMatrix(){   // Initializes the rank matrix and fills it with proper values.
	int n = vertices.size();
	rankMatrix = new float *[n];
	for(int i = 0; i < n; i++){
		rankMatrix[i] = new float[n];
		for(int j = 0; j < n; j++)
			rankMatrix[i][j] = 0; // Must set values before we can alter them in a different order (j,i) later.
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(isEdge(sortedVertices[i],sortedVertices[j]))
				rankMatrix[j][i] = 1/getOutDegree(sortedVertices[i]);
	}
}

void Graph::initPowMatrix(){   // Initializes the power matrix and fills it with proper values.
	int n = vertices.size();
	powMatrix = new float[n];
	for(int i = 0; i < n; i++)
		powMatrix[i] = 1 / float(n);
}

void Graph::initMatrices(){
	initPowMatrix();
	initRankMatrix();
}

void Graph::powerIterations(int iterations){
	int n = vertices.size();
	float * tempMatrix = new float[n];
	for(int t = 1; t < iterations; t++){  // Uses a temporary matrix to store and change the values of the
										  // iterating power matrix.
		for(int i = 0; i < n; i++)
			tempMatrix[i] = powMatrix[i];  // Copy powMatrix to the tempMatrix

		for(int i = 0; i < n; i++){
			float num = 0;
			for(int j = 0; j < n; j++)
				num += rankMatrix[i][j] * powMatrix[j];  // Perform multiplication
			tempMatrix[i] = num;
		}

		for(int i = 0; i < n; i++)
			powMatrix[i] = tempMatrix[i];  // Copy tempMatrix back to the powMatrix

	}
}

void Graph::printPageRank(){
	int n = vertices.size();
	for(int i = 0; i < n; i++){
		cout << sortedVertices[i];
		printf(" %.2f\n", powMatrix[i]);
	}
}

int main(){
    Graph * g = new Graph();
	int lines, iterations;
	string from, to;

	cin >> lines;
	cin >> iterations;
	if(iterations >= 1){
		for(int i = 0; i < lines; i++){
			cin >> from;
			cin >> to;
			g->insertEdge(from,to);
		}

		g->sortVertices();
		g->initMatrices();
		g->powerIterations(iterations);
		g->printPageRank();
	}
	else
		cout << "\nThe number of iterations must be a positive integer above 0." << endl;

    return 0;
}
