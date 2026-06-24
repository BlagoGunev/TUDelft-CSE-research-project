#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100003;
int n;
char a[MaxN];

inline bool check(int T) {
    int last=0,right=0;
    for (int i=1;i<=n;++i) {
        if (a[i]=='*') {
            if (right<i && !last) last=i;
        } else
        if (a[i]=='P') {
            int pos=i;
            if (last && pos-last>T) return false;
            if (last) pos=last;
            last=0;
            right=max(right,i);
            right=max(right,pos+(T-(i-pos)));
            right=max(right,i+(T-(i-pos))/2);
        }
    }
    if (last) return false;
    return true;
}

int main() {
    scanf("%d%s",&n,a+1);
    int l=0,r=2*n;
    while (l<r) {
        int mid=(l+r)/2;
        if (!check(mid)) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}