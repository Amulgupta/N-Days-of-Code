#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N, K, squarescalc;
	    cin>>N>>K;
	    squarescalc = (N/K);
	   // Number of squares needed can be easily calculated if we come to know how many squares can we place either row wise or column wise then multiply by 2.
	   if(N == K)
	   cout<<1<<endl;
	   else
	   cout<<pow(squarescalc, 2)<<endl;
	   
	}
	return 0;
}
