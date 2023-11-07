#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	   int N;
	   cin>>N;
	   int i;
	   for(i = 1; i <= N; i++){
	       cout<< 2 * i <<" ";
	   }
	   cout<<endl;
	   for(i=1; i <= N; i++){
	       cout<< 2 * i + 1 <<" ";
	   }
	   cout<<endl;
	}
	return 0;
}
