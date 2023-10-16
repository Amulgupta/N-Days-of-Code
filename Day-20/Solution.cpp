#include <iostream>
using namespace std;


int digitSum(int N){
    int sum = 0;
	while(N > 0){
	sum += N % 10;
	N /= 10;
	}
	return sum;
}


int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    if(digitSum(N) % 2 == 0 && digitSum(N + 1) % 2 == 0)
	    cout<<N + 2<<endl;
	    
	    else if(digitSum(N) % 2 != 0 && digitSum(N + 1) % 2 != 0)
	    cout<<N + 2<<endl;
	    
	    else
	    cout<<N + 1<<endl;
	    
	}
	return 0;
}
