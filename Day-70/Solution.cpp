#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	// your code goes here
	int n, m, p;
    cin>>n>>m>>p;
    vector<pair<int, int> > change;
    for(int i = 0; i < p; i++){
        int x, y;
        cin>>x>>y;
        change.push_back(make_pair(y-1, x-1));
    }
    sort(change.begin(), change.end());

    vector<pair<int, int> > poss(n);
    vector<pair<int, int> > prev(n);
    vector<int> cost(n, m-1);

    for(int i = 0; i < n; i++){
        poss[i] = make_pair(-1, -1);
        prev[i] = make_pair(-1, -1);
    }

    for(int i = 0; i < p; i++){
        int x = change[i].second;
        int y = change[i].first;
        if(poss[x].first==-1)
        {
            poss[x] = make_pair(y, 1);
        }
        else if(poss[x].first==y){
            poss[x].second++;
        }
        else if(poss[x].first+1 == y){
            if(prev[x].second>poss[x].second+1){
                poss[x] = make_pair(-2, -2); continue;
            }
            if(prev[x].first == -1){
                if(poss[x].first != 0)
                    cost[x] += poss[x].second;
            }
            else{
                cost[x] += poss[x].second-prev[x].second;
            }
            prev[x] = poss[x];
            poss[x] = make_pair(y, 1);
        }
        else if(poss[x].second == 1){
            if(prev[x].second > poss[x].second+1){
                poss[x] = make_pair(-2, -2);
                continue;
            }
            if(prev[x].first == -1){
                if(poss[x].first != 0)
                    cost[x] += poss[x].second;
            }
            else{
                cost[x] += poss[x].second-prev[x].second;
            }
            cost[x]--;
            poss[x] = make_pair(y, 1);
            prev[x] = make_pair(-1, -1);
        }
        else{
            poss[x].first = -2;
            poss[x].second = -2;
        }
    }

    for(int i = 0; i < n; i++){
        if(poss[i].first == -2 || poss[i].first == -1)
            continue;
        if(prev[i].second > poss[i].second+1){
            poss[i] = make_pair(-2, -2);
                continue;
        }
        if(poss[i].first != m-1 && poss[i].second != 1){
            poss[i] = make_pair(-2, -2); 
            continue;
        }
        
            if(prev[i].first == -1){
                if(poss[i].first != 0)
                    cost[i] += poss[i].second;
            }
            else{
                cost[i] += poss[i].second-prev[i].second;
            }
        
        if(poss[i].first != m-1)
            cost[i]--;
    }

    for(int i = 0; i < n; i++){
        if(poss[i].first != -2){
            cout<<cost[i]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
	return 0;
}
