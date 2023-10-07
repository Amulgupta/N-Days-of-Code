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
	    int sum = 0; 
	    int count = 0;
	    for(int i = 0; i<N; i++)
	    {
	        int runs;
	        int numofballs = i + 1;
	        cin>>runs;
	        sum += runs;
	        if(sum % numofballs == 0 && sum / numofballs == 1)
	        count ++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}

// There are two things that I want to clarify:
// 1.) I have chosen % as sum is a int and if div operator was chosen then dividing sum and numofballs will give 1 everytime the result is 1.XXXXXX, as result of division of two integers is an integer and also after && operator div is used to remove the test cases where remainder is zero, i.e., score is completely divisible by zero but strike rate is not 100 but is multiple of 100.