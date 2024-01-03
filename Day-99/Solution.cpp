#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

#define ll long long
#define maxn 50005
#define F first
#define S second

using namespace std;

ll res, m;
bool vis[maxn];
int my_hash[maxn], a[maxn];

vector<pair<int, ll>> g[maxn];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int dfs(int curr, int cost)
{
    vis[curr] = true;
    int p = 0;
    for (int i = 0; i < g[curr].size(); i++)
    {
        if (vis[g[curr][i].F] == false)
        {
            p += dfs(g[curr][i].F, g[curr][i].S);
        }
    }
    if (my_hash[curr])
        p++;
    res += cost * (p) * (m - p);
    return p;
}

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        res = 0;
        memset(my_hash, 0, sizeof(my_hash));
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;

        for (int i = 0; i < maxn; i++)
            g[i].clear();

        for (int i = 1; i < n; i++)
        {
            int u, v;
            ll p;
            cin >> u >> v >> p;

            g[u].push_back({v, p});
            g[v].push_back({u, p});
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            my_hash[a[i]] = 1;
        }

        dfs(a[0], 0);
        res *= 2;

        ll g = gcd(res, m * m);

        cout << res / g << " " << (m * m) / g << "\n";
    }
    return 0;
}

