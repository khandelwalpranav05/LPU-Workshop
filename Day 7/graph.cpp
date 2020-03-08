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

	void dfsHelper(T node, unordered_map<T, bool> &visited) {

		cout << node << " ";
		visited[node] = true;

		for (T neighbor : adjList[node]) {
			if (visited[neighbor] == false) {
				dfsHelper(neighbor, visited);
			}
		}
	}

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

		unordered_map<T, bool> visited;

		dfsHelper(src, visited);
		cout << endl;
	}

	int connectedComponents() {
		unordered_map<T, bool> visited;

		int components = 0;

		for (auto node : adjList) {

			if (visited[node.first] == false) {
				dfsHelper(node.first, visited);
				components++;
			}

		}

		return components;
	}

	void bfsTopologicalSort() {
		unordered_map<T, int> indegree;

		for (auto node : adjList) {
			indegree[node.first] = 0;
		}

		for (auto node : adjList) {
			for (auto neighbor : node.second) {
				indegree[neighbor]++;
			}
		}

		queue<T> q;

		for (auto node : adjList) {
			if (indegree[node.first] == 0) {
				q.push(node.first);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << "->";

			for (T neighbor : adjList[node]) {
				indegree[neighbor]--;

				if (indegree[neighbor] == 0) {
					q.push(neighbor);
				}
			}
		}

		cout << endl;
	}



};

int main() {

	// Graph<int> g;

	// // g.addEdge(1, 2);
	// // g.addEdge(3, 2);
	// // g.addEdge(4, 2);
	// // g.addEdge(1, 4);
	// // g.addEdge(3, 4);

	// // g.display();

	// g.addEdge(1, 2);
	// g.addEdge(1, 4);
	// g.addEdge(3, 2);
	// g.addEdge(3, 4);
	// g.addEdge(3, 5);
	// g.addEdge(5, 4);
	// g.addEdge(6, 5);

	// g.addEdge(7, 8);
	// g.addEdge(7, 9);
	// g.addEdge(9, 8);


	// g.addEdge(17, 18);
	// g.addEdge(70, 18);


	// g.display();

	// g.bfs(1);

	// cout << "******************" << endl;

	// g.addEdge(15, 4, false);

	// cout << "Starting from 1" << endl;

	// g.bfs(1);

	// cout << "Starting from 15" << endl;

	// g.bfs(15);

	// g.dfs(1);

	// cout << g.connectedComponents() << endl;

	Graph<string> g;

	g.addEdge("Maths", "Programming", false);
	g.addEdge("English", "Programming", false);
	g.addEdge("Programming", "Python", false);
	g.addEdge("Programming", "Java", false);
	g.addEdge("Python", "JS", false);
	g.addEdge("Java", "JS", false);
	g.addEdge("JS", "Web", false);
	g.addEdge("Java", "Web", false);

	g.bfsTopologicalSort();

	return 0;
}