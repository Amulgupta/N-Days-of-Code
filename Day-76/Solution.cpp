#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int

using namespace std;

int main() {
	// your code goes here
	ll T, m, n, i, j, k, l, f, ct, p;
    cin>>T;
    while(T--)
    {
        f = 1; ct = 0;
        cin>>n;
        string s = to_string(n);
        l = s.length();
        for(i = 2; i <= l; i++){
            f *= i;
        }
        for(i = 0; i < l-1; i++)
        {
            p=1; 
            map<char,ll>mp, mp1;
            for(j = i; j < l; j++)
            {
                mp[s[j]]++;
                p *= mp[s[j]];
            }
            for(j = i; j < l; j++)
            {
                if(int(s[j]) < int(s[i]) && mp1[s[j]] != 7)
                { 
                    ct += ((f/(l-i))/(p/mp[s[j]]));
                    mp1[s[j]] = 7;
                }
            }
            f = f/(l-i);
        }
        cout<<ct+1<<endl;
    }
	return 0;
}
