#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    string s[n];
	    int res[n];
	    int sum = 0;
	    int count11 = 0, count12=0;
	    for(int i = 0; i < n; i++){
            count11 = 0, count12 = 0;
            cin>>s[i];
	        for(int j = 0; j < n; j++){
	            if(j < n/2 && s[i][j] == '1'){
	                count11++;
	            }
	            if(j >= n/2 && s[i][j] == '1'){
	                count12++;
	            }
	        }
	        res[i] = count11 - count12;
	        sum = sum + res[i];
	    }
	    sort(res, res+n);
	    int ans = 1e9+7;
	    if(sum > 0){
	        for(int i = 0; i < n; i++){
	            if(abs(sum - 2*res[i]) < ans){
	                ans = abs(sum - 2*res[i]);
	            }
	        }
	    }
	    else if(sum < 0){
	         for(int i = 0; i < n; i++){
	            if(abs(sum - 2*res[i]) < ans){
	                ans = abs(sum - 2*res[i]);
	            }
	        }
	    }
	    else{
	        ans = 0;
	    }
	   cout<<ans<<endl;
	}
	return 0;
}
