#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    register char c=getchar();
    bool neg=0;
    x=0;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){
        neg=1;
        c=getchar();
    }
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c-'0');
    if(neg) x=-x;
}
inline void write(int x){
    register char c[10],*p=c;
    do{
        *p++=x%10+'0';
        x/=10;
    }while(x);
    do{
        putchar(*--p);
    }while(p!=c);
    putchar(' ');
}
const int INF=1e9+7;
vector<pair<int,int> > e[300005];
bool b[300005];
int d[300005];
queue<int> q;
int main(){
    int n,i,j,k,dd;
    read(n);read(k);read(dd);
    for(i=1;i<=n;++i) d[i]=INF;
    while(k--){
        read(i);
        d[i]=0;
        q.push(i);
    }
    for(i=1;i<n;++i){
        b[i]=1;
        read(j);read(k);
        e[j].push_back(make_pair(k,i));
        e[k].push_back(make_pair(j,i));
    }
    k=n-1;
    while(!q.empty()){
        i=q.front();q.pop();
        if(d[i]<dd)
            for(auto p:e[i])
                if(d[p.first]>d[i]+1){
                    --k;
                    d[p.first]=d[i]+1;
                    q.push(p.first);
                    b[p.second]=0;
                }
    }
    write(k);putchar('\n');
    for(i=1;i<n;++i)
        if(b[i])
            write(i);
}