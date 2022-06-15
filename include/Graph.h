#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

typedef struct Node {
	int _id;
	vector<pair<int, int>> _children;
}Node;

class Graph {
private:
	vector<Node> _nodes;

public:
	//Construtor padrao para o grafo, sem vertices ou arestas
	Graph();


	//Metodo para adicionar um vertice
	void addNode(int id);
	//Metodo para adicionar uma aresta de origin para dest
	void addEdge(int origin, int dest, int weight);
	//Imprime todos os vertices
	void printNodes();
	//Imprime todas as arestas
	void printEdges();

	/*Funcao: int findMaxFlowPath(int a, int b)
*	Descricao:	A partir de uma busca BFS, calcula dentre todos os caminhos de a até b, o que tem o maior fluxo
*	Entrada:	int a - id do vertice a
*				int b - id do vertice b

*
*	Retorna:	O fluxo inteiro referente ao caminho encontrado
*/
	int findMaxFlowPath(int a, int b);
};

/*Tipo Data_BFS que e usado para processar os caminhos entre dois vertices no grafo. Data_BFS e uma tupla de 3 
elementos da forma triple(set<int> path, int atual, int flow)
		- set<int> path: Set utilizado para salvar todos os vertices visitados no caminho processado
		- int current: Variavel inteira que salva o ultimo vertice adicionado ao caminho que esta sendo processado
		- int flow: Variavel inteira que salva o fluxo relacionado ao caminho processado
	*/
typedef tuple<unordered_set<int>, int, int> Data_BFS;
#endif // !GRAPH_H