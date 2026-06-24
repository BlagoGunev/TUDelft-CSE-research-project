#include <stdio.h>
#include <algorithm>
using namespace std;

long long a,b,c,d;

class PT{
    public:
        long long x,y;
        bool operator<(const PT& p) const{
            long long z=(x*c-y*d)-(p.x*c-p.y*d);
            if(z==0){
                return (y*b-x*a)>(p.y*b-p.x*a);
            }
            return z<0;
        }
};

PT pt[200000];
PT lt[200000];

int main(){
    int n,p,L,R,M;
    scanf("%d",&n);
    scanf("%I64d/%I64d %I64d/%I64d",&a,&b,&c,&d);
    for( int i=0; i<n; i++ ){
        scanf("%I64d %I64d",&pt[i].x,&pt[i].y);
    }
    sort(pt,pt+n);
    p=-1;
    for( int i=0; i<n; i++ ){
        if((pt[i].x*c-pt[i].y*d)<=0 || (pt[i].y*b-pt[i].x*a)<=0) continue;
        if(p==-1 || (pt[i].y*b-pt[i].x*a)<=(lt[0].y*b-lt[0].x*a)){
            if(p==-1) p++;
            lt[0]=pt[i];
        }else if((pt[i].y*b-pt[i].x*a)>(lt[p].y*b-lt[p].x*a)){
            lt[++p]=pt[i];
        }else{
            L=0;
            R=p;
            while(L<R-1){
                M=(L+R)/2;
                if((pt[i].y*b-pt[i].x*a)>(lt[M].y*b-lt[M].x*a)){
                    L=M;
                }else{
                    R=M;
                }
            }
            lt[R]=pt[i];
        }
    }
    printf("%d\n",p+1);
    return 0;
}