#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 1000000000

int main() {
    int T;
    cin >> T;
    while(T--) {
        int K;
        cin >> K; 
        vector<pair<int, char> > rangedEndpoints;
        for (int i = 0 ; i < K; i++) {
            char oper; 
            int value; 
            string answer; 
            cin >> oper >> value >> answer;
            if (oper == '=') {
                if (answer == "Yes") {
                    rangedEndpoints.push_back(make_pair(value, 'l'));
                    rangedEndpoints.push_back(make_pair(value, 'r'));    
                } 
                else {
                    rangedEndpoints.push_back(make_pair(1, 'l'));
                    rangedEndpoints.push_back(make_pair(value-1, 'r'));
                    rangedEndpoints.push_back(make_pair(value+1, 'l'));
                    rangedEndpoints.push_back(make_pair(MAX_VALUE, 'r'));
                }
            } 
            else if (oper == '<') {
                if (answer == "Yes") {
                    rangedEndpoints.push_back(make_pair(1, 'l'));
                    rangedEndpoints.push_back(make_pair(value-1, 'r'));    
                } 
                else {
                    rangedEndpoints.push_back(make_pair(value, 'l'));
                    rangedEndpoints.push_back(make_pair(MAX_VALUE, 'r'));    
                }
            } 
            else {
                if (answer == "Yes") {
                    rangedEndpoints.push_back(make_pair(value + 1, 'l'));
                    rangedEndpoints.push_back(make_pair(MAX_VALUE, 'r'));    
                } 
                else {
                    rangedEndpoints.push_back(make_pair(1, 'l'));
                    rangedEndpoints.push_back(make_pair(value, 'r'));    
                }
            }
        }
        sort(rangedEndpoints.begin(), rangedEndpoints.end());
        int max_value = 0;
        int current_value = 0;
        for (int i = 0 ; i < rangedEndpoints.size(); i++) {
            if (rangedEndpoints[i].second == 'l') {
                current_value++;
            } 
            else {
                current_value--;
            }
            max_value = max(max_value, current_value);
        }
        
        cout << K - max_value << endl;
    }
	return 0;
}