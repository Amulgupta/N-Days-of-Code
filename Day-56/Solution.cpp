#include<bits/stdc++.h>
#include<string>
using namespace std;
int even(string s)
{
	    int l = s.length();
        string s1 = s.substr(0,l/2);
		string s2 = s.substr(l/2);
		if(s1.compare(s2) == 0)
		return 1;
		else
		return 2;
}

int main() {
	// your code goes here
	int D;
	int flag;
	string s;
	cin>>D;

	while(D--)
	{flag = 0;
	cin>>s;
	int l = s.length();
	if(l == 1)
        flag = 2;

	else if(l % 2 == 0){
		flag = even(s);
	}

	else{
	int hash[256];
	int count = 0,key;
	for(int i = 0; i < 26; i++){
		hash[i] = 0;
		}
		for(int i = 0; i<l; i++){
			hash[s[i] - 97]++;
		}

		for(int j = 0; j < 26; j++){
			if(hash[j] % 2 != 0)
				{count++;
				key = j;
			}
		}
			int c[l];
			for(int j = 0; j < l; j++){
                c[j] = 0;
			}
			if(s[0] == (char)(key+97))
                c[0] = 1;
			for(int j = 1; j < l; j++){
                if(s[j] == (char)(key+97))
                    c[j] = c[j-1]+1;
                    else
                        c[j] = c[j-1];
			}
			if(count > 1)
			flag = 2;
			else
			{   string str;
             if(s[l/2] == (char)(key+97)){
                 str = s;
              str.erase(str.begin()+l/2);
						flag = even(str);
                            str.clear();

            if(flag != 1){
				for(int i = 0; i < l; i++){
					str = s;
					if(s[i] == (char)(key+97))
					{
						str.erase(str.begin() + i);
						flag = even(str);
						if(flag == 1)
						break;
					}
					str.clear();
				}
			}
			if(flag != 1)
                flag = 2;
             }
             else{

            if(c[l/2] > (c[l-1] - c[l/2]))
                            {int skip = 0;
                            int mid = l/2;
                            int i = 0;
                               while(i <= l/2){
					if(s[i] == s[mid+1])
                    {
                        i++;
                        mid++;
                        flag = 1;
                    }
                    else if(s[i] != s[mid + 1] && s[i+1] == s[mid+1] && s[i] == (char)(key+97) && skip == 0){
                        i++;
                        flag = 1;
                        skip = 1;
                    }
                    else{
                        flag = 2;
                        break;
                        }
				}
                            }

            else{
                int skip = 0;
                int mid = l/2;
                int i = 0;
                while(i < l/2){
					if(s[i] == s[mid])
                    {
                        i++;
                        mid++;
                        flag = 1;
                    }
                    else if(s[i] != s[mid] && s[i] == s[mid + 1] && s[mid] == (char)(key + 97) && skip == 0){
                        mid++;
                        flag = 1;
                        skip = 1;
                    }
                    else{
                        flag = 2;
                        break;
                        
                    }
                    
                }
                
            }
		}
	}
}
	if(flag == 1)
	cout<<"YES"<<endl;
	else if(flag == 2)
	cout<<"NO"<<endl;
	}
	return 0;
}
