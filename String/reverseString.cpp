#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=0,r=s.length()-1;
    while (l<=r)
    {
        swap(s[l],s[r]);
        l++;r--;
    }

    cout<<s<<" ";
    
}