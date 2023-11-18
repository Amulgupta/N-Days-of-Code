#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--) {
	    int n, maxi = INT_MIN, shifts = 0, idx = 0, firstIdx = 0, lastShift = 0, totalShift = 0, l = 0;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++) {
	        cin>>arr[i];
	    }
	    for(int i = 0; i<n; i++) {
	        if(maxi < arr[i]) {
	            maxi = arr[i];
	            firstIdx = i;
	        }
	    }
	    idx = firstIdx;
	    l = idx-n/2+1;
	    shifts = max(l, 0);
	    for(int i = idx+1; i<n; i++) {
	        if(arr[i] == maxi) {
	            l = i - idx-1;
	            shifts += max(l-n/2+1, 0);
	            idx = i;
	        }
	    }
	    lastShift = (n-1) - idx;
	    if(lastShift > 0) {
	        for(int i = lastShift; i > 0; i--) {
	            totalShift = i + firstIdx;
	            l = totalShift - n/2+1;
	            if( l > 0) {
	                shifts += 1;
	            }
	        }
	    }
	    cout<<shifts<<endl;
	}
	return 0;
}
