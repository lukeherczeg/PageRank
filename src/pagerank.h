#ifndef PAGERANK_H_
#define PAGERANK_H_

class Graph
{
	private:
		map <string, vector<string>> graph; // Graph in the form of a map of vertices with their adjacent vertices in a vector
		set <string> vertices;              // Unordered set to store all vertices (even if they don't have an edge)
		vector <string> sortedVertices;     // Only needed for alphabetically sorted output
		float ** rankMatrix;                // Two dimensional matrix with ranks regarding out degrees
		float * powMatrix;                  // |V|x 1 matrix that will be iterated, only necessary to make it one dimensional

    public:
		vector<string> getAdjacent(string vertex);
		bool isEdge(string from, string to);
		float getOutDegree(string vertex);
		void insertEdge(string from, string to);
		void powerIterations(int iterations);
		void sortVertices();
		void initRankMatrix();
		void initPowMatrix();
		void initMatrices();
		void printPageRank();
};



#endif /* PAGERANK_H_ */
