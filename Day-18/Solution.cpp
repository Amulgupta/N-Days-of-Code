#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int X, H;
	    cin>>X>>H;
	    int count = 0;
	    while (H > 0) {
            if(count < 5) {
                H -= X/ 2;
            } else {
                H -= X;
            }
            count++;
        }
	    cout<<count<<endl;
	}
	return 0;
}
