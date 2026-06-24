#include <bits/stdc++.h>
using namespace std;
int test,n,h,a[200010],res;
template <typename T> inline void read( T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-'){
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
    //freopen("h.inp","r",stdin);
    read(test);
    while(test--)
    {
        read(h); read(n);
        int res=0;
        for(int i=1;i<=n;i++)
            read(a[i]);
        int i=1;
        a[n+1]=0;
        while(i<n)
        {
            i++;
            res++;
            if(a[i+1]==a[i]-1)
            {
                res--;
                i++;
            }
        }
        write(res); putchar('\n');
    }
}