#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int A[10], T1 = 0, T2 = 0;
	    for(int i = 0; i < 10; i++)
	    {
	        cin>>A[i];
	        if(i%2 == 0)
	            T1 += A[i];     // Count in index starts with 0 so first attempt was from Team 1 and therefore this condition.
	        else
	            T2 += A[i];

	    }
	    if(T1 > T2)
	        cout<<1<<endl;
	    
	    else if(T2 > T1)
	        cout<<2<<endl;
	    
	    else
	        cout<<0<<endl;
	}
	return 0;
}
