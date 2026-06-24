#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main(){

    int x, z=0, n=0;
    char s[MAXN];
    scanf("%d", &x);
    scanf("%s", s);

    for(int i = 0; i < x; i++){
        if(s[i]=='z') z++;
        if(s[i]=='n') n++;
    }

    for(int i=0; i<n; i++) printf("1 ");
    for(int i=0; i<z; i++) printf("0 ");
    printf("\n");

    return 0;
}