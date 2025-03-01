#include <bits/stdc++.h>
#define M (10<<7)
using namespace std;

vector<int> G[M + 1];
int stopwatch = 0;
int color[M + 1];
int entry[M + 1];
int finish[M + 1];

void DFS(int u) {
    color[u] = 1;
    stopwatch++;
    entry[u] = stopwatch;
    cout << "Visited node " << u << " at time " << entry[u] << '\n';
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (color[v] == 0) {
            DFS(v);
        }
    }
    stopwatch++;
    finish[u] = stopwatch;
    cout << "Finished visiting all descendants of node " << u << " at time " << finish[u] << '\n';
}

int main() {
    for (int u = 0; u <= M; u++) {
        color[u] = 0;
    }

    int n;
    cout << "Enter the number of edges: ";
    cin >> n;

    cout << "Enter the edges:" << '\n';
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    DFS(src);

    return 0;
}
