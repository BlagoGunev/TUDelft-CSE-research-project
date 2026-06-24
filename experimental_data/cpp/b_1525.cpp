#include <bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
    x=0; register int f=1; register char c=getchar();
    while(c>'9'||c<'0') {if (c=='-') f=-1;c=getchar();}
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    x*=f;
}
const int MAXN=1e7+10;
const int MAXM=1e5+10;

int T,n,temp,f,l;
bool isorder;

int main(){
    read(T);
    while(T--){
        read(n);isorder=1;
        read(f);
        if(f!=1) isorder=0;
        for(int i=2;i<n;i++){
            read(temp);
            if (temp!=i) isorder=0;
        }
        read(l);
        if (l!=n) isorder=0;
        if(isorder) cout<<0<<'\n';
        else{
            int ans=0;
            if(f!=1) ans++;
            if(l!=n) ans++;
            if(f==n && l==1) ans++;
            cout<<max(ans,1)<<'\n';
        }
    }
    return 0;
}