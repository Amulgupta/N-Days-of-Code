#include <vector>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--)
{
    long long n, q;
    cin>>n>>q;
    vector<long long> a(n);
    vector<long long> b(q);
    long long ans=1;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        if(ans*a[i]>1000000000)
        ans=1e18;
        else
        ans*=a[i];
    }
    for(long long i=0 ; i<q; i++)
    {
        cin>>b[i];
        cout<<b[i]/ans<<" ";
    }
    cout<<endl;
}
	return 0;
}