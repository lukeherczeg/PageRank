#ifndef PAGERANK_H_
#define PAGERANK_H_

class Graph
{
	private:
		map <string, vector<string>> graph;
		set <string> vertices;
		vector <string> sortedVertices;
		float ** rankMatrix;
		float * powMatrix;

    public:
		vector<string> getAdjacent(string vertex);
		bool isEdge(string from, string to);
		float getOutDegree(string vertex);
		void insertEdge(string from, string to);
		void powerIterations(int iterations);
		void printGraph();
		void sortVertices();
		void initRankMatrix();
		void initPowMatrix();
		void initMatrices();
		void printRankMatrix();
		void printPowMatrix();
		void printPageRank();
};



#endif /* PAGERANK_H_ */
