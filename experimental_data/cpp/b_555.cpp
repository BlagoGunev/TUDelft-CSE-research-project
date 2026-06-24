//Hello. I'm Peter.
#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readLL(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void printno(){
    printf("No\n");
    exit(0);
}
#define N 200100
int n,m,b[N];
ll l[N],r[N];
struct Data{
    ll l,r;
    int id1,id2;
    friend bool operator<(const Data a,const Data b){
        return a.r>b.r;
    }
}d[N];
bool cmp1(const Data a,const Data b){
    return a.l<b.l;
}
struct Bridge{
    ll l;
    int id;
}bri[N];
bool cmp2(const Bridge a,const Bridge b){
    return a.l<b.l;
}
int main(){
    //freopen("/Users/peteryuanpan/data.txt","r",stdin);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        l[i]=readLL();
        r[i]=readLL();
    }
    for(int i=1;i<=m;i++){
        bri[i].l=readLL();
        bri[i].id=i;
    }
    if(m<n-1) printno();
    for(int i=1;i<n;i++){
        d[i].l=l[i+1]-r[i];
        d[i].r=r[i+1]-l[i];
        d[i].id1=i,d[i].id2=i+1;
    }
    sort(d+1,d+1+(n-1),cmp1);
    sort(bri+1,bri+1+m,cmp2);
    priority_queue<Data>q;
    while(!q.empty()) q.pop();
    int j=1;
    for(int i=1;i<=m;i++){
        if(j>n-1&&q.empty()) break;
        while(j<=n-1&&d[j].l<=bri[i].l){
            q.push(d[j]);
            j++;
        }
        if(q.empty()) continue;
        Data d1=q.top();
        q.pop();
        if(d1.r<bri[i].l) printno();
        b[d1.id1]=bri[i].id;
    }
    if(j<=n-1||!q.empty()) printno();
    printf("Yes\n");
    for(int i=1;i<n;i++){
        if(i>1) printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}