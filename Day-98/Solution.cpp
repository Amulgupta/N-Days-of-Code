#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N, X;
	cin >> N >> X;

	if (X == 1)
	{
		for (int i = 1; i <= N; i++)
		    cout << i << ' ';
		cout << endl;
		return;
	}
	if (X == N)
	{
		for (int i = N; i > 0; i--)
			cout << i << ' ';
		cout << endl;
		return;
	}

	if (N % 2 == 1 && (N + 1) / 2 == X)
	{
		cout << -1 << endl;
		return;
	}

	int A[N];

	for (int i = 0; i < N; i++)
	{
		A[i] = i + 1;
	}

	swap(A[0], A[X - 1]);
	swap(A[N - 1], A[N - X]);
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
