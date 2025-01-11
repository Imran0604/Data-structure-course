#include<bits/stdc++.h>
#define inf 1<<30
using namespace std;
int main(){
	freopen("C:/Users/LENOVO/OneDrive/Desktop/Algorithm/flyed warshell.txt","r",stdin);
	int M=25;
	int ne;
	cin>>ne;
	int G[M+1][M+1];
	for(int u=0;u<=25;u++){
		for(int v=0;v<=25;v++){
			if(u==v){
				G[u][v]=0;
				
			}
			else{
				G[u][v]=inf;
			}
		}
	}
	
	int id=0;
	map<char,int>Map;
	for(int i=1;i<=ne;i++){
		char u,v;
		int w;
		cin>>u>>v>>w;
		if(Map.find(u)==Map.end()){
			Map[u]=id;
			id++;
		}
		if(Map.find(v)==Map.end()){
			Map[v]=id;
			id++;
		}
		G[Map[u]][Map[v]]=w;
	}
	for(int k=0;k<=id-1;k++){
		for(int u=0;u<=id-1;u++){
			for(int v=0;v<=id-1;v++){
				if(G[u][k]!=inf && G[k][v]!=inf){
					if(G[u][k]+G[k][v]<G[u][v]){
						G[u][v]=G[u][k]+G[k][v];
					}
				} 
			}
			
					
	}
}
for(int u=0;u<id;u++){
	for(int v=0;v<id;v++){
		cout<<G[u][v] <<" ";
	}
	cout<<endl;
}
return 0;
}
