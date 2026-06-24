#include <cstdio>
#include <iostream>
#define sqr(x) ((x)*(x))
#define INF (~0u>>1)
using namespace std;
int x1, y1, r1, R1, x2, y2, r2, R2, ans=0;
int main(){
    cin>>x1>>y1>>r1>>R1;
    cin>>x2>>y2>>r2>>R2;
    int x=sqr(x1-x2)+sqr(y1-y2);
    ans+= ((x<=sqr(r1-r2) && r1<r2) || (x<=sqr(r1-R2) && r1>R2) || (x>=sqr(r1+R2)));
    ans+= ((x<=sqr(R1-r2) && R1<r2) || (x<=sqr(R1-R2) && R1>R2) || (x>=sqr(R1+R2)));
    ans+= ((x<=sqr(r1-r2) && r1>r2) || (x<=sqr(R1-r2) && r2>R1) || (x>=sqr(r2+R1)));
    ans+= ((x<=sqr(r1-R2) && r1>R2) || (x<=sqr(R1-R2) && R2>R1) || (x>=sqr(R2+R1)));
    cout<<ans<<endl;
    return 0;
}