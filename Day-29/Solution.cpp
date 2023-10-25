#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin>>t;
    while(t--)
    { 
        int a, b, c=0, d=0;
        string s;
        cin>>a>>s;
        vector<int> k, x;
        k.push_back(0);
        x.push_back(1);
        for(b=0;b<s.size()-1;b++)
        {
            if((s[b]-'0'==0 && k[b]==0)||(s[b]-'0'==1 && k[b]==1))
                k.push_back(0);
            if((s[b]-'0'==0 && k[b]==1)||(s[b]-'0'==1 && k[b]==0)) 
                k.push_back(1);
            if((s[b]-'0'==0 && x[b]==0)||(s[b]-'0'==1 && x[b]==1))
                x.push_back(0);
            if((s[b]-'0'==0 && x[b]==1)||(s[b]-'0'==1 && x[b]==0)) 
                x.push_back(1);
        }
        c=count(k.begin(),k.end(),1);
        d=count(x.begin(),x.end(),1);
        cout<<max(c,d)<<endl;
    }
	return 0;
}
