#include <bits/stdc++.h>
#define M (10<<7)
#define inf (10<<7)
using namespace std;

int main() {
    vector<int> G[M + 1];
    int color[M + 1];
    int level[M + 1];
    for (int i = 0; i <= M; i++) {
        color[i] = 0;
        level[i] = -1;
    }
    int ne;
    cout << "Number of edges: ";
    cin >> ne;
    for (int i = 0; i < ne; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << "Adjecency graph by list:" << endl;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            if (G[i][j] != inf) {
                cout << G[i][j] << " ";
            } cout << endl;
        }
    }
    int src;
    cout << "Source Vertex: ";
    cin >> src;

    queue<int> Q;
    color[src] = 1;
    level[src] = 0;
    Q.push(src);
    while (!Q.empty()) {
        int u = Q.front();
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (color[v] == 0) {
                color[v] = 1;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    cout << "Level" << endl;
    for (int i = 0; i <= M; i++) {
        if (level[i] != -1) {
            cout << "Node:" << i << " level:" << level[i] << endl;
        }
    }
}
