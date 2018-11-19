#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#include "pagerank.h"

/*
  map <int, vector<pair<int, int>>>;
  set <int> vertices;
  map <int, vector<int>>;
*/



void insertEdge(int from, int to, int weight){
	;
}  //inserts new edge in graph


bool isEdge(int from, int to){
	return true;
}  //returns true if there is an edge between the vertices from and to


int getWeight(int from, int to){
	return 0;
}  //returns the weight of the edge between the vertices from and to


vector<int> getAdjacent(int vertex){
	return NULL;
}  //return an array of integers representing vertices adjacent to vertex


void printGraph(){
	;
} //prints graph in a format sorted by ascending vertex and edge list


int main()
{
    //DO NOT CHANGE THIS FUNCTION. CHANGE YOUR IMPLEMENTATION CODE TO MAKE IT WORK
    int noOfLines, operation, vertex, to, fro, weight,source,j;
    vector<int> arr;
    int arrSize;
    Graph g;
    cin>>noOfLines;
    for(int i=0;i<noOfLines;i++)
    {
        cin>>operation;
        switch(operation)
        {
            case 2:
                cin>>fro;
                cin>>to;
                cin>>weight;
                g.insertEdge(fro,to,weight);
                break;
            case 3:
                cin>>fro;
                cin>>to;
                cout<<g.isEdge(fro,to)<<"\n";
                break;
            case 4:
                cin>>fro;
                cin>>to;
                cout<<g.getWeight(fro,to)<<"\n";
                break;
            case 5:
                cin>>vertex;
                arr=g.getAdjacent(vertex);
                arrSize = arr.size();
                j=0;
                while(j<arrSize)
                {
                    cout<<arr[j]<<" ";
                    j++;
                }
                cout<<"\n";
                break;
            case 7:
                g.printGraph();
                cout<<"\n";
                break;
        }
    }
    return 0;
}
