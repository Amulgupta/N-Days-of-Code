#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define ll long long
#define F  first
#define S  second
#define pb  push_back

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


inline void cp() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

}



const int mod = 1e9 + 7;



void solve() {
	int n, k;
	cin >> n >> k;
	long long int ans1 = 0, ans2 = 0;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	vector<int> m;
	int x = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (a[x] == i) x++;
		else m.pb(i);
	}

	for (int i = 0 ; i < k ; i++) ans1 += max(0, a[n - 1] - m[i]);
	for (int i = 0 ; i < k - 1 ; i++) ans2 += max(0, 2 * n - m[i]);

	cout << max(ans1, ans2) << "\n";
}

int main() {
	// your code goes here
	cp();
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
