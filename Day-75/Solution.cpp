#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long power(long long x,long long y)
{
    long long res=1;
    x=x%mod;
    while(y>0)
    {
        if (y&1)
            res=(res*x)%mod;
        y = (y>>1);
        x = (x*x)%mod;
    }
    return res % mod;
}

int main() {
	// your code goes here
	int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> v(n);

        for(int i=0;i<n;i++)
        cin>>v[i];
        sort(v.begin(),v.end() );

        long long res=1;
        long long int c[5001][5001]={0};
        for(int i=0;i<5001;i++)
        {
          for(int j=0;j<i+1;j++)
            {
             if(j==0||j==i)
             c[i][j]=1LL;
             else
             c[i][j]=(c[i-1][j-1]%(mod-1)+c[i-1][j]%(mod-1))%(mod-1);
            }
        }
        for(int i=1;i<n-1;i++)
        {
            long long ans=0;
            for(int j=1;j<k-1;j++){
                ans+=c[i][j]*c[n-i-1][k-j-1];
                ans=ans%(mod-1);
            }
            res=(res*power(v[i],ans))%mod;
            
        }
        cout<<res%mod<<endl;
    }
	return 0;
}
