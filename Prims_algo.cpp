#include<bits/stdc++.h>
#define inf (1 << 30)
using namespace std;
struct compare
{
    bool operator() (pair<char,int> a,pair<char,int> b)
    {
        if(a.second<b.second) return 0;
        else return 1;
    }
};


void prims_mst(vector<pair<char,int> > G[], char root)
{
    int M=122;
    bool MST[M+1];
    for(int u=0; u<=122; u++)
	MST[u]=0;
	
    int weight[M+1];
    
    for(int u=0; u<=122; u++)
    
	weight[u]=inf;
	
    weight[root]=0;
    priority_queue<pair<char,int>,vector<pair<char,int> >,compare > pq;
  
    pq.push(make_pair(root,weight[root]));
    int total=0;
    
    while(!pq.empty())
    {
        char u= pq.top().first;
        pq.pop();
        if(MST[u]==1)
		continue;
		
        MST[u]=1;
        total=total+weight[u];
        
        int l=G[u].size();
        for(int i=0; i<=l-1; i++)
        {
            char v= G[u][i].first;
            int w=G[u][i].second;
            if(MST[v]==0 && w<weight[v])
            {
                weight[v]=w;
                pq.push(make_pair(v,weight[v]));
            }
        }

    }
    cout  << total << endl;

}

int main(){
    freopen("C:/Users/LENOVO/OneDrive/Desktop/Algorithm/mst.txt","r",stdin);
    int M=122;
    vector<pair<char,int> > G[M+1];
    int ne;
    cin>>ne;
    for (int i = 0; i < ne; i++)
    {
        char u, v; int w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    char root;
    root='a';

    prims_mst(G,root);


    return 0;

}
