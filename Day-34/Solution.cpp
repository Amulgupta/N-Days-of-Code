#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int a[N];
	    int count=0;
	    for(int i = 0; i < N; i++)
	    {
	        
	        cin>>a[i];
	        if(a[i]==0)
	        count ++;
	    }
	    
	    if(count > N/2)
	    cout<<count<<endl;
	    else
	    cout<<N - count<<endl;
	}
	return 0;
}
