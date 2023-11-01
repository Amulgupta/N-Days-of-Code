#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
	    int N, P;
	    cin>>N>>P;
	    if (P < 3) {
	        cout << "impossible"<<endl;
	    }
	    else {
	        string ans = "";
	        ans += 'a';
	        for (int i = 1; i < P - 1; i++) {
	            ans += 'b';
	        }
	        ans += 'a';
	        
	        if (N == P) {
	            cout << ans << endl;
	        }
	        else {
	            for (int i = 0; i < N / P; i++) {
	                cout << ans;
	            }
	            cout << endl;
	        }
	    }
	}
	return 0;
}
