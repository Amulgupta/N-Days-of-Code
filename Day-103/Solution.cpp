#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> v1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        vector<int> v2 = v1;
        sort(v2.begin(), v2.end());
        int ans = n;
        int p = 0;
        for (int i = 0; i < v2.size(); i++)
        {
            if (v1[i] == v2[p])
            {
                p++;
                ans--;
            }
        }
    
        cout << ans << endl;
    }
    return 0;
}
