#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    cin>>a[0];
	    int res=a[0];
	    for(int i=1;i<n;i++)
	    {
	        cin>>a[i];
	        res=res&a[i];
	    }
	    int count=0;
	    int flag=0;
	    for(int i=0;i<n-1;i++)
	    {
	        if(a[i]==res)
	        {
	            continue;
	        }
	        else
	        {
	             a[i+1]=a[i+1]&a[i];
	             a[i]=-1;
	        }
	        
	    }
	       if(a[n-1]!=res)
	       {
	           a[n-1]=-1;
	       }
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==-1)
	        count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
