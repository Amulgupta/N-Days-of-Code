#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf LLONG_MAX

int main() {
	// your code goes here
	 int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        long long a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = 0LL;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i][i];
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            u--, v--;
            a[u][v] = d;
        }

        long long upd[n][n];
        for (int i = 0; i < n; i++)
        {
            upd[i][i] = a[i][i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            upd[i][i + 1] = a[i][i + 1] + upd[i][i] + upd[i + 1][i + 1];
        }

        for (int d = 2; d < n; d++)
        {
            for (int i = 0; i < n - d; i++)
            {
                upd[i][i + d] = a[i][i + d] + upd[i][i + d - 1] + upd[i + 1][i + d] - upd[i + 1][i + d - 1];
            }
        }
        vector<long long> dp[n + 1];
        dp[0].push_back(0LL);
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i];
            for (int j = 0; j <= i; j++)
            {
                for (auto it : dp[max(j - 1, 0)])
                    dp[i + 1].push_back(upd[j][i] + it);
            }

            sort(dp[i + 1].begin(), dp[i + 1].end(), [](long long a, long long b) -> bool
                 { return a > b; });
            while (((int)dp[i + 1].size()) > k)
                dp[i + 1].pop_back();
        }

        for (auto it : dp[n])
            cout << it << " ";
        cout << endl;
    }
	return 0;
}
