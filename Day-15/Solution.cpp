#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int B, n;
	    cin>>B;
	    B -=2;     //This line of code ensures that triangles are neither overlapped nor overflowed.(Side is of 2 units)
	    B /= 2;    //This line indicates that the side of 'square'(Keyword of question[Area of squae = side * side]) is 2 units so how much space it needs.
	    
	    B = B*(B+1)/2; //This is like an Arithmetic Progression. So,sum of n terms.
	    cout<<B<<endl;
	}
	return 0;
}
