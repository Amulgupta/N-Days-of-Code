#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,i,j,d,pos,k,res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        ll dp1[n], dp2[n], a[n], ma1[n], ma2[n];
        for(i=0; i<n; i++) cin >> a[i];
        dp1[0]=a[0];
        dp2[n-1]=a[n-1];
        ma1[0]=a[0];
        ma2[n-1]=a[n-1];
        for(i=1; i<n; i++){
            dp1[i]=max(a[i], a[i] + dp1[i-1]);
            ma1[i]=max(dp1[i], ma1[i-1]);
        }
        for(i=n-2; i>=0; i--){
            dp2[i]=max(a[i], a[i] + dp2[i+1]);
            ma2[i]=max(dp2[i], ma2[i+1]);
        }
        res=ma1[0]+ma2[1+k];
        for(i=0; i<=n-2-k; i++)
            res=max(ma1[i] + ma2[i+1+k], res);
        cout << res << endl;
    }
}
