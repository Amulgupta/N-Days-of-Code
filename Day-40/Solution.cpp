#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<string> v;
        string ans = "";
        for(int i = 0; i < n; ++i) {
          string s;
          cin >> s;
          if(s[i] == '0') {
    	ans = ans + "1";
          } else {
    	ans = ans + "0";
          }
        }
        cout << ans << endl;
      }
	return 0;
}
