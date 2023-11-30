#include <bits/stdc++.h>
using namespace std;

int dp[35][35];
unordered_map<string, bool> ex;

int grundy(string &str, int i, int j) {
    if (i > j)
        return 0;
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    set<int> ss;
    for (int l = i; l <= j; ++l) {
        string s;
        for (int r = l; r <= j; ++r) {
            s += str[r];
            if (ex[s])
                ss.insert(grundy(str, i, l - 1) ^ grundy(str, r + 1, j));
        }
    }
    for (int z = 0; z <= ss.size(); ++z)
        if (ss.find(z) == ss.end())
            return ret = z;
}


int main() {
	// your code goes here
	int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof dp);
        string str, s;
        int n;
        cin >> str >> n;
        ex.clear();
        while (n--) {
            cin >> s;
            ex[s] = 1;
        }

        cout << (grundy(str, 0, str.size() - 1) ? "Teddy" : "Tracy") << endl;
    }
	return 0;
}
