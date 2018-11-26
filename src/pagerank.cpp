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
	graph[from].push_back(to);
	vertices.insert(to);		// Inserting both to and from will assure all vertices are collected without overlap.
	vertices.insert(from);
}


bool Graph::isEdge(string from, string to){
	string i = *(vertices.find(from));      // Automatically dereference returned iterator
	vector<string> j = getAdjacent(i);
	for(string k : j)
		if(k == to)
			return true;
	return false;
}

vector<string> Graph::getAdjacent(string vertex){
	return graph[vertex];
}


void Graph::printGraph(){
	for(string i : vertices){
		vector<string> j = getAdjacent(i);
		int n = j.size();
		if(!j.empty()){
			cout << i << " ";
			for(int k = 0; k < n; k++){
				cout << j[k];
				if(k+1 < n)
					cout << " ";
			}
		}
		else
			cout << i;
		cout << endl;
	}
}

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


void Graph::initRankMatrix(){
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

void Graph::initPowMatrix(){
	int n = vertices.size();
	powMatrix = new float[n];
	for(int i = 0; i < n; i++)
		powMatrix[i] = 1 / float(n);
}

void Graph::initMatrices(){
	initPowMatrix();
	initRankMatrix();
}


void Graph::printRankMatrix(){
	int n = vertices.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("  %.2f", rankMatrix[i][j]);
		cout << endl;
	}
	cout << endl;
}

void Graph::printPowMatrix(){
	int n = vertices.size();
	for(int i = 0; i < n; i++){
		printf("  %.2f", powMatrix[i]);
		cout << endl;
	}
	cout << endl;
}

void Graph::powerIterations(int iterations){
	int n = vertices.size();
	float * tempMatrix = new float[n];
	for(int t = 1; t < iterations; t++){

		for(int i = 0; i < n; i++)
			tempMatrix[i] = powMatrix[i];

		for(int i = 0; i < n; i++){
			float num = 0;
			for(int j = 0; j < n; j++)
				num += rankMatrix[i][j] * powMatrix[j];
			tempMatrix[i] = num;
		}

		for(int i = 0; i < n; i++)
			powMatrix[i] = tempMatrix[i];
	}
}

void Graph::printPageRank(){
	int n = vertices.size();
	for(int i = 0; i < n; i++)
		cout << sortedVertices[i] << " " << powMatrix[i] << endl;
}

int main(){
    Graph * g = new Graph();
	int lines, iterations;
	string from, to;

	cin >> lines;
	cin >> iterations;

	for(int i = 0; i < lines; i++){
		cin >> from;
		cin >> to;
		g->insertEdge(from,to);
	}

	g->sortVertices();
	g->initMatrices();
	g->powerIterations(iterations);
	g->printPageRank();

    return 0;
}
