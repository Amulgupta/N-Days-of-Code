#include <iostream>
#include<cmath>
using namespace std;

int main() {
	// your code goes here
	long long int n,q,z,g,h,i,sum,a,b,c,x;
	z=1000000007;
	scanf("%lld%lld",&n,&q);
	sum=0;
	x=1;
	for(i=0;i<n;i++){
	    sum+=((x*2));
	    sum=sum%z;
	    x=x*2;
	    x=x%z;
	}
	a=1;
	b=n+1;
	c=1;
	for(i=0;i<n;i++){
	    c=(c*2);
	    c=c%z;
	}
	
	while(q--){
	    scanf("%lld",&g);
	    if(g==1){
	        scanf("%lld",&h);
	        if((h==1)||(h==2)){
	            sum=((sum*2)%z);
	            sum+=b;
	            sum=sum%z;
	            a=a*2;
	            c=c*2;
	            a=a%z;
	            c=c%z;
	        }
	        if((h==3)){
	            sum=((sum*2)%z);
	            sum+=a;
	            sum=sum%z;
	            b=b*2;
	            b=b%z;
	            a=c;
	        }
	        if((h==4)){
	            sum=((sum*2)%z);
	            sum+=c;
	            sum=sum%z;
	            b=b*2;
	            b=b%z;
	            c=a;
	        }
	        
	    }else{
	        printf("%lld\n",sum);
	    }
	}
	return 0;
}
