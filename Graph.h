#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

typedef struct Node {
	int _id;
	std::vector<std::pair<int, int>> _children;
}Node;

class Graph {
private:
	std::vector<Node> _nodes;

public:
	Graph();
	void addNode(int id);
	void addEdge(int origin, int dest, int weight);
	void printNodes();
	void printEdges();
};

#endif // !GRAPH_H