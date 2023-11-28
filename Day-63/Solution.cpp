#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
	// your code goes here
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n;
	    cin>>n;
	    ll arr[n], xorr=0;
	    ll pre[n]={0};
	    ll suf[n]={0};
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	        xorr^=arr[i];
	    }
	    ll ans=10000000000;
	    for(int i=0; i<n; i++)
	    {
	        ans=min(abs(arr[i]-(arr[i]^xorr)),ans);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
