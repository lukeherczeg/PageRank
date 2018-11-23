#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#include "pagerank.h"

void Graph::insertEdge(int from, int to, int weight){
	g[from].push_back(pair<int,int>(weight,to));
	simpleG[from].push_back(to);
	vertices.insert(to);
	vertices.insert(from);
}  //inserts new edge in graph


bool Graph::isEdge(int from, int to){
	for(int i : vertices){
		if(from == i){
			vector<int> j = getAdjacent(i);
			for(int k : j)
				if(k == to)
					return true;
		}
	}
	return false;
}  //returns true if there is an edge between the vertices from and to


int Graph::getWeight(int from, int to){
	if(isEdge(from,to)){
		vector<pair<int,int>> i  = g[from];
		for(pair<int,int> j : i)
			if(j.second == to)
				return j.first;
	}
	return -1;
}  //returns the weight of the edge between the vertices from and to


vector<int> Graph::getAdjacent(int vertex){
	vector<int> adjacent;
	for(int i : simpleG[vertex])
		adjacent.push_back(i);
	return adjacent;
}  //return an array of integers representing vertices adjacent to vertex


void Graph::printGraph(){
	for(int i : vertices){
		vector<int> j = getAdjacent(i);
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


int main()
{
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
    int to, fro, weight;
    Graph g;

    fro = 2;
    to = 3;
    weight = 40;
    g.insertEdge(fro,to,weight);
    cout<<g.getWeight(fro,to)<<"\n";

    fro = 1;
	to = 4;
	weight = 150;
	g.insertEdge(fro,to,weight);
	cout<<g.isEdge(fro,to)<<"\n";
	cout<<g.isEdge(to,fro)<<"\n";
	cout<<g.getWeight(fro,to)<<"\n";

	fro = 1;
	to = 5;
	weight = 340;
	g.insertEdge(fro,to,weight);
	cout<<g.getWeight(fro,to)<<"\n";

	g.printGraph();

    return 0;
}
