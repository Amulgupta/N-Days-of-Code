#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
        int n,k,s;
        cin>>n>>k>>s;
        int m=(s/7);
        if(k*s>(s-m)*n){
            cout<<"-1\n";
            continue;
        }
        if((k*s)%n==0) 
            cout<<((k*s)/n)<<endl;
        else 
            cout<<((k*s)/n)+1<<endl;
    }
	return 0;
}
