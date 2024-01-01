#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 2002;
int ar[MAX_LEN][MAX_LEN][2];
string s;
int ans;

void sal()
{
    int ll = s.length();
    for (int i = 1; i <= ll; ++i)
    {
        for (int j = 0; j + i <= ll; ++j)
        {
            int l = j, h = j + i - 1;
            if (l == h)
            {
                ar[l][h][0] = 1;
                ar[l][h][1] = 1;
                continue;
            }
            ar[l][h][0] = ar[l + 1][h][0];
            ar[l][h][1] = ar[l + 1][h][1];
            if (s[l] < s[h])
            {
                int tmp = 2 + (l > h ? 0 : ar[l + 1][h - 1][1]);
                if (ar[l][h][0] < tmp)
                    ar[l][h][0] = tmp;
            }
            else if (s[l] > s[h])
            {
                int tmp = 2 + (l > h ? 0 : ar[l + 1][h - 1][0]);
                if (ar[l][h][1] < tmp)
                    ar[l][h][1] = tmp;
            }
            if (ar[l][h][0] < ar[l][h - 1][0])
                ar[l][h][0] = ar[l][h - 1][0];
            if (ar[l][h][1] < ar[l][h - 1][1])
                ar[l][h][1] = ar[l][h - 1][1];
        }
    }
}

string solve2(int l, int h, bool t, int an, map<int, string> &m)
{
    int num = l * 100000 + h * 10 + t;
    if (m.find(num) != m.end())
        return m[num];
    string ret = "";
    if (l > h)
        return "";
    if (l == h)
        return m[num] = s[l];
    if ((s[l] < s[h] && !t) && ar[l][h][t] == 2 + ar[l + 1][h - 1][1 - t])
    {
        string tmp = solve2(l + 1, h - 1, 1 - t, an - 2, m);
        ret = s[l] + tmp + s[h];
    }
    if ((s[l] > s[h] && t) && ar[l][h][t] == 2 + ar[l + 1][h - 1][1 - t])
    {
        string tmp = solve2(l + 1, h - 1, 1 - t, an - 2, m);
        ret = s[l] + tmp + s[h];
    }
    if (ar[l][h][t] == ar[l + 1][h][t])
    {
        string tmp = solve2(l + 1, h, t, an, m);
        if (ret == "" || ret > tmp)
            ret = tmp;
    }
    if (ar[l][h][t] == ar[l][h - 1][t])
    {
        string tmp = solve2(l, h - 1, t, an, m);
        if (ret == "" || ret > tmp)
            ret = tmp;
    }
    return m[num] = ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        sal();
        ans = ar[0][s.length() - 1][0];
        map<int, string> m;
        cout << solve2(0, s.length() - 1, 0, ans, m) << endl;
    }
    return 0;
}
