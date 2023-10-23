#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N, K;
	cin>>N>>K;
	set<int> a;
    int open = 0;
    while (K--)
    {
        string S;
        cin >> S;
        int T;
        if (S == "CLOSEALL")
            a.clear();
        else if (S == "CLICK"){
            cin >> T;
            auto it = a.find(T);
            if (it != a.end()){
                a.erase(T);
            }
            else a.insert(T);
        }
        cout << a.size() << endl;
    }
	return 0;
}
