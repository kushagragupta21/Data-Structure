#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool detectCycle(int V,vector<int>g[],vector<bool> &vis,int strt,int par){
   
    vis[strt]=true;
    
    for(auto node: g[strt]){
        if(!vis[node]){
            if(detectCycle(V,g,vis,node,strt)){
                return true;
            }
        } else if(node!=par){
                return true;
            }
    }
    return false;
}
	bool isCycle(int V, vector<int>g[]){
	    int par=-1;
	    int strt=0;
	    vector<bool>vis(V,false);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(detectCycle(V,g,vis,i,par))  
	            return true;
	        }
	    }
	    
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}