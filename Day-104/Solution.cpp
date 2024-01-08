#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    // your code goes here
    vector<ll> cubes;
    for (ll i = 1; i <= 1010000; i++)
        cubes.push_back(i * i * i);
    ll T;
    cin >> T;
    while (T--)
    {
        ll x;
        cin >> x;
        ll l = 1;
        ll r = 2e9;
        ll ans;
        while (l <= r)
        {
            ll mid = (r + l) / 2;
            ll temp = upper_bound(cubes.begin(), cubes.end(), mid * mid) - cubes.begin();
            ll curr = mid - temp;
            if (curr >= x)
            {
                ans = mid * mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
