#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll n)
{
	string s = to_string(n);
	bool ok = true;
	for (auto e : s)
	{
		if (e != '9' and e != '4' and e != '0' and e != '1')
		{
			ok = false;
			break;
		}
	}
	return ok;
}
vector<ll> num;
void precompute()
{
	for (long long  i = 1; i <= 100009; i++)
	{
		ll sq = i * i;
		if (check(sq))
			num.push_back(sq);
	}
}


void Traverser()
{
	ll a, b;
	cin >> a >> b;
	int ans = 0;
	for (auto e : num)
		if (e >= a and e <= b)
			ans++;
	cout << ans << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll TC;
	TC = 1;
	precompute();
	cin >> TC;

	while (TC--)
	{
		Traverser();
	}
	return 0;
}
