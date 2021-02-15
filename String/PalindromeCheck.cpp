 
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int l=0,h=S.size()-1;
	    
	    while(l<=h){
	        if(S[l]!=S[h]){
	            return 0;
	        }
	        l++;
	        h--;
	    }
	    return 1;
	}

};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  