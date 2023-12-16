#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int maxposibble = 0, minvalue;
	    for(int i = 2; i*i <= n ; i++)
	    {
	        if(n%i == 0)
	        {
	            int c = 0; while(n % i == 0)
	            {
	                c++;
	                n /= i;
	                
	            }
	            if(c > maxposibble)
	            {
	                maxposibble = c;
	                minvalue = i;
	                
	            }
	            
	        }
	        
	    }
	    if(maxposibble == 0)
    	    minvalue = n;
    	    cout<<minvalue<<endl;
	    
	}
	return 0;
}
