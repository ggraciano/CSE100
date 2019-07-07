
/* References:
 * 	Introduction to Algorithms by Thomas H. Cormen et al.
 * 		Page 595: BFS(G,s)
 * 	www.cplusplus.com/reference/list/list/
 * 	www.cplusplus.com/reference/map/map/
 */

#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

#include <algorithm>
#include <sstream>

using namespace std;

struct Vertex {
	string name;
	string color;
	int d;
	Vertex *v;

	Vertex(string name, string color) {
		this->name = name;
		this->color = color;
		d = 0;
		v = NULL;
	}
};

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;

    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }

    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
	edges.insert(pair<pair<string, string>, int>(pair<string, string>(vert1, vert2), weight));

	return;
}

bool Graph::FindVertex(string vert1) {
	if (find(vertices.begin(), vertices.end(), vert1) != vertices.end()) {
		return true;
	}

	return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
	if (edges.find(pair<string, string>(vert1, vert2)) != edges.end()) {
		return IsReachable(vert1, vert2);
	}

	return -1;
}

int Graph::IsReachable(string vert1, string vert2) {
	return edges.find(pair<string, string>(vert1, vert2))->second;
}

int BreadthFirstSearch(Graph G, string vert1, string vert2)
{
	map<string, string> vM;
	queue<Vertex*> vQ;

	list<string>::iterator it;
	map<string, string>::iterator vit;
	map<pair<string, string>, int>::iterator eit;

	for (it = G.vertices.begin(); it != G.vertices.end(); ++it) {
		vM.insert(pair<string, string>(*it, "WHITE"));
	}

	Vertex *s = new Vertex(vert1, "GRAY");
	vQ.push(s);

	while (!vQ.empty()) {
		Vertex *u = vQ.front();
		vQ.pop();

		if (u->name == vert2) {
			return u->d;
		}

		for (eit = G.edges.begin(); eit != G.edges.end(); ++eit) {
			if (eit->first.first == u->name) {
				if (vM.find(eit->first.second)->second == "WHITE") {
					Vertex *v = new Vertex(eit->first.second, "GRAY");
					v->d = u->d + 1;
					v->v = u;
					vQ.push(v);
				}
			}
		}

		vit = vM.find(u->name);
		vit->second = "BLACK";
	}

	return -1;
}

int NumberOfEdges(Graph G, string vert1, string vert2)
{
	if (!G.FindVertex(vert1) || !G.FindVertex(vert2)) {
		return -1;
	}
	if (vert1 == vert2) {
		return 0;
	}

	return BreadthFirstSearch(G, vert1, vert2);
}

int main() {
    Graph G;

	int wt, oc;
	string str1, str2;
	stringstream ss;

	getline(cin, str1);

	while (str1 != "END") {
		G.vertices.push_back(str1);
		getline(cin, str1);
	}

	getline(cin, str1);

	while (str1 != "END") {
		ss << str1;
		ss >> str1 >> str2 >> wt;
		ss.clear();

		if (G.FindVertex(str1) && G.FindVertex(str2)) {
			G.AddEdge(str1, str2, wt);
		}

		getline(cin, str1);
	}

	G.PrintOut();

	getline(cin, str1);

	while (str1 != "0") {
		ss << str1;
		ss >> oc;

		if (oc == 1) {
			ss >> str1;
			cout << G.FindVertex(str1) << endl;
		} else if (oc == 2) {
			ss >> str1 >> str2;
			cout << G.FindEdgeCost(str1, str2) << endl;
		} else {
			ss >> str1 >> str2;
			cout << NumberOfEdges(G, str1, str2) << endl;
		}

		ss.clear();

		getline(cin, str1);
	}

	return 0;
}
