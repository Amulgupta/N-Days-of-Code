#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int X, Y;
	    cin>>X>>Y;
	    if(X > 2*Y)
	    cout<<Y<<endl;
	    else if(X < 2*Y)
	    cout<<X/2<<endl;
	    else
	    cout<<Y<<endl;
	}
	return 0;
}
