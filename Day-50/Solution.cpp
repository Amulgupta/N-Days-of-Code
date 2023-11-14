#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        string s,cpy;
        cin>>s;
        bool arr[26] = {0}, isFound = 0;
        if(N % 3 == 1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(N % 3 == 2)
        {
            for(int i = 0; i < N; i++)
            {
                if(!(i % 3))
                {
                    arr[s[i]-'a'] = 1;
                    continue;
                }
                if(i % 3 == 1 && arr[s[i] - 'a'])
                {
                    isFound = 1;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < N; i++)
            {
                if(!(i % 3))
                {
                    arr[s[i]-'a'] = 1;
                    continue;
                }
                if(i % 3 == 2 && arr[s[i] - 'a'])
                {
                    isFound = 1;
                    break;
                }
            }
        }
        if(isFound)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
	return 0;
}
