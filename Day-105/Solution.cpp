#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
#define db2(x,a,y,b) cout << x <<" "<< a <<"    "<< y <<" " << (b) << "\n" 
#define db1(x,a) cout << x <<" "<< a << "\n"
#define ALL(x)  (x).begin(),(x).end() 

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int,unordered_set<int>> mp;
    for(int i= 1; i<n;i++){
        if(arr[i-1] > arr[i]){
            (mp[arr[i-1] - arr[i]]).insert(i);
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        if(a-2 >= 0 && arr[a-2] > arr[a-1]){
            int diff = arr[a-2] - arr[a-1];
            mp[diff].erase(a-1);
            if(mp[diff].size() == 0) mp.erase(diff);
        }
        if(a < n && arr[a-1] > arr[a]){
            int diff = arr[a-1] - arr[a];
            mp[diff].erase(a);
            if(mp[diff].size() == 0) mp.erase(diff);
        }
        arr[a-1] = b;
        if(a-2 >= 0 && arr[a-2] > arr[a-1]){
            int diff = arr[a-2] - arr[a-1];
            mp[diff].insert(a-1);
        }
        if(a < n && arr[a-1] > arr[a]){
            int diff = arr[a-1] - arr[a];
            mp[diff].insert(a);
        }
        int ans = 0;
        if(mp.size()){
            auto it = mp.rbegin();
            ans = it->first;
        }
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}