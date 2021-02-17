#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool CycleDetect(vector<int> adj[],int V,int strt,vector<bool> &ansc,vector<bool> &vis){
        vis[strt]=true;
        ansc[strt]=true;
        
        for(auto node : adj[strt]){
            if(!vis[node]){
                if(CycleDetect(adj,V,node,ansc,vis)) return true;
            } else if(ansc[node]) return true;
        }
        ansc[strt]=false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	
	   	vector<bool> ansc(V,false);
	   	vector<bool> vis(V,false);
	   	int strt=0;
	   	
	   	for(int i=0;i<V;i++){
	   	    if(!vis[i]){
	   	        if(CycleDetect(adj,V,i,ansc,vis)){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	   	
	}
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
