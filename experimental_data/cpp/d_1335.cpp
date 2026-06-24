#include <bits/stdc++.h>

using namespace std;
char s[10][10];
int main() {
    int t;
    cin >> t;
    while (t--){
        for (int i = 0; i < 9; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 9; j++) {
                if (s[i][j] == '9')
                    s[i][j] = '1';
            }
        }
    for (int i = 0; i < 9; i++)
        printf("%s\n", s[i]);
}
    return 0;
}