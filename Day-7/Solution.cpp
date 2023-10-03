#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int AlexX, AlexY, BOBX, BOBY;
	    cin>>AlexX>>AlexY>>BOBX>>BOBY;
	    
	   // Apply distance formula : sqrt (x*x + y*y)
	    int distAlex = AlexX * AlexX + AlexY * AlexY;
	    int distBob = BOBX * BOBX + BOBY * BOBY;
	    
	    if(distAlex > distBob)
	    cout<<"ALEX"<<endl;                    // ALEX is far if distance is more for ALEX
	    
	    else if(distAlex < distBob)
	    cout<<"BOB"<<endl;                    //  BOB is far if distance is more for BOB
	    
	    else
	    cout<<"EQUAL"<<endl;                  // Equal Distance
	}
	return 0;
}
