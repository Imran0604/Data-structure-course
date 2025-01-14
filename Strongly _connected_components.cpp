#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<int> &visited, stack<int> &order, vector<int> adj[]) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, visited, order, adj);
        }
    }
    order.push(node);
}

void dfs2(int node, vector<int> &visited, vector<int> adj[], vector<int> &component) {
    visited[node] = 1;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, visited, adj, component);
        }
    }
}

int main() {
    int E;
    cin >> E;

    map<int, vector<int>> adj, adjT;
    set<int> nodes;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }

    stack<int> order;
    vector<int> visited(1000, 0); // Assuming node values are in the range [0, 999]

    for (int node : nodes) {
        if (!visited[node]) {
            dfs1(node, visited, order, adj);
        }
    }

    for (int i = 0; i < visited.size(); i++) {
          visited[i] = 0;
    }
    vector<vector<int>> sccs;

    while (!order.empty()) {
        int node = order.top();
        order.pop();

        if (!visited[node]) {
            vector<int> component;
            dfs2(node, visited, adjT, component);
            sccs.push_back(component);
        }
    }

    int component_id = 1;
    for (const auto &component : sccs) {
        cout << "Component " << component_id++ << ": {";
        for (size_t i = 0; i < component.size(); i++) {
            cout << component[i];
            if (i != component.size() - 1) cout << ", ";
        }
        cout << "}\n";
    }

    return 0;
}
