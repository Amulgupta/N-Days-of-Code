#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    N *= 3;
	    
	    map<string, int> mp;
	    
	    string code;
	    int subcount;
	    for(int i = 0; i < N; i++){
	        cin>>code>>subcount;
	        mp[code] += subcount;
	    }
	    
	    vector<int> v;
	    for(auto it : mp){
	        v.push_back(it.second);
	    }
	    
	    sort(v.begin(), v.end());
	    
	    for(auto it : v){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}
