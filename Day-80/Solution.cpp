#include <bits/stdc++.h>
using namespace std;

int T, n, K, head[1<<17], tail[1<<17];
string str;

int main() {
	// your code goes here
	cin>>T;
    while(T--){
        cin>>n>>K>>str;
        for(int j = 1 ; j < n ; j++) {
            if (str[j - 1] == '1')
                head[j] = head[j - 1] + 1;
            else head[j] = 0;
        }
 
        for(int j = n - 2 ; j >= 0 ; j--) {
            if (str[j + 1] == '1')
                tail[j] = tail[j + 1] + 1;
            else tail[j] = 0;
        }
 
        int ans = 0;

        for(int j = 0 ; j + K <= n ; j++)
            ans = max(ans , K + head[j] + tail[j + K - 1]);
 
        cout<<ans<<endl;
    }
	return 0;
}
