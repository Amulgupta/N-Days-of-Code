#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        int A[n];
        int B[n];
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++)
        {
            cin>>A[i];
            B[i] = A[i];
        }
        sort(B, B + n);
        
        if(k == 1)
        {
            cout<<B[n - 1]<<endl;
            cout<<B[n - 1]<<endl;
            continue;
        }
        reverse(B, B+n);
        for(int i = 0; i < k; i++)
        {
            m[B[i]] = 1;
        }
        cout<<B[k / 2]<<endl;
        for(int i = 0; i < n; i++)
        {
            if(m[A[i]] == 1)
            {
                cout<<A[i]<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}
