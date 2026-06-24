#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char s[100100];
int n, k, ans;
int main() {
    scanf("%d%d\n", &n, &k);
    ans = n;
    fgets(s, sizeof(s), stdin);
    if ( k == 1 ) {
        for ( int i = 0; i < n; i++ )
            if ( s[i] == '0' ) {
                for ( int j = i+1; j < n; j++ )
                    if (s[j] == '0') {
                        if (j-i < ans) {
                            ans = j-i;
                        }
                        break;
                    }
            }

        printf("%d\n", ans);
        return 0;
    }
    int p1 = -1, p2 = -1, pf = -1, num = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( s[i] == '0' ) {
            if ( p1 == -1 )
                p1 = i;
            num++;
            if ( num == k+1 ) {
                p2 = i;
                break;
            }
        }
    }

    for ( int i = p1+1; i < p2; i++ ) {
        if ( s[i] == '0' ) {
            int t = max(i-p1, p2-i);
            if ( t < ans ) {
                ans = t;
            }
            pf = i;
            if ( p2-i < i-p1 ) 
                break;
        }
    }

    bool ok = 0;
    while (true) {
        for ( int i = p2 + 1; i < n; i++ )
            if ( s[i] == '0' ) {
                p2 = i;
                ok = 1;
                break;
            }
        if ( !ok ) 
            break;

        for ( int i = p1 + 1; i < n; i++ )
            if ( s[i] == '0' ) {
                p1 = i;
                break;
            }

        if (pf > p1) {
            int t = max(pf-p1, p2-pf);
            if ( t < ans )
                ans = t;
        }

        for ( int i = pf + 1; i < p2; i++ ) {
            if ( p2 - pf < pf - p1 )
                break;
            if ( s[i] == '0' ) {
                pf = i;
                int t = max(pf-p1, p2-pf);
                if ( t < ans )
                    ans = t;

                if ( p2 - pf < pf - p1 ) 
                    break;
            }
        }
        ok = 0;
    }
    printf("%d\n", ans);
    return 0;
}