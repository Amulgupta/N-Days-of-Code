#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N, K;
	    cin>>N>>K;
	    int arr[N];
	    for(int i = 0; i < N; i++)
	    {
	        cin>>arr[i];
	    }
	    for(int j = 0; j < N; j++)
	    {
	        if(arr[j] <= K){
	        cout<<1;
	        K -= arr[j];
	        }
	        else
	        cout<<0;
	    }
	    cout<<endl;
	}
	return 0;
}
