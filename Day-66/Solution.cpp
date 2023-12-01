#include <bits/stdc++.h>
using namespace std;

int findparent(int x, vector<int>&finalowner){
    if(finalowner[x] == x){
        return x;
    }
    finalowner[x] = findparent(finalowner[x], finalowner);
    return finalowner[x];
}


int main(){
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    vector<int>finalowner(N+1, 0);
	    for(int i = 1; i <= N; i++){
	        finalowner[i]=i;
	    }
    	vector<int>parent(N+1, 0);
    	vector<int>maxdish(N+1, 0);
    	vector<int>dish;
	    for(int i=0; i < N; i++){
	        int inp;
	        cin>>inp;
	        parent[i+1] = i+1;
	        maxdish[i+1] = inp;
	        dish.push_back(inp);
	    }
	    int Q;
	    cin>>Q;
	    for(int i = 0; i < Q; i++){
	        int t;
	        cin>>t;
	        if(t == 0){
	            int x, y;
	            cin>>x>>y;
	            int dish1 = dish[x-1];
	            int dish2 = dish[y-1];
    	        int p1 = parent[x];
                int p2 = parent[y];
    	        int parent1 = findparent(p1,finalowner);
    	        int parent2 = findparent(p2,finalowner);
	            int maxdish1 = maxdish[parent1];
	            int maxdish2 = maxdish[parent2];
	            if(parent1 == parent2){
	                cout<<"Invalid query!"<<endl;
	            }
	            
	            else if(maxdish1 > maxdish2){
	                finalowner[parent2] = parent1;
	                maxdish[parent1] = max(maxdish1, maxdish2);
	            }
	            else if(maxdish1 < maxdish2){
	                finalowner[parent1] = parent2;
	                maxdish[parent2] = max(maxdish1, maxdish2);    
	            } 
	        }
			else {
				int x;
				cin>>x;
				int parentx = parent[x];
				while(finalowner[parentx] != parentx){
	                parentx = finalowner[parentx];
	            }
				cout<<parentx<<endl;
			}
	    }
	}
	return 0;
}
