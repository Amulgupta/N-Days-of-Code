#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
            if(m.size()==n){
                cout<<(n*(n-1))/2<<'\n';
        return;
    }
    long long ans=0,sum=0,x;
    for(int i=0;i<n-1;i++){
        x=n-m[arr[i]]-sum;
        ans+=x;
        m[arr[i]]--;
        sum++;
    }
    cout<<ans<<endl;
}

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--){
        solve();
    }
	return 0;
}
