#include "Graph.h"

Graph::Graph() : _nodes(NULL) {}

void Graph::addNode(int id) {
	Node node;
	node._id = id;
	_nodes.push_back(node);
}

void Graph::addEdge(int origin, int dest, int weight) {
	pair<int, int> child(dest, weight);
	_nodes[origin]._children.push_back(child);
}

void Graph::printNodes() {
	for (int i = 0; i < _nodes.size(); i++) {
		cout << _nodes[i]._id << "\n";
	}
}

void Graph::printEdges() {
	for (int i = 0; i < _nodes.size(); i++) {
		for (int j = 0; j < _nodes[i]._children.size(); j++) {
			int parent = _nodes[i]._id;
			int child = _nodes[i]._children[j].first;
			int weight = _nodes[i]._children[j].second;
			cout << parent << " to " << child << " weighing " << weight << "\n";
		}
	}
}

int Graph::findMaxFlowPath(int a, int b) {
	if (a == b) {
		return 0;
	}
	//Vetor para salvar o fluxo de cada caminho encontrado
	vector<int> flow;

	/*Fila da busca BFS no grafo. Para realizar a busca BFS e utilizado uma tupla de 3 elementos da forma triple(set<int> path, int atual, int flow)
		- set<int> path: Set utilizado para salvar todos os vertices visitados no caminho processado
		- int current: Variavel inteira que salva o ultimo vertice adicionado ao caminho que esta sendo processado
		- int flow: Variavel inteira que salva o fluxo relacionado ao caminho processado
	*/
	queue<Data_BFS> q;
	//Inicia busca BFS no grafo a partir de a
	unordered_set<int> path;
	path.insert(a);
	Data_BFS tmp = make_tuple(path, a, 100001);
	q.push(tmp);
	while (!q.empty()) {
		path = get<0>(q.front());
		int current = get<1>(q.front());
		int path_flow = get<2>(q.front());
		q.pop();

		//Se o no atual e o destino, salva o fluxo do caminho encontrado
		if (current == b) {
			flow.push_back(path_flow);
		}
		
		else {
			//Percorre todos os filhos do vertice atual
			for (int i = 0; i < _nodes[current]._children.size(); i++) {
				int child = _nodes[current]._children[i].first;
				int weight = _nodes[current]._children[i].second;
				//Se o filho nao esta no caminho atual, o insere
				unordered_set<int>::iterator finded = path.find(child);
				if (finded == path.end()) {
					unordered_set<int> newPath = path;
					newPath.insert(child);
					//Atualiza current e testa se o peso da aresta e menor que o fluxo do caminho ate o momento
					int newCurrent = child;
					int newPathFlow = path_flow;
					if (weight < path_flow) {
						newPathFlow = weight;
					}
					tmp = make_tuple(newPath, newCurrent, newPathFlow);
					q.push(tmp);
				}
			}
		}
		
	}
	int higherFlow = 100001;
	if (flow.empty()) {
		cout << "There are no paths between a and b\n";
	}
	else {
		higherFlow = flow[0];
	}
	for (int i = 1; i < flow.size(); i++) {
		if (flow[i] > higherFlow) {
			higherFlow = flow[i];
		}
	}

	return higherFlow;
}