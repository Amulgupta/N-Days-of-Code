#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int X, Y, Z, W, a, b;
	    cin>>X>>Y>>Z>>W;
	    a = abs(X - Z);
	    b = abs(Y - W);
	    cout<<max(a, b)<<endl;
	}
	return 0;
}
