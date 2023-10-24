#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int n, m;
	    cin>>n>>m;
	    int moves = n * m ;
	    if(moves % 2 == 0)
	    cout<<"Yes"<<endl;
	    else
	    cout<<"No"<<endl;
	    
	}
	return 0;
}
