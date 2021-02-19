#include <bits/stdc++.h>
// Approach is BFS Checking all parts 
using namespace std;
    int X[] = {-1,-1,-1,0,0,1,1,1};
    int Y[] = {-1,0,1,-1,1,-1,0,1};
bool solve(int i,int j,string s,vector<vector<char> > &grid,int size,int ind,int n,int m){
    if(grid[i][j] != s[0]) return false;
    
    for(int dir=0;dir<8;i++){
        int k,rd= i+X[dir],cd=j+Y[dir];
        
        for(k=1;k<size;k++){
            if(rd >=n || rd <0 || cd >=m ||cd<0) break;
            if(grid[rd][cd] != s[k]) break;
            
            rd+=X[dir], cd+=Y[dir];
        }
        if(k==size) return true;
    }
    return false;
    
}
int main() {
	//code
	int tc;
	cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        // char grid[n][m];
        vector<vector<char> > grid(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin>>x;
                grid[i][j]=x;
            }
        }
        string s;
        cin>>s;
        int size=s.length();
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,s,grid,size,0,n,m))
                ans.push_back({i,j});
                // cout<<i<<" "<<j<<",\n";
            }
            // cout<<"\n";
        }
        
        if(ans.size()==0){
            cout<<-1;
        }else{
        for(auto it : ans){
            cout<<it.first<<" "<<it.second<<",";
            // cout<<endl;
        }
        }
        cout<<"\n";
    }
	return 0;
}