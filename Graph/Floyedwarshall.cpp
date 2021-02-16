#include <bits/stdc++.h>
#define INF -1
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int v;
	    cin>>v;
	    int graph[v][v];
	    
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            
	            cin>>graph[i][j];
	        }
	    }
	    
	    int dist[v][v];
	    
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            
	            dist[i][j]=graph[i][j];
	        }
	    }
	    
	    for(int k=0;k<v;k++){
	        for(int i=0;i<v;i++){
	            for(int j=0;j<v;j++){
	                if(dist[i][k]==10000000  && dist[k][j]==10000000  ) continue;
	                if( dist[i][k]+dist[k][j] < dist[i][j]){
	                    dist[i][j] = dist[i][k] + dist[k][j];
	                }
	            }
	        }
	    }
	    
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            if(dist[i][j]==10000000 ) cout<<"INF"<<" ";
	            else cout<<dist[i][j]<<" ";
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}