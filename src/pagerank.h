#ifndef PAGERANK_H_
#define PAGERANK_H_

class Graph
{
	private:
		map <string, vector<pair<int, string>>> g;
		int weightMatrix[][];
		set <string> vertices;

    public:
		void insertEdge(string from, string to, int weight);  //inserts new edge in graph
		bool isEdge(string from, string to);  //returns true if there is an edge between the vertices from and to
		int getWeight(string from, string to);  //returns the weight of the edge between the vertices from and to
		vector<string> getAdjacent(string vertex);  //return an array of integers representing vertices adjacent to vertex
		void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
		int getOutDegree(string vertex);
		void fillAdjacency();
};



#endif /* PAGERANK_H_ */
