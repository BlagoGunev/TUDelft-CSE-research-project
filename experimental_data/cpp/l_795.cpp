#include <stdio.h>

char s[200005];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int l=0, r=n-2;
    int res = n-2;
    while(l<=r){
        int m=(l+r)>>1;
        int last=0, lastfree=0;
        int used = 2;
        for(int i=1; i<n-1 && n-1-last-1 > m; i++){
            if(s[i] == '0') lastfree = i;
            if(i-last-1 == m){
                if(last == lastfree){ used = 1e9; break; }
                last = lastfree;
                used++;
            }
        }
        if(used > k) l = m+1;
        else r = m-1, res = m;
    }
    printf("%d" ,res);
    return 0;
}