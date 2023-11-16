#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;
    while(T--)
    {
        long long n,r;
        cin>>n>>r;
        vector<pair<long long,long long>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].second;
        }
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            v[i].first=v[i].second-v[i].first;
        }
        sort(v.begin(),v.end());
        long long count=0;
        int idx=0;
        while(r>0 && idx<n)
        {
            long long curr=r-v[idx].second;
            if(curr<0)
            {
                idx++;
                continue;
            }
            long long ex=(curr)/v[idx].first;
            count+=ex+1;
            r-=(ex+1)*v[idx].first;
            idx++;
        }
        cout<<count<<endl;
    }
	return 0;
}
