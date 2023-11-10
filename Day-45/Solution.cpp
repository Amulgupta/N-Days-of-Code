#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string str;
    cin >> str;
    ll one=0,zero=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0') zero++;
        else one++;
    }
    if(str.length()%2==1 or zero==0 or one==0){
        cout<<-1<<endl;
        return;
    }
    cout<<abs(one-zero)/2<<endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while(T--){
        solve();
   }
	return 0;
}
