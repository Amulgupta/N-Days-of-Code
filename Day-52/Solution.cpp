#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >>T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<int> max_left(n), max_right(n);
        max_left[0] = A[0];
        max_right[n - 1] = A[n - 1];
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], A[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            max_right[i] = max(max_right[i + 1], A[i]);
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += min(max_left[i], max_right[i]);
        }
        cout << sum <<endl;
    }
	return 0;
}
