// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
 
int countPS(string str);
 
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}


int func(int i,int j,string s,vector<vector<int> >& dp){
    if(i>j) return 0;
    if(i==j) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s[i]==s[j]) return dp[i][j] = func(i+1,j,s,dp) + func(i,j-1,s,dp) +1;
    
    else return dp[i][j] = func(i+1,j,s,dp) + func(i,j-1,s,dp) - func(i+1,j-1,s,dp);
}

int countPS(string str)
{
   int n=str.length();
   vector<vector<int > > dp(n,vector<int>(n,-1));
   
   return func(0,n-1,str,dp);
}
 