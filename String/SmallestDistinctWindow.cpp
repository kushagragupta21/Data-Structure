#include <bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

string findSubString(string str);

int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        cout << findSubString(str).size() << endl;
    }
    return 0;
}




string findSubString(string s)
{
    unordered_map<char,int> mp;
    set<char>st;
    for(int i=0;i<s.length();i++) st.insert(s[i]);
    int n=st.size();
    int i=0;
    int j=1;
    mp[s[i]]++;
    int c=0;
    c++;
    int mi=INT_MAX;
    while(i<=j && j<s.length()){
        if(c<n){
            if(mp[s[j]]==0) c++;
            mp[s[j]]++;
            j++;
        } else if(c==n){
            mi = min(mi,j-i);
            if(mp[s[i]]==1) c--;
            mp[s[i]]--;
            i++;
        }
    }
    while(c==n){
        mi = min(mi,j-i);
        if(mp[s[i]]==1) c--;
        mp[s[i]]--;
        i++;
    }
    
    // cout<<s.substr(i-1,mi);
    return s.substr(i-1,mi);
    
}