#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, a[N], b[N];

void solution() {
	cin >> n >> q;
	unordered_map<int, int> mp;
	for(int i = 0; i < n; ++i) cin >> a[i], mp[a[i]] = i, b[i] = a[i];
	sort(b, b + n);

	while(q--) {
		int qr;
		cin >> qr;
		int pos = mp[qr], v = 0, gr = 0, sm = 0, tsm = 0, tgr = 0, lo = 0, hi = n - 1;
		int tmp = lower_bound(b, b + n, qr) - b;

		if(tmp >= n) {
			cout << "-1\n";
			continue;
		}

		while(lo < hi) {
			int md = (lo + hi) / 2;
			if(pos == md) break;
			if(pos < md) {
				gr++;
				if(a[md] < qr) tgr++;
				hi = md - 1;
			}
			else {
				sm++;
				if(a[md] > qr) tsm++;
				lo = md + 1;
			}
		}

		if(tmp < sm || n - 1 - tmp < gr)
			cout << "-1\n";
		else
			cout << min(tsm, tgr) + abs(tsm - tgr) << "\n";
	}
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
		solution();
	return 0;
}
