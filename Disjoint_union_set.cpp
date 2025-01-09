#include<bits/stdc++.h>
using namespace std;
const int M = 500;

int parent[M + 1];
int Rank[M + 1];

int Find(int u) {
	if (parent[u] == u) return u;
	else {
		return parent[u] = Find(parent[u]);
	}
}

void union_set(int root_u, int root_v) {

	if (Rank[root_u] == Rank[root_v]) {
		parent[root_v] = root_u;
		Rank[root_u]++;
	}
	else if (Rank[root_u] > Rank[root_v]) {
		parent[root_v] = root_u;
	}
	else {
		parent[root_u] = root_v;
	}
}


int main() {
	freopen("C:/Users/User/Downloads/Algorithm/union_input.txt", "r", stdin);

	for (int u = 0; u <= M; u++) //O(M)
	{
		parent[u] = u;
		Rank[u] = 0;
	}
	int ne; //O(1)
	cin >> ne;

	for (int i = 1; i <= ne; i++)
	{
		int u, v;
		cin >> u >> v;

		int root_u = Find(u);
		int root_v = Find(v);

		if (root_u == root_v)
		{
			cout << "The G contains cycle" << endl;
			break;
		}
		else
		{
			union_set(root_u, root_v);
		}
	}

	return 0;
}
