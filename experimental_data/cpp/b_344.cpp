#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c,t;
int x,y,z;
bool ans;

int main ()
{
    scanf("%d %d %d",&a,&b,&c);
    if (a+b<c||b+c<a||a+c<b) ans=1;
    else if ((a+b+c)%2==1) ans=1;
    else
    {
        t=(a+b+c)/2;
        z=t-b;
        x=t-c;
        y=t-a;
    }
    if (ans==1) printf("Impossible\n");
    else printf("%d %d %d\n",x,y,z);
    return 0;
}