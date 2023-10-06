#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N, X;
	    cin>>N>>X;
	    int sum = 0, minlife;
	   // Minlife is the life time required for the last bulb to make the claim true.
	    for(int i = 0; i< N-1; i++)
	    {
	        int n;
	        cin>>n;
	        sum += n;
	    }
	    minlife = (N * X) - sum;
	   // Apply the formula: 
	   //Take Sample Input 1:
	   // 3
      // 3 4
      // 1 5
    //   Then  1 + 5 + X / 3 = 4   Apply for finding X and hence conditions are put accordingly.
	    if(minlife < 0)
	    cout<<0<<endl;
	    else
	    cout<<minlife<<endl;
	    }
	return 0;
}
