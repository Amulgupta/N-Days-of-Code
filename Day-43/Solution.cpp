#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
    while(T--){
        long long N;
        cin>>N;
        map<long long, long long>m;
        for(long long i = 0; i < N; i++)
        {
            long long x;cin>>x;
            m[log2(x)+1]++;
        }
        long long count=0;
        for(auto it:m){
            count += (it.second) * ((it.second) - 1)/2;
        }
        cout<<count<<endl;
    }
	return 0;
}
