#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long fall, n, k, p, i, j, r;
    long long x, y, a[110][110];
    for(a[0][0]=scanf("%ld",&fall);fall--;printf("%lld\n",y)){
    	for(i=!!scanf("%ld%ld%ld",&n,&k,&p);i<=k+1;i++)
    	for(j=0;++j<=i;a[i][j]=(a[i-1][j-1]+j*a[i-1][j])%p);
    	for(y=!(j=1);j<=k+1;y=(y+a[k+1][j++]*x)%p)
    	for(x=!((r=n%j)*!(i=-1));++i<j;x=x*(n-i)/((i==r)?j:1)%p);
    	}
	return 0;
}
