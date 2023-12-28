#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        ll X;
        cin>>N>>K>>X;
        vector<ll> A(N);
        for(int i = 0; i < N; i++) {
            cin>>A[i];
        }
        sort(A.begin(), A.end(), greater<ll>());
        ll total_cost = std::accumulate(A.begin(), A.end(), 0ll);
        ll ans = total_cost;
        for(int x = 0; x <= K; x++) {
            ans = min(ans, x*X + total_cost);
            if (x == K) break;
            total_cost -= A[2*x] + A[2*x+1];
        }
        cout<<ans<<endl;
    }
}