#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int graph[4][4],visited[4],cost=0;
int find_next_node(int node){
	int nd,min=INT_MAX,min_index,democost;
	for(int i=0;i<4;i++){
		if(!visited[i] && graph[node][i]!=0 && graph[node][i]<min){
			democost=graph[node][i];
			min=graph[node][i];
			min_index=i;
		}
	}
	nd=min_index;
	cost=cost+democost;
	return nd;
}
void TSP(int node){
	int next_node;
	visited[node]=1;
	cout<<node<<"->";
	next_node=find_next_node(node);
	if(next_node==INT_MAX){
		int v=0;
		cost=cost+graph[next_node][v];
		return;
	}
	TSP(next_node);
	cout<<cost;
}
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>graph[i][j];
		}
	}
	memset(visited,0,sizeof(visited));
	int start;
	cout<<"enter start node\n";
	cin>>start;
	TSP(start);
	cout<<cost;
}
