#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<double,int> abcd;
const int N=100010;
int k,n,w,x,y,num;
int s[N];
abcd a[N],c[N];
long long Ans;
int Query(int x) {
    int Ans=0;
    for(;x;x-=x&-x) Ans+=s[x];
    return Ans;
}
void Update(int x) {
    for(;x<=num;x+=x&-x) ++s[x];
}
int main() {
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        a[i].fi=(double)-x/(y-w);
        c[i].fi=(double)-x/(y+w);c[i].se=i;
        a[i].se=c[i].fi;
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++) {
        if(c[i].fi>c[i-1].fi) ++num;
        a[c[i].se].se=num;
    }
    sort(a+1,a+n+1);
    for(int i=n;i;) {
        int j=i;
        while(j&&a[j].fi==a[i].fi) --j;
        for(int k=i;k>j;k--) Ans+=Query(a[k].se)+i-k;
        while(i>j) Update(a[i--].se);
    }
    cout<<Ans<<endl;
    return 0;
}