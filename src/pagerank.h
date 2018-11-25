#ifndef PAGERANK_H_
#define PAGERANK_H_

class Graph
{
	private:
		map <string, vector<string>> g;
		set <string> vertices;
		vector <string> sortedVertices;
		float ** rankMatrix;

    public:
		void insertEdge(string from, string to);  //inserts new edge in graph
		bool isEdge(string from, string to);  //returns true if there is an edge between the vertices from and to
		vector<string> getAdjacent(string vertex);  //return an array of integers representing vertices adjacent to vertex
		void printGraph(); //prints graph in a format sorted by ascending vertex and edge list
		float getOutDegree(string vertex);
		void sortVertices();
		void printSortedVertices();
		void initializeMatrix();
		void fillRanks();
		void printMatrix();
};



#endif /* PAGERANK_H_ */
