#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1000;
int parent[MAX_NODES];
int Rank[MAX_NODES];

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	int root_u = Find(u);
	int root_v = Find(v);

	if (root_u != root_v) {
		if (Rank[root_u] < Rank[root_v]) {
			parent[root_u] = root_v;
		} else if (Rank[root_u] > Rank[root_v]) {
			parent[root_v] = root_u;
		} else {
			parent[root_v] = root_u;
			Rank[root_u]++;
		}
	}
}

bool compare(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
	return a.second.second < b.second.second;
}

int main() {
	vector<pair<int, pair<int, int>>> G;
	int ne;
	cout << "Enter the number of edges: ";
	cin >> ne;

	cout << "Enter the edges (u v w):\n";
	for (int i = 0; i < ne; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G.push_back(make_pair(u, make_pair(v, w)));
	}

	sort(G.begin(), G.end(), compare);

	for (int i = 0; i < MAX_NODES; i++) {
		parent[i] = i;
		Rank[i] = 0;
	}

	vector<pair<int, pair<int, int>>> MST;
	int mst_weight = 0;

	for (int i = 0; i < ne; i++) {
		int u = G[i].first;
		int v = G[i].second.first;
		int w = G[i].second.second;

		if (Find(u) != Find(v)) {
			MST.push_back(make_pair(u, make_pair(v, w)));
			mst_weight += w;
			Union(u, v);
		}
	}

	cout << "MST Construction:\n";
	for (auto& edge : MST) {
		cout << "Edge: " << edge.first << " - " << edge.second.first
		     << " - " << edge.second.second << endl;
	}
	cout << "Total Weight of MST: " << mst_weight << endl;

	return 0;
}
