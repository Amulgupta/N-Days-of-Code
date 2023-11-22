#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        int cost[n], weight[n];
        for (int i = 0; i < n; i++) {
            cin >> cost[i] >> weight[i];
        }
        int maxWeight = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int totalCost = 0, totalWeight = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    totalCost += cost[i];
                    totalWeight += weight[i];
                }
            }
            if (totalCost <= k) {
                maxWeight = max(maxWeight, totalWeight);
            }
        }
        cout << maxWeight << endl;
    }
	return 0;
}
