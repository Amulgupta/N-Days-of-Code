#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll unsigned long long int 
ll func(ll p)
{
    ll res = 1;
    ll x = 2;
    while(p)
    {
        if(p % 2)
        {
            res = (res % MOD * x % MOD) % MOD;
            p--;
        }
        else
        {
            x=(x % MOD * x % MOD) % MOD;
            p = p / 2;
        }
    }
    return res % MOD;
}

int main() 
{
	// your code goes here
	ll T;
    cin>>T;
    while(T--)
    {
        ll n, i, j, bit_rep = 0, d, a;
        cin>>n;
        string str;
        while(n > 0)
        {
            d = n % 2;
            str = str + to_string(d);
            n = n / 2;
        }
        reverse(str.begin(),str.end());
        d = 0;
        for(i = 0; i < str.length();i++)
        {
            a = int(str[i]) - 48;
            d = d * 10 + a;
        }
        ll temp = func(d);
        ll ans = (temp * temp) % MOD;
        cout<<ans<<endl;
    }
	return 0;
}

