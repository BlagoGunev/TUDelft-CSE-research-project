#include<bits/stdc++.h>
using namespace std;
int t;
int n,x,p;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&x,&p);
        bool ok=false;
        for(int i=1;i<=min(p,2*n);i++) {
            x=(x+i)%n;
            if(x==0) ok=true;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}