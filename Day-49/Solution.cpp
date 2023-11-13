#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin>>a[i];
        }
        int c = -1;
        for(int i = 0; i < N-1; i++){
            if(a[i] > a[i+1])
            {
                c = i;
                break;
            }
        }
        if(c == -1)
        {
            cout<<"YES"<<endl;
            cout<<0<<endl;
        }
        else{
            int d = 0;
            for(int i = c+1; i < N-1; i++){
                if(a[i] > a[i+1])
                {
                    d++;
                }
            }
            
            if(d == 0 && a[N-1] <= a[0])
            {
                cout<<"YES"<<endl;
                cout<<1<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
	return 0;
}
