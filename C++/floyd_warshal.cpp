// this algorithm is used to find the shortest distance between all pair of vertices
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9+1;
const int N = 100;
int dist[N][N];

void floyd_warshal(int n){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] == INF){
                    cout<<"I"<<" ";
                }
                else{
                cout<<dist[i][j]<<" ";}
                
            }
            cout<<endl;
        }
}
int main()
{   
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
            
    }
    // graph input;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y, wt;
        cin>>x>>y>>wt;
        dist[x][y] = wt;
    }
    floyd_warshal(n);
    return 0;
}

