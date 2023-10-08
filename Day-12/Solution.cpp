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
	    int min = 0;
	    while(N != 50)
	    {
	        if(N > 50)
	        {
	            N -= 3;
	            min++;
	        }
	        else if (N < 50)
	        {
	            N += 2;
	            min++;
	        }
	    }
	    cout<<min<<endl;
	}
	return 0;
}
