#include<bits/stdc++.h>

using namespace std;

#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define long long long
#define line "\n"
#define __lcm(a, b) (a/__gcd(a, b)*b)
#define PI acos(-1)
#define error cout <<"Line is print"<<endl
#define DBG(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<endl
template<class A, class B>

A POW(A b, B p, A mod)
{
    A res = 1;
    while(p)
    {
        if(p % 2 == 1)
            res = (res*b)%mod;
        b = (b * b) % mod, p = p/2;
    }
    return res;
}
int tc = 0;
#define maxn 1000002
string s1, s2, s;
const int mod = 1000000007;
int dp[1010][2][1050];
int make(int pos, int state, int sum = 0)
{
    if(pos == s.length())
    {
        if(!sum) return 0;
        while(sum)
        {
            int r = sum % 10;
            sum /= 10;
            if(r != 4 && r != 7) return 0;
        }
        return 1;
    }
    if(dp[pos][state][sum] == -1)
    {
        int &res =  (dp[pos][state][sum] = 0);

        if(state == 1)
        {
            for(int i = 0; i <= 9; i++)
                res = (res + make(pos+1, 1, sum + (i == 4 || i == 7))) % mod;
        }
        else
        {
            for(int i = 0; i < s[pos]-'0'; i++)
                res = (res + make(pos+1, 1, sum + (i == 4 || i == 7))) % mod;
            res = (res + make(pos+1, 0, sum + (s[pos] == '4' || s[pos] == '7'))) % mod;
        }
    }
    return dp[pos][state][sum];
}


void solve()
{
    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    s = s1;
    int cnt1 = make(0, 0, 0);

    memset(dp, -1, sizeof dp);
    s = s2;
    int cnt2 = make(0, 0, 0);
    int cnt  = 0;
    for(auto &x: s1) if(x=='4' || x == '7') cnt++;
    bool ok = 1;
    if(!cnt) ok = 0;
    while(cnt)
    {
        if(cnt % 10 != 4 && cnt % 10 != 7) ok = 0;
        cnt /= 10;
    }
    if(ok) cnt1--;

    cnt1 = (cnt1 + mod) % mod;
    cout << (cnt2 - cnt1 + mod) % mod <<'\n';

}

int main() {
	// your code goes here
	fastIO();
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
	return 0;
}
