#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    vector<int> vec;
	    unordered_map<int,int> mapping;
	    for(int i=0;i<2*n;i++){
	        int tmp;
	        cin>>tmp;
	        vec.push_back(tmp);
	        mapping[tmp]++;
	    }
	    sort(vec.begin(),vec.end());
	    if(vec.size()>0 && vec[0]==0){
	        bool yes=true;
	        if(mapping[0]==1){
	            yes=false;
	        }
	        for(int i=1;i<vec.size();i++){
	            if((vec[i]-vec[i-1])==1){
	                if(mapping[vec[i]]==1 || mapping[vec[i-1]]==1){
	                    yes=false;
	                }
	                
	            }
	            else if((vec[i]-vec[i-1])>1){
	                    break;
	            }
	        }
	        if(yes){
	            cout<<"YES"<<endl;
	        }
	        else{
	            cout<<"NO"<<endl;
	        }
	    }
	    else{
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
