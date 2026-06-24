#include <bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
#define drap(i,s,n) for(int i=s;i>=n;i--)
#define N 333333
#define ll long long
using namespace std;
char xB[1<<15],*xS=xB,*xTT=xB;
#define getc() (xS==xTT&&(xTT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xTT)?0:*xS++)
#define isd(c) ((c>='0'&&c<='9')||(c=='-'))
template<typename T>
inline void rd(T & xaa){
    char xchh; T f=1; xaa=0; while(xchh=getc(),!isd(xchh));
    if(xchh=='-'){f=-1; xchh=getc();} xaa=xchh-'0';
    while(xchh=getc(),isd(xchh)) xaa=xaa*10+xchh-'0';
    xaa*=f; return;
}
struct seg{
    int l,r,q;
    bool operator < (const seg& b) const {if(l==b.l) return r>b.r; else return l<b.l;}
}a[N];
int n,maxr,tr;
int main(){
	//freopen("a.in","r",stdin); 
    rd(n); rap(i,1,n){rd(a[i].l); rd(a[i].r); a[i].q=i;} sort(a+1,a+n+1);
    rap(i,1,n){
        if(a[i].r<=maxr){
            printf("%d %d\n",a[i].q,a[tr].q);
            return 0;
        }
        else maxr=a[i].r,tr=i;
    }
    printf("-1 -1\n"); return 0;
}