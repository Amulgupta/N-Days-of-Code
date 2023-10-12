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
	    int Z = X/Y;
	    if(Z > 20)
	    cout<<20<<endl;
	    else
	    cout<<Z<<endl;
	}
	return 0;
}
