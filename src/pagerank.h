#ifndef PAGERANK_H_
#define PAGERANK_H_

class Graph
{
	private:
		map <int, vector<pair<int, int>>> g;
		set <int> vertices;
		map <int, vector<int>> simpleG;
    public:
		void insertEdge(int from, int to, int weight);  //inserts new edge in graph
		bool isEdge(int from, int to);  //returns true if there is an edge between the vertices from and to
		int getWeight(int from, int to);  //returns the weight of the edge between the vertices from and to
		vector<int> getAdjacent(int vertex);  //return an array of integers representing vertices adjacent to vertex
		void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
};



#endif /* PAGERANK_H_ */
