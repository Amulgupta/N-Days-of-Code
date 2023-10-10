#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	int prices[12] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
	while(T--)
	{
	    int p;
	    cin>>p;
	    int menus = 0;
	    for(int i = 11; i >= 0; i-- )
	    {
	        menus += p/prices[i];    // menus will keep an eye on the division of price by prices in descending order which will make it easier to chose what minimum combination of menus will have the work done.
	        p %= prices[i];
	       // p will check for remainder(the amount Tomya is left with) that will do the further calculation part.
	    }
	    cout<<menus<<endl;
	}
	return 0;
}
