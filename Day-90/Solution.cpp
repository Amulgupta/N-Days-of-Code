#include<iostream>
#include<string>

using namespace std;

static int dp[2005][27][27];

int main()
{
	string str;
	int T;
	cin >> T;
	while ( T-- )
	{
		cin >> str;
		int res = 0;
		int L = str.length();
		for(int i = 0; i <= L; ++i)
		for(int j = 0; j <= 26; ++j)
		for(int k = 0; k <= 26; ++k)
			dp[i][j][k] = 0;
		int c;
		for(int i = 1; i <= L; ++i)
		{
		c =(int) (str[i-1]) - 'a' + 1 ;
		for(int j = 0; j <= 26; ++j)
		for(int k = 0; k <= 26; ++k)
		{
			dp[i][j][k] = dp[i-1][j][k];
			if( k == c )
			{
				
				for( int f = 0 ; f <= k; ++f)
					dp[i][j][k] = max ( dp[i][j][k] , dp[i-1][j][f] + 1 );
			}
			if( j == c )
			{
				for( int f = j; f <= 26; ++f)
					dp[i][j][k] = max ( dp[i][j][k] , dp[i-1][f][k] + 1 );
			}
			res = max( dp[i][j][k] , res );
		}
		}
		cout << res << "\n";
	}
	return 0;
}
