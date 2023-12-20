#include <bits/stdc++.h>
using namespace std ;
vector< int > prime ;
#define limit 100005
#define MOD 1000000007
typedef long long ll ;

void init() {
	vector< bool > status( limit+1  ) ;
	fill( status.begin() , status.end() , true ) ;
	for( int i = 2 ; i*i < limit ; i++ ) {
		if( status[i] ) {
			for( int j = i*i ; j < limit ; j += i ) status[j] = false ;
		}
	}
	for( int i = 2 ; i < limit ; i++ ) if( status[i] ) prime.push_back( i ) ;
}

ll power(ll a, ll b ) {

	if( b == 0 ) return 1 ;
	ll x = power( a , b/2 ) ;
	if( b & 1 ) return ( ( (x*x)%MOD )*a )%MOD ;
	return (x*x)%MOD ;
}

int main() {
    // your code goes here
	init() ;
	int n , x ;
	map< int , int > primeFactors ;
	map< int , int > :: iterator it ;
    cin >> n; 
	for( int i = 0 ; i < n ; i++ ) {
			cin >> x ;
			for( int j = 0 ; j < prime.size() ; j++ ) 	
				while( x%prime[j] == 0 ) { x /= prime[j] ; primeFactors[ prime[j] ]++ ;
				}
				
			if( x > 1 ) primeFactors[ x ]++ ;
	}

	bool justDoit = true ;
	long long ans  = 1 ;
	for( it = primeFactors.begin() ; it != primeFactors.end() ; it++ ) {
			if( (it->second)%n ) {
				justDoit = false ;
				
			}
			ans = ( ans * power(it->first, ( n+1- (it->second)%(n+1) )  %( n+1 ) )  )%MOD ;
	}
	
	if( justDoit ) cout << "justdoit" << endl ;
	else 
		cout << ans << endl ;
	
}
