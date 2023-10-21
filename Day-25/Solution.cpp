#include <iostream>
using namespace std;

int main() {
	// your code goes here
		int T;
	    cin >> T;
	    while(T--) { 
	        int N, sum = 0, diff, i;
	        cin >> N;
	        int a[N], b[N];
	        a[0] = 0;
	        b[0] = 0;
	        for(i = 1; i < N; i++) {
	            cin >> a[i];
	            sum += a[i];
	            b[i] = a[i];
	            a[i] = sum;
	        }
	        for(i = 0; i < N - 1; i++) {
	            diff = a[i + 1] - b[i];
	            if(diff > 0) {
	                b[i + 1] = b[i] + diff + b[i + 1];
	            }
	            else {
	                b[i + 1] = b[i] + b[i + 1];
	            }
	        }
	        cout << b[i] << endl;
	    }
	return 0;
}
