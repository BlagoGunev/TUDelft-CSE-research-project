#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

struct P{
    int a,b;
    bool operator<(const P&o)const{
        if(a!=o.a)return a<o.a;
        return b>o.b;
    }
}p[2000005],ans[2000005];
int acnt=0;

template <class T>
inline bool scan(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}


int main(){
    int n,k;
    scan(n);scan(k);
    for(int i=0;i<n;i++){
        scan(p[i*2].a);
        scan(p[i*2+1].a);
        p[i*2].b=1;
        p[i*2+1].b=-1;
    }
    sort(p,p+2*n);
    
    int scnt=0,lastp=INT_MIN;
    for(int i=0;i<2*n;i++){
        scnt+=p[i].b;
        if(scnt>=k&&lastp==INT_MIN){
            lastp=p[i].a;
        }else if(scnt<k&&lastp!=INT_MIN){
            ans[acnt].a=lastp;
            ans[acnt].b=p[i].a;
            acnt++;
            lastp=INT_MIN;
        }
    }
    printf("%d\n",acnt);
    for(int i=0;i<acnt;i++){
        printf("%d %d\n",ans[i].a,ans[i].b);
    }
    return 0;
}