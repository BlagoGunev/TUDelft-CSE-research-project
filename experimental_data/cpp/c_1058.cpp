#include "bits/stdc++.h"
using namespace std;

const int N = 1e2 + 5;

int n;
string s;

int main() {
    scanf("%d", &n);
    cin >> s;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
        sum += (s[i] - '0');
    bool okay = false;
    for(int i = 2 ; i <= n ; i++) {
        if(sum % i)
            continue;
        int part = sum / i;
        int c = 0;
        bool ok = true;
        for(int j = 0 ; j < n ; j++) {
            if(c < part) {
                c += (s[j] - '0');
            }

            if(c == part) {
                c = 0;
            }
            else if(c > part) {
                ok = false;
                break;
            }
        }
        if(c != 0)
            ok = false;
        if(ok)
            okay = true;
    }
    if(okay)
        printf("YES");
    else
        printf("NO");
    return 0;
}