#include<bits/stdc++.h>
using namespace std;
const int M=122;

vector <char> topological_sort_kahn(vector <char> G[],int indegree[],set <char> V)
{
    queue <char> Q; // o(1)
    set <char> :: iterator k; // o(1)
    for(k=V.begin(); k!=V.end(); k++) // o(n)
    {
        if(indegree[*k]==0)
        {
            Q.push(*k);
        }
    }
    vector <char> topological_order;
    while(!Q.empty())// o(V+E) bfs & topologicaler tc
    {
        char u=Q.front();
        Q.pop();
        //print(u) korle egulo ar access korte parbona pore
        topological_order.push_back(u);//can return any datapye vector or int anything
        int l =G[u].size();
        for(int i=0; i<=l-1; i++)
        {
            char v=G[u][i];
            indegree[v] = indegree[v] -1;
            if(indegree[v]==0)
            {
                Q.push(v);
            }
        }
    }

    return topological_order; //o(v)
}


int main()
{
    int ne;
    cin>> ne;
    vector <char> G[M+1];
    set <char> V;// o(1)
    int indegree[M+1]; //0...m-1 o(1)
    for(int u=0; u<=M; u++)indegree[u] = 0; // o(m)
    for(int i =1; i<=ne; i++) // o(ne)
    {

        char u,v;
        cin>>u>>v;
        G[u].push_back(v);
        V.insert(u);
        V.insert(v);

        indegree[v]++;//indegree[v]=indegree[v]+1
        //indegree[u]++ korte parbona karon u te outdegree hocche indegree na
    }
    vector <char> topological_order =topological_sort_kahn(G,indegree,V); //o(v)+o(v+E)

    int n= topological_order.size();//o(v)
    for(int i=0; i<n; i++) // o(v)
    {
        cout<<topological_order[i]<<" ";
    }
    cout<<endl;

    return 0;
}
