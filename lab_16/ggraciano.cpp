
/* References:
 * 	www.cplusplus.com/reference/algorithm/sort/
 * 	www.cplusplus.com/reference/map/map/
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct Vertex
{
	int name;
	int key;
	Vertex* pi;

	Vertex(int name) {
		this->name = name;
		key = INT_MAX;
		pi = NULL;
	}
};

struct vertexCompare
{
	bool operator()(const Vertex* left, const Vertex* right)
	{
		return left->key < right->key;
	}
};

struct Graph
{
	std::vector<Vertex*> vertices;
	std::map<std::pair<int, int>, int> edges;
	void AddEdge(int, int, int);
	int FindEdgeCost(int, int);
};

void Graph::AddEdge(int vert1, int vert2, int wt)
{
	edges.insert(std::pair<std::pair<int, int>, int>(std::pair<int, int>(vert1, vert2), wt));
	edges.insert(std::pair<std::pair<int, int>, int>(std::pair<int, int>(vert2, vert1), wt));

	return;
}

int Graph::FindEdgeCost(int vert1, int vert2)
{
	return edges.find(std::pair<int, int>(vert1, vert2))->second;
}

Vertex* vertexFind(std::vector<Vertex*> &Q, int v)
{
	for (int i = 0; i < Q.size(); i++) {
		if (Q[i]->name == v) {
			return Q[i];
		}
	}

	return NULL;
}

void decreaseKey(std::vector<Vertex*> &Q, Vertex* v, int wt)
{
	for (int i = 0; i < Q.size(); i++) {
		if (Q[i]->name == v->name) {
			Q[i]->key = wt;
			Q[i]->pi = v->pi;
			break;
		}
	}
	std::sort(Q.begin(), Q.end(), vertexCompare());

	return;
}

void MSTPrim(Graph G, int r)
{
	std::vector<Vertex*> Q;
	std::map<std::pair<int, int>, int>::iterator eit;

	for (int i = 0; i < G.vertices.size(); i++) {
		Q.push_back(new Vertex(i));
	}
	std::sort(Q.begin(), Q.end(), vertexCompare());

	Q[r]->key = 0;

	while(!Q.empty()) {
		Vertex* u = Q[0];
		Q.erase(Q.begin());

		for (eit = G.edges.begin(); eit != G.edges.end(); ++eit) {
			if (eit->first.first == u->name) {
				Vertex* v = vertexFind(Q, eit->first.second);
				if (v != NULL && eit->second < v->key) {
					v->pi = u;
					G.vertices[v->name]->pi = u;
					decreaseKey(Q, v, eit->second);
				}
			}
		}
	}

	return;
}

int main()
{
	Graph G;
	int vs, es, vert1, vert2, wt;
	std::string str;
	std::stringstream ss;

	std::cin >> vs;
	std::cin >> es;
	std::cin.ignore();

	for (int i = 0; i < vs; i++) {
		G.vertices.push_back(new Vertex(i));
	}

	for (int i = 0; i < es; i++) {
		std::getline(std::cin, str);

		ss << str;
		ss >> vert1 >> vert2 >> wt;
		ss.clear();

		G.AddEdge(vert1, vert2, wt);
	}

	MSTPrim(G, 0);

	for (int i = 1; i < vs; i++) {
		std::cout << G.vertices[i]->pi->name << std::endl;
	}

	return 0;
}

