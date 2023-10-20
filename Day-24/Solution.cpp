#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    string S;
	    cin>>S;
	    int valid = 1;   // Flag for a later use
	    string L = S;    // Initialize a string L as left
	    for (int i = 0; i < S.length(); i++) {
            L[i] = S[(i + 1) % S.length()];
        }
        
        string R = S;  // Initialize a string R as right
        for (int i = 0; i < S.length(); i++) {
            R[(i + 1) % S.length()] = S[i];
        }

        for (int i = 0; i < S.length(); i++) {
            if(L[i] != R[i]){
                valid = 0;
                break;
            }
        }
        
        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
