#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	long long int c[n+1];
	for(int i=1;i<=n;i++){
	    cin>>c[i];
	}
	while(m--){
	    int e,p;
	    cin>>e>>p;
	    pair<long long int,int> data[p+1];
	    for(int i=1;i<=p;i++){
	        cin>>data[i].first;
	        cin>>data[i].second;
	    }
	    for(int i=1;i<=p;i++){
	        c[data[i].second]=(c[data[i].second]+c[e]*data[i].first)%(1000000007);
	    }
	    c[e]=0;
	}
	for(int i=1;i<=n;i++){
	    cout<<c[i]<<endl;
	}
	return 0;
}
