#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N, K, ans;
	    cin>>N>>K>>ans;
	    vector<int> arr(N);
	    int x = 0,o = 0;
	    for(int i = 0; i < N; i++)
	    {
	        cin>>arr[i];
	        x = x ^ arr[i];
	        o = o | arr[i];
	    }
	    int a=arr[0];
	    for(int i = 1; i < N; i++)
	    {
	        a = a & arr[i];
	    }
	    string op;
	    cin>>op;
	    if(op == "XOR")
	    {
	        if(K % 2==0)
	        cout<<ans<<endl;
	        else
	        {
	            ans=ans ^ x;
	            cout<<ans<<endl;
	        }
	    }
	    else if(op=="AND")
	    {
	        if(K > 0)
	        ans=ans&a;
	        cout<<ans<<endl;
	    }
	    else
	    {
	        if(K > 0)
	        ans=ans|o;
	        cout<<ans<<endl;
	    }
	}
	return 0;
}
