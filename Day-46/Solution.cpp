#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int C[n+1];
        for(int i=1;i<n+1;i++)
            cin>>C[i];
        int H[n+1];
        for(int i=1;i<n+1;i++)
            cin>>H[i];
        pair<int,int> ranges[n+1];
        for(int i=1;i<n+1;i++)
        {
            ranges[i].first=max(1,i-C[i]);
            ranges[i].second=min(n,i+C[i]);
        }
        sort(ranges+1,ranges+n+1);
        int levels[n+1];
        priority_queue<int,vector<int>,greater<int>> pq;
        int count=0;
        int index=1;
        for(int i=1;i<n+1;i++)
        {
            while(index<n+1 && ranges[index].first==i)
            {
                pq.push(ranges[index].second);
                index++;
                count++;
            }
            levels[i]=count;
            while(!pq.empty() && pq.top()==i)
            {
                pq.pop();
                count--;
            }
        }
        sort(H+1,H+n+1);
        sort(levels+1,levels+n+1);
        bool flag=true;
        for(int i=1;i<n+1 && flag;i++)
        {
            if(levels[i]!=H[i])
                flag=false;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}
