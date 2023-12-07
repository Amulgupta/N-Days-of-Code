#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>>&grid, int r, int c, int n){
    if(grid[r][c] == -1) return false;
    for(int j = c-1; j >= 0; --j){
        if(grid[r][j] == 1) return false;
        if(grid[r][j] == -1) break;
    }
    int x = r-1 , y = c-1 ;
    while(x >= 0 && y >= 0){
        if(grid[x][y] == 1 ) return false;
        if(grid[x][y] == -1) break;;
        x--, y--;
    }
    x = r+1 , y = c-1 ;
    while(y >= 0 && x < n){
        if(grid[x][y] == 1) return false;
        if(grid[x][y] == -1) break;;
        x++, y--;
    }
    return true;
}

bool fill(vector<vector<int>>&grid, int c, int n){
    if(c >= n) return true;
    for(int i = 0; i < n; ++i){
         if(isValid(grid, i, c, n)){
             grid[i][c] = 1;
             if(fill(grid, c+1, n)) return true;
             grid[i][c] = 0;
         }
    }
    return false;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    int n, k;
	    cin >> n >> k;
	    vector <vector<int>> grid(n,vector<int>(n, 0));
	    for(int i = 0; i < k; ++i){
	        int x, y;  cin >> x >> y;
	        x--, y--;
	        grid[x][y] = -1;
	    }
	    fill(grid, 0, n);
	    if(1){
	        for(int j = 0; j < n; j++){
	            for(int i  = 0; i < n; ++i){
	                if(grid[i][j] == 1) cout << i+1 << " ";
	            }
	        }
	    }
	    cout << endl;
	}
	return 0;
}
