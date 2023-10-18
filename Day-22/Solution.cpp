#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N, A, side;
	    cin>>N>>A;
	    side = int(sqrt(N)) * A;       
	    // The side of the longest square will be determined in the process as follows:
	   // Evenly distribute squares to get a square. (More of imagination is used to solve the question)
	   cout<<side<<endl;
	}
	return 0;
}
