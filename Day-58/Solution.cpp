#include <bits/stdc++.h>
#define ll long long
#define llinf LLONG_MAX
#define llminf LLONG_MIN
#define inf INT_MAX
#define minf INT_MIN
const long long mod = 1e9 + 7;

using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        vector <ll> v0,v1;
        for (int i = 0;i<n;i++) 
        {
            ll ai;
            cin >> ai;
            if (i%2==0) v0.push_back(ai);
            else v1.push_back(ai);
        }
        sort(v0.rbegin(),v0.rend());
        sort(v1.begin(),v1.end());
        ll ans = 0;
        for (int i = 0;i<v0.size();i++) 
        {
            for (int j = i;j<v1.size();j++) 
            {
                ans+=v0[i]*v1[j];
            }
        }
        for (int i = 0;i<n;i++) 
        {
            if (i%2==0) cout << v0[i/2] << " ";
            else cout << v1[i/2] << " ";
        }
        cout << endl;
        cout << ans << endl;
    }
	return 0;
}
