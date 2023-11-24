#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int arr[26];
		memset(arr, 0, sizeof(arr));
		
		for(int i = 0; i < s.length(); i++)
			arr[s[i] - 'A'] += 1;
		sort(arr, arr + 26, greater<int>());
		int cnt = 0;
		int fin = INT_MAX;
		int sz = s.length();
		for(int i = 1; i <= 26; i++){
			
			if(sz % i == 0){
				for(int k = i; k <= 25; k++)
					cnt += arr[k];
				for(int k = 0; k <= i - 1; k++){
					int mx = sz / i;
					if(arr[k] > mx)
						cnt += arr[k] - mx;
				}
				fin = min(fin, cnt);
				cnt = 0;
			}
		}
		cout<<fin<<endl;
	}
	return 0;
}
