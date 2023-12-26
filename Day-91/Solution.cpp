#include <bits/stdc++.h>

using namespace std;

void solve()
{   
    int n;
    cin>>n;
    pair<int, int> arr[n];

    for(int i = 0; i < n; i++) 
    {
        int x;
        cin>>x;
        arr[i].first = x;
        arr[i].second = i;
    }

    if(n>4){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    sort(arr, arr+n);
    pair<int, pair<int, int>> points[n];

    if(n >= 1){
        points[0].first = arr[0].second;
        points[0].second.first = -1*arr[0].first;
        points[0].second.second = 0;
    }
    if(n >= 2)
    {
        points[1].first = arr[1].second;
        points[1].second.first = 0;
        points[1].second.second = arr[1].first;
    }
    if(n >= 3)
    {
        points[2].first = arr[2].second;
        points[2].second.first = arr[2].first;
        points[2].second.second = 0;
    }
    if(n >= 4)
    {
        points[3].first = arr[3].second;
        points[3].second.first = 0;
        points[3].second.second = -1*arr[3].first;
    }

    sort(points, points+n);
    for(int i = 0; i < n; i++) cout<<points[i].second.first<<" "<<points[i].second.second<<'\n';     
}

int main() {
    int T;
    cin>>T;
    for(int i = 0; i < T; i++)
        solve();
}