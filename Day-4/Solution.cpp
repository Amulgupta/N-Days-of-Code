#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    for(int i = 0; i < N; i++)
	    {
	        char A[N+1];
	        cin>>A[i];
	        if(A[i] == 'A')
	        cout<<"T";
	        if(A[i] == 'T')
	        cout<<"A";
	        if(A[i] == 'C')
	        cout<<"G";
	        if(A[i] == 'G')
	        cout<<"C";
	    }
	    cout<<endl;
	}
	    
	return 0;
}
