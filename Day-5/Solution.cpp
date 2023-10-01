#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int X,Y;
	    cin>>X>>Y;
	    int sum = X + Y;
	    int req = 21 - sum;
	    if(req > 10)
	    cout<<-1<<endl;
	    else
	    cout<<req<<endl;
	}
	return 0;
}
