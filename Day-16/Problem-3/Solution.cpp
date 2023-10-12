#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int Alice = 0, Bob = 0;
	    int A, B, C, D, E, F;
	    cin>>A>>B>>C>>D>>E>>F;
	    
	    // Alice Score:
	    if(A > B && A > C){
	        if(B > C)
	        Alice = A * 100 + B * 10 + C;
	        
	        else
	        Alice = A * 100 + C * 10 + B;
	    }
	    
	    else if(B > C){
	        if(A > C)
	        Alice = B * 100 + A * 10 + C;
	        
	        else
	        Alice = B * 100 + C * 10 + A;
	    }
	    
	    else{
	        if(A > B)
	        Alice = C * 100 + A * 10 + B;
	        
	        else
	        Alice = C * 100 + B * 10 + A;
	    }
	    
	    // Bob Score:
	    if(D > E && D > F){
	        if(E > F)
	            Bob = D * 100 + E * 10 + F;
	        
	        else
	            Bob = D * 100 + F * 10 + E;
	    }
	    
	    else if(E > F){
	        if(D > F)
    	        Bob = E * 100 + D * 10 + F;
	        
	        else
    	        Bob = E * 100 + F * 10 + D;
	    }
	    
	    else{
	        if(D > E)
    	        Bob = F * 100 + D * 10 + E;
	        
	        else
	            Bob = F * 100 + E * 10 + D;
	    }
	    
	    if(Alice > Bob)
	    cout<<"Alice"<<endl;
	    else if(Alice<Bob)
	    cout<<"Bob"<<endl;
	    else
	    cout<<"Tie"<<endl;
	}
	    
	return 0;
}
