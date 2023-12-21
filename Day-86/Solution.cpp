#include <bits/stdc++.h>
using namespace std;

#define int int long long
#define fr(i, n) for (int i = 0; i < n; i++)
#define fr1(i, n) for (int i = 1; i <= n; i++)
#define S second
#define F first
#define pb(n) push_back(n)
#define endl "\n"
#define pr pair<int, int>
#define so(a) sort(a.begin(), a.end())
#define intv vector<int>
int mod = 1e9 + 7;
int mod1 = -1 * mod;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int timer = 0, n, m, t, k, eq = 0;



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        fr(i, n)
        {
            cin >> a[i];
        }
        int f = 0;
        int bit;
        vector<pair<int, int>> ans;
        fr(j, 32)
        {
            int sum = 0;
            int cnt = 0;
            fr(i, n)
            {
                sum += a[i];
                if (sum & (1 << j))
                {
                    sum = 0;
                    cnt++;
                }
            }
            if (cnt > 1)
            {

                int p1 = 0;
                int check = sum;
                sum = 0;
                fr(i, n)
                {
                    sum += a[i];
                    if (sum & (1 << j))
                    {
                        ans.push_back({p1, i});
                        p1 = i + 1;
                        sum = 0;
                    }
                }
               
                    ans[ans.size() - 1].second = n - 1;
                
                break;
            }
        }
        if (ans.size())
        {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                cout << i.F + 1 << " " << i.S + 1 << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
