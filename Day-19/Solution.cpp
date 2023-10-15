#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    int arr[N];
	   // A[i] <= 100. Therefore let's create an array frequency which stores frequency of each element.
	   int freq[101] = {0};   // Array always 1 greater than size.
	   for(int i = 0; i < N; i++)
	   {
	       cin>>arr[i];
	       freq[arr[i]]++;
	   }
	   
	   int count = 0;
	   sort(freq, freq+101);
	   cout<<N - freq[100]<<endl;
	}
	return 0;
}
