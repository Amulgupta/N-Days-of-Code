#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--){
        long long int N, X, count=0, ans=0;
        cin>>N>>X;
        long long int a[N];
        for(int i = 0; i < N; i++){
            cin>>a[i];
            if(a[i] & 1){
                count++;
          }
        }
        if(count == 0 and (X % 2 == 0)){
            cout<<-1<<endl;
        } 
        else if((X % 2 == 0)) {
            cout<<(N - count)<<endl; 
            
        }
        else {
            cout<<((N - count) / 2) + (N - count) % 2<<endl;
        }
    }
	return 0;
}
