#include "Graph.h"

using namespace std;
int main() {
	int V, E, numPaths;
	cin >> V; cin >> E; cin >> numPaths;
	//Declara grafo G e preenche os vertices
	Graph G;
	for (int i = 0; i < V; i++) {
		G.addNode(i);
	}
	//Declara grafo G e preenche as arestas
	for (int i = 0; i < E; i++) {
		int source, dest, weight;
		cin >> source; cin >> dest; cin >> weight;
		source--; dest--;
		G.addEdge(source, dest, weight);
	}

	//Para cada consulta, calcula o caminho que tem o maior fluxo
	for (int i = 0; i < numPaths; i++) {
		int source, dest;
		cin >> source; cin >> dest;
		source--; dest--;
		int result = G.findMaxFlowPath(source, dest);
		cout << result << endl;
	}
	
	return 0;
}