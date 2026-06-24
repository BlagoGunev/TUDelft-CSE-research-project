#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int t,ans[N],n,cnt[N],tail1,tail2,k,cnt2[N];
typedef pair<int,int> P;
P a[N],b[N],c[N];

inline void clear(){
    tail1=tail2=0;
    for(int i=1;i<=n;i++) ans[i]=cnt2[i]=cnt[i]=0;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);read(k);
        for(int i=1;i<=n;i++){
            read(a[i].first);a[i].second=i;
            cnt[a[i].first]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[a[i].first]>=k) b[++tail1]=a[i];
            else c[++tail2]=a[i];
        }
        sort(b+1,b+tail1+1);
        for(int i=1;i<=tail1;i++){
            if(cnt2[b[i].first]==k) continue;
            cnt2[b[i].first]++;
            ans[b[i].second]=cnt2[b[i].first];
        }
        sort(c+1,c+tail2+1);
        int len=(tail2/k)*k;
        for(int j=1;j<=len;j++){
            ans[c[j].second]=j%k+1;
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        putchar('\n');
        clear();
    }
}