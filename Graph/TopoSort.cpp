#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	void toposortUtil(vector<int> adj[],int V,int strt,vector<bool> &vis,stack<int> &st){
	    vis[strt] = true;
	    
	    for(auto node: adj[strt]){
	        if(!vis[node]){
	            toposortUtil(adj,V,node,vis,st);
	        }
	    }
	    
	    st.push(strt);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    stack<int> st;
	    vector<bool> vis(V,false);
	    int strt=0;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	        toposortUtil(adj,V,i,vis,st);
	    
	    }
	    
	    
	vector<int>ans;
	while(!st.empty()){
	    ans.push_back(st.top());
	    st.pop();
	}
	
	return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}