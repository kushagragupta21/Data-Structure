#include <bits/stdc++.h>
using namespace std;
void printPalindrome(string s,int l,int h){
    for(int i=l;i<=h;i++) cout<<s[i];
}

void LongPalindrome(string s){
    
    int l,h;
    int start=0,end=1;
    
    for(int i=1;i<s.length();i++){
        
        //even substring
        l=i-1;
        h=i;
        
        while(l>=0 && h<s.length() && s[l]==s[h]){
            if(h-l+1 > end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
        
        //odd substring
        
        
        l=i-1;
        h=i+1;
        
        while(l>=0 && h<s.length() && s[l]==s[h]){
            if(h-l+1 > end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
    }
    
    printPalindrome(s,start,start+end-1);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
	LongPalindrome(s);
	cout<<endl;
	}
	return 0;
}