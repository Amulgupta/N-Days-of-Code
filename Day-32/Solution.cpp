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
	    //For n = 1 print 1
	    if(N == 1)
	    cout<<1<<endl;
	    else if(N == 2)
	    //For n = 2 print 1 and 3 we can also print 2 4 in place of 1 and 3 
	    //As 2 and 4 is divisible by 1 and also 2 + 4 is divisible by 2
	    cout<<1<<" "<<3<<endl;
	    else{
	        int c = 2;
	        //For else case when n>2 start printing from 2 and increse the value or 2 by 2
	    for(int i = 0; i < N; i++){
	    cout<<c<<" ";
	    c += 2 ;
	    }
	    cout<<endl;
	    }
	}
	return 0;
}
