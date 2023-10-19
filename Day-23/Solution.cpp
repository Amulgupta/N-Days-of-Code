// #include <iostream>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 	    int N;
// 	    cin>>N;
// 	    int A[N];
// 	    for(int i = 0; i < N; i++)
// 	    {
// 	        cin>>A[i];
// 	    }
// 	    for(int i = 0; i < N - 1; i+2)   // If i < N (condition) is used then we will not be able to access A[N + 1] later.
// 	    {
// 	        if(i % 2 == 0 && A[i] > A[i+1]){
// 	            int temp = A[i];
// 	            A[i] = A[i + 1];
// 	            A[i + 1] = temp;
// 	        }
// 	        else if(A[i] < A[i+1]){
// 	            int temp = A[i];
// 	            A[i + 1] = temp;
// 	        }
// 	    }
// 	    for(int i= 0; i < N; i++)
// 		{
// 			cout<<A[i]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }
//  Problem with the solution is Time limit exceeded.


// Optimal Solution
#include <iostream>
#include <algorithm>
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
	    
	    //Getting the array input
	    for(int i = 0 ; i < N; i++)
	    {
	        cin>>arr[i];
	    }
	    
	   // Sorting the array
	    sort(arr,arr + N);
	    
	   // Swapping the elements according to the question
	    for(int i = 0 ; i < N  - 1 ; i++)
	    {
	        if(i % 2 == 0 && arr[i] > arr[i+1])
	        {
	            swap(arr[i],arr[i+1]);
	        }
	        if(i % 2 == 1 && arr[i] < arr[i+1])
	        {
	            swap(arr[i],arr[i+1]);
	        }
	    }
	    
	   // Displaying array
	    for(int i = 0 ; i < N; i++)
	    {
            cout<<arr[i]<<" ";
	    }

	    cout<<endl;
	    
	}
	return 0;
}