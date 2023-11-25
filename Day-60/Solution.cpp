#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
    while (T--) {
        int N; 
        long long K; 
        cin >> N >> K;
        vector<string> A(N), B(N);
        for (int i = 0; i < N; i++) 
            cin >> A[i];
        for (int i = 0; i < N; i++) 
            cin >> B[i];
        string ans = "YES";

        for (int i = 0; i < N; i++) {
            if (A[i].size() != B[i].size()) ans = "NO";
        }
        
        vector<int> dif(10, 0);
        for (string x : A) {
            for (char d : x) dif[d - '0']++;
        }
        for (string x : B) {
            for (char d : x) dif[d - '0']--;
        }

        long long reqd = 0;
        for (int x : dif) {
            if (x > 0) reqd += x;
        }
        
        if (reqd > K) 
            ans = "NO";
        cout << ans << endl;
    }
	return 0;
}
