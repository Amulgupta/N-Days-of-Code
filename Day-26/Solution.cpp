#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    double ans = 0.0;
	    for(int i = 0; i < N; i++)
	    {
	        int a, b, c;
	        cin>>a>>b>>c;
	        double x = a * (100 + c) / 100.0;
	        double y = (100 - c) * x/100.0;
	        ans += (a - y) * b;
	        
	    }
	    
	    int x = ans;
        string s = to_string(x);
        int size = 11 - s.size();
        cout<<fixed<<setprecision(size)<<ans<<endl;
        
	}
	return 0;
}
