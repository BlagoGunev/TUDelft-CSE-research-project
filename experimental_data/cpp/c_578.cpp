#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int SIZE = 2e5+10;
int a[SIZE];
int up_stk[SIZE],down_stk[SIZE];
int Un=1,Dn=1;
LL compare(LL x,LL y,LL z,LL w){return (a[x]-a[y])*(w-z)-(a[z]-a[w])*(y-x);}
double get_x(int x,int y){return (a[x]-a[y])*1./(y-x);}
double get_y(double v,int x){return x*v+a[x];}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
        while(Un>1&&compare(up_stk[Un-1],i,up_stk[Un-1],up_stk[Un-2])>=0)Un--;
        up_stk[Un++]=i;
        while(Dn>1&&compare(down_stk[Dn-1],i,down_stk[Dn-1],down_stk[Dn-2])<=0)Dn--;
        down_stk[Dn++]=i;
    }
    reverse(down_stk,down_stk+Dn);
    int it1=0,it2=0;
    double an=1e18;
    while(it1+1<Dn||it2+1<Un){
        if(it2+1>=Un||(it1+1<Dn&&compare(down_stk[it1],down_stk[it1+1],up_stk[it2+1],up_stk[it2])<=0)){
            double x=get_x(down_stk[it1],down_stk[it1+1]);
            an=min(an,get_y(x,up_stk[it2])-get_y(x,down_stk[it1]));
            it1++;
        }
        else{
            double x=get_x(up_stk[it2],up_stk[it2+1]);
            an=min(an,get_y(x,up_stk[it2])-get_y(x,down_stk[it1]));
            it2++;
        }
    }
    printf("%.15f\n",an);
    return 0;
}