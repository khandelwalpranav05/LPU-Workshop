#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

template <typename T>
class Graph {

	unordered_map<T, list<T> > adjList;

public:

	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);

		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void display() {

		for (auto node : adjList) {
			cout << node.first << " -> ";

			for (auto val : node.second) {
				cout << val << ",";
			}
			cout << endl;
		}
	}

	void bfs(T src) {

		queue<T> q;
		unordered_map<T, bool> visited;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (T neighbor : adjList[node]) {
				if (visited[neighbor] == false) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		cout << endl;
	}

	void dfs(T src) {



	}

};

int main() {

	Graph<int> g;

	// g.addEdge(1, 2);
	// g.addEdge(3, 2);
	// g.addEdge(4, 2);
	// g.addEdge(1, 4);
	// g.addEdge(3, 4);

	// g.display();

	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(5, 4);
	g.addEdge(6, 5);

	g.display();

	g.bfs(1);

	cout << "******************" << endl;

	g.addEdge(15, 4, false);

	cout << "Starting from 1" << endl;

	g.bfs(1);

	cout << "Starting from 15" << endl;

	g.bfs(15);

	return 0;
}