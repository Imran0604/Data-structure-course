#include<bits/stdc++.h>
using namespace std;

vector<string> topological_sort_kahn(map<string, vector<string>>& G, map<string, int>& indegree, set<string>& V) {
    queue<string> Q;
    for (const auto& course : V) {
        if (indegree[course] == 0) {
            Q.push(course);
        }
    }
    
    vector<string> topological_order;
    while (!Q.empty()) {
        string u = Q.front();
        Q.pop();
        topological_order.push_back(u);
        for (const string& v : G[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                Q.push(v);
            }
        }
    }
    return topological_order;
}

int main() {
    int ne;
    cin >> ne;
    
    map<string, vector<string>> G;
    set<string> V;
    map<string, int> indegree;
    
    for (int i = 0; i < ne; ++i) {
        string u, v;
        cin >> u >> v;
        G[u].push_back(v);
        V.insert(u);
        V.insert(v);
        indegree[v]++;
        if (indegree.find(u) == indegree.end()) {
            indegree[u] = 0;
        }
    }

    vector<string> topological_order = topological_sort_kahn(G, indegree, V);
    
    for (const string& course : topological_order) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}
