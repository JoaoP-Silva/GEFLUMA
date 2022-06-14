#include "Graph.h"

Graph::Graph() : _nodes(NULL) {}

void Graph::addNode(int id) {
	Node node;
	node._id = id;
	_nodes.push_back(node);
}

void Graph::addEdge(int origin, int dest, int weight) {
	std::pair<int, int> child(dest, weight);
	_nodes[origin]._children.push_back(child);
}

void Graph::printNodes() {
	for (int i = 0; i < _nodes.size(); i++) {
		std::cout << _nodes[i]._id << "\n";
	}
}

void Graph::printEdges() {
	for (int i = 0; i < _nodes.size(); i++) {
		for (int j = 0; j < _nodes[i]._children.size(); j++) {
			int parent = _nodes[i]._id;
			int child = _nodes[i]._children[j].first;
			int weight = _nodes[i]._children[j].second;
			std::cout << parent << " to " << child << " weighing " << weight << "\n";
		}
	}
}