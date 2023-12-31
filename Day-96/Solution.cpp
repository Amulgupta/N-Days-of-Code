#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x, y, z;
        cin >> x >> y >> z;
        int mx = INT_MIN;
        for (int i = 0; i <= 20; i++)
        {
            for (int j = 0; j <= 20; j++)
            {
                for (int k = 0; k <= 20; k++)
                {
                    if (a * i + b * j + c * k <= 240)
                    {
                        mx = max(mx, x * i + y * j + z * k);
                    }
                }
            }
        }
        cout << mx << endl;
    }

    return 0;
}