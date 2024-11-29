//Bellman ALgorithm

#include<bits/stdc++.h>
#define inf (1<<30)
using namespace std;
void Bellman_Ford(vector<pair<char, pair<char, int>>> edge, int n, char src, set<char> uv) {
    int dist[122 + 1];
    for (int i = 0; i <= 122; i++) {
        dist[i] = inf;
    }
    dist[src] = 0;
    for (int i = 1; i < n; i++) {
        int l = edge.size();
        for (int k = 0; k < l; k++) {
            pair<char, pair<char, int>> e = edge[k];
            char u = e.first;
            char v = e.second.first;
            int w = e.second.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    set<char> :: iterator i; //scope resolution operator ::
    cout << endl;
    for (i = uv.begin(); i != uv.end(); i++) {
        cout << *i << " : " << dist[*i] << endl;
    }
}

int main() {

    freopen("E:/bell/new.txt", "r", stdin);
    freopen("E:/bell/output.txt", "w", stdout);
    vector<pair<char, pair<char, int>>> edge;
    int ne;
    cout << "Enter the number of edges: ";
    cin >> ne;
    set<char> uv; //unique vertex
    cout << "Enter u,v,w value: " << '\n';
    for (int i = 1; i <= ne; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        uv.insert(u);
        uv.insert(v);
        edge.push_back(make_pair(u, make_pair(v, w)));
    }
    int n = uv.size();
    char src;
    cout << "Enter the source vertex: ";
    cin >> src;
    Bellman_Ford(edge, n, src, uv);

    return 0;
}

/*
9
A B 6
A C 4
A D 5
B E -1
C B -2
D F -1
E F 3
D C -2
C E 3
A
*/
