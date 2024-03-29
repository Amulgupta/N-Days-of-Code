#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
 
#define maxn 2229283
#define ull unsigned long long
 
int md = 500009;
vector<int> prime;
int minp[maxn];
int ans[maxn+5];
ull sum[maxn+5];
ull div[maxn+5];
ull deg[maxn+5];
void pre()
{
	for (int i = 2; i*i < maxn; i++) {
		if (!minp[i]) {
			for (int j = i; j < maxn; j += i) {
				minp[j] = i;
			}
		}
	}
}
int main()
{
	pre();
	int t;
	ans[0] = 1;
	div[1] = 1;
	deg[1] = 1;
	for (int i = 2; i < maxn; i++) {
		int &p = minp[i];
		if (!p) p = i;
		int j = i/p;
		if(minp[j] == minp[i]) {
			deg[i] = deg[j]+1;
			div[i] = (div[j]*(deg[i]+1))/(deg[j]+1);
		}
		else {
			deg[i] = 1;
			div[i] = div[j]*2;
		}
	}
	for (int i = 1; i <= maxn; i++) {
		sum[div[i]]++;
		ans[i] = ((ans[i-1]*sum[div[i]]))%md;
	}
	scanf("%d",&t);
	while (t--) {
		ull n;
		scanf("%llu",&n);
		if (n < maxn) {
			printf("%d\n",(ans[n]+md-1)%md);
		}
		else {
			printf("%d\n",md-1);
		}
	}
	return 0;
}