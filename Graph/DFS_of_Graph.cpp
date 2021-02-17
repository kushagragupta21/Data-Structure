#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
void dfs(int V,vector<int> adj[],vector<bool>& vis,int strt,vector<int> &ans){
    ans.push_back(strt);
    vis[strt]=true;
    
    for(auto it: adj[strt]){
        if(!vis[it]){
            dfs(V,adj,vis,it,ans);
            
        }
    }
    
}
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    
	   // bool visited[V]={0};
	   vector<bool> vis(V,false);
	    int strt=0;
	    vector<int>ans;
	    dfs(V,adj,vis,strt,ans);
	    return ans;
	}
	
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}