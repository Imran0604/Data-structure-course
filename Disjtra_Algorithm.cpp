//Disjtra Algorithm

#include<bits/stdc++.h>
using namespace std;

#define infinity (1<<30)

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int dijkstra(vector<pair<int, int>> G[], int source, int destination) {
	int M = 8;
	int dist[M + 1];
	for (int i = 0; i <= M; i++) {
		dist[i] = infinity;
	}
	dist[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q; // Fixed priority_queue syntax

	Q.push(make_pair(source, dist[source]));

	while (!Q.empty()) {
		pair<int, int> u = Q.top();
		Q.pop();

		int l = G[u.first].size();

		for (int i = 0; i <= l - 1; i++) {
			pair<int, int> v = G[u.first][i];
			if (dist[u.first] + v.second < dist[v.first]) {
				dist[v.first] = dist[u.first] + v.second;

				Q.push(make_pair(v.first, dist[v.first]));
			}
		}
	}
	return dist[destination];
}

int main() {
	vector<pair<int, int>> G[10];
	int ne;
	cout << "Enter the number of edges: ";
	cin >> ne;

	for (int i = 1; i <= ne; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}

	int source, destination;
	cout << "Enter source and destination: ";
	cin >> source >> destination;

	int ans = dijkstra(G, source, destination);
	cout << "The shortest path distance = " << ans  << "\n";

	return 0;
}
