#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    if(N & 1)
	    {
	        if(N == 1 || N == 3)
	            cout<<-1;
	        else 
	        {
	            cout<<"2 5 1 3 4 ";
	            for(int i = 6; i <= N; i++){
	                if(i % 2)
	                    cout<<i-1;
    	            else
    	                cout<<i+1;
    	        cout<<" ";
	            }
	         }
	    } 
	    else
	    {
	        for(int i = 1; i <= N; i++){
	            if(i % 2)
	                cout<<i+1;
	            else 
	                cout<<i-1;
            cout<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
