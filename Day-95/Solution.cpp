#include <iostream>
#include <cstring>

using namespace std;

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m, M, T, num, tot, vis[50][50], v[50][50];
char s[50][50];

inline int read()
{
    int x = 0, f = 1;
    char ch;
    while ((ch = getchar()) && !isdigit(ch))
    {
        if (ch == '-')
            f = -1;
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline bool check(int x, int y)
{
    return (1 <= x) && (1 <= y) && (x <= n) && (y <= m) && (s[x][y] != '#');
}

inline bool dfs(int x, int y)
{
    if (v[x][y])
        return 0;
    v[x][y] = 1;
    for (int d = 0; d < 8; ++d)
    {
        int xx = x + dx[d], yy = y + dy[d];
        if (!check(xx, yy))
            continue;
        if ((vis[xx][yy] == -1) || (dfs(vis[xx][yy] / m, vis[xx][yy] % m + 1)))
        {
            vis[xx][yy] = x * m + y - 1;
            vis[x][y] = xx * m + yy - 1;
            return 1;
        }
    }
    return 0;
}

inline bool work()
{
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (check(i, j) && vis[i][j] == -1 && dfs(i, j))
                return 1;
    return 0;
}

int main()
{
    T = read();
    while (T--)
    {
        num = tot = 0;
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i] + 1;
            for (int j = 1; j <= m; j++)
                if (s[i][j] == '#')
                    ++num;
        }
        memset(vis, -1, sizeof(vis));
        while (work())
            ++tot;
        cout << n * m - num - tot << "\n";
    }
    return 0;
}
