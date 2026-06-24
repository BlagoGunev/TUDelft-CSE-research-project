#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10000
using namespace std;
FILE *in,*out;
int N,a,b;
int main()
{
   // in=fopen("inches.in","r");
   // out=fopen("inches.out","w");
   in=stdin;out=stdout;
    fscanf(in,"%d",&N);
    a=N/36;
    N=N%36;
    b=N/3;
    N=N%3;
    if(N>1) b++;
    if(b>11)    a+=b/12;
    b%=12;
    fprintf(out,"%d %d\n",a,b);
}