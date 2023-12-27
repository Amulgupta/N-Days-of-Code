#include<bits/stdc++.h>

#define ll long long

using namespace std;
int main(){ 
int T;
cin>>T;
while(T--){
    int n,z1,z2;
    cin>>n>>z1>>z2;
    int arr[n+2];
    int i;
    for(i = 0; i < n; i++)
    cin>>arr[i];
    int arr2[2 * n+1];
    map<int, int>m;
    for(i = 0; i < n; i++)
    {
        arr2[2 * i] = arr[i];
        arr2[2 * i+1] =- arr[i];
        m.insert(make_pair(arr2[2 * i], 1));
        m.insert(make_pair(arr2[2 * i + 1], 1));
    }
    int ans = 0;
    for(i = 0; i < 2 * n; i++)
    {
        if(arr2[i] == z1 || arr2[i] == z2)
        {
            ans = 1;
            break;
        }
    }
    
    if(ans == 0)
    {
        for(i = 0; i < 2 * n; i++)
        {
            if(m.find(z1 + arr2[i]) != m.end() || m.find(arr2[i] + z2) != m.end())
            {
                continue;
            }
            else
            {
                ans=0;
                break;
            }
        }
        if(i == 2 * n)
            ans = 2;
        }
        cout<<ans<<endl;
    }
    return 0;
}