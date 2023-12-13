#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef long long ll;
const int md=1e9+7;

using namespace std;

int modpow(int a,int b,int m) {
    if(b==0) return 1%m;
    int p=modpow(a,b/2,m);
    p=ll(p)*p%m;
    if(b&1) p=ll(p)*a%m;
    return p;
}

int cnt[45];
int main() {
	// your code goes here
	int t;
    cin>>t;
    while(t--) {
        memset(cnt,0,sizeof(cnt));
        int upper,d,m,n;
        cin>>upper>>d>>m>>n;
        for(int i=0;i<n;i++) {
            int mp=modpow(i,d,n);
            if(i<=upper) cnt[mp]+=(upper-i)/n+1;
        }
        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) {
            if((i+j+k)%n==m%n) {
                ans+=ll(ll(cnt[i])*cnt[j]%md)*cnt[k]%md;
                ans%=md;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
