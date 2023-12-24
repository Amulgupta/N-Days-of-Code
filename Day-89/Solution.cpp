#include <bits/stdc++.h>
using namespace std;
vector<int> prime(10000000, 1);
vector<int> ans(10000000, 0);
void isPrime()
{
    int c = 0;
    for (int p = 2; p * p <= 10000000; p++)
        if (prime[p] == 1)
            for (int i = p * 2; i <= 10000000; i += p)
            {
                prime[i] = 0;
            }
    for (int p = 2; p <= 10000000; p++)
    {
        ans[p] = ans[p - 1] + prime[p];
    }
}
void solve()
{
    long long a, b;
    cin >> a >> b;
    if (a == 1 and b == 2)
    {
        cout << 1 << endl;
        return;
    }
    else if (a == 1 and b == 3)
    {
        cout << 2 << endl;
        return;
    }
    else if (a == 2 and b == 3)
    {
        cout << 1 << endl;
        return;
    }
    int count = 0;
    int p1 = ans[a + 1];
    int p2 = ans[b];
    int to = p2 - p1;
    count = (b - a) - to;
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    isPrime();
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}