#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    register char c=getchar();
    x=0;
    while(c<'0'||c>'9') c=getchar();
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c-'0');
}
int s[100005],a[100005],b[100005],c[100005];
int n,i,j,S;
long long k=0,m,v=0,t=0;
inline bool cmp(const int &x, const int &y){
    return a[x]-b[x]>a[y]-b[y];
}
long long check(long long u){
    long long l=0,r=0,z=0;
    if(u<0||u>m) return 0;
    u*=S;
    for(i=0;i<n&&u>s[c[i]];++i){
        z+=1LL*s[c[i]]*a[c[i]];
        u-=s[c[i]];
    }
    if(i>=n) return z;
    if(a[c[i]]>b[c[i]]){
        z+=u*a[c[i]]+1LL*(s[c[i]]-u)*b[c[i]];
        for(++i;i<n;++i) z+=1LL*s[c[i]]*b[c[i]];
    }
    else if(u>m*S-t){
        u-=m*S-t;
        z+=u*a[c[i]]+1LL*(s[c[i]]-u)*b[c[i]];
        for(++i;i<n;++i) z+=1LL*s[c[i]]*b[c[i]];
    }
    else{
        u=m*S-t-u;
        for(j=i;j<n;++j) z+=1LL*s[c[j]]*b[c[j]];
        for(--i;i>=0&&a[c[i]]<b[c[i]];--i){
            if(u>s[c[i]]){
                z+=1LL*s[c[i]]*(b[c[i]]-a[c[i]]);
                u-=s[c[i]];
            }
            else{
                z+=u*(b[c[i]]-a[c[i]]);
                break;
            }
        }
    }
    return z;
}
int main(){
    read(n);read(S);
    for(i=0;i<n;++i){
        read(s[i]),read(a[i]),read(b[i]),c[i]=i;
        t+=s[i];
        if(a[i]>b[i]) v+=s[i];
    }
    m=(t+S-1)/S;
    sort(c,c+n,cmp);
    v/=S;
    cout<<max(max(check(v),check(v+2)),max(check(v+1),check(v-1)));
}