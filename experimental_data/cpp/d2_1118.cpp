#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int n,a[N],m;
bool check(int x){
    int len=0,cnt=0;
    int sum=0;
    for(int i=n;i>=1;--i){
        if(a[i]<=len)break;
        cnt++;
        sum+=(a[i]-len);
        if(sum>=m)return 1;
        if(cnt==x)len++,cnt=0;
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=m+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    if(check(l))printf("%d\n",l);
    else if(check(r))printf("%d\n",r);
    else puts("-1");
    return 0;
}