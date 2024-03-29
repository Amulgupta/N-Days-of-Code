#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1337;

int t[7][101];
int c[7][101];
int p10[101];
char s[101];

int main() {
	// your code goes here
	for (int k = 1; k < 7; ++k) t[k][0] = c[k][0] = 1;
        t[0][0] = c[0][0] = -1;
        p10[0] = 1;
    for (int len = 1; len <= 100; ++len) {
        p10[len] = (10 * p10[len - 1]) % 7;
        for (int md = 0; md < 7; ++md) {
            t[md][len] = 0;
            c[md][len] = 1;
            for (int d = 0; d <= 9; ++d) {
                if (d != 7) {
                    t[md][len] += c[md][len] * t[(p10[len - 1] * d + md) % 7][len - 1];
                    c[md][len] *= c[(p10[len - 1] * d + md) % 7][len - 1];
                } else if (len == 1) {
                    t[md][len] += -c[md][len];
                    c[md][len] *= -1;
                }
            }
            t[md][len] = (t[md][len] % M + M) % M;
        }
    }
    int d;
    cin >> d;
    while (d--) {
        cin >> s;
        int len = strlen(s);
        int p = -1;
        int cc = -1;
        int md = 0;
        reverse(s, s + len);
        for (int i = len - 1; i >= 0; --i) {
            for (int d = 0; d < s[i] - '0'; ++d) {
                if (d != 7) {
                    p += cc * t[(md + d * p10[i]) % 7][i];
                    cc *= c[(md + d * p10[i]) % 7][i];
                } else if (i == 0) {
                    p += -cc;
                    cc *= -1;
                }
            }
            if (s[i] == '7' && i) {
                if (s[0] % 2) {
                    p -= cc;
                }
                break;
            }
            md = (md + (s[i] - '0') * p10[i]) % 7;
        }
        cout << (p % M + M) % M + 1 << endl;
    }
	return 0;
}
