#include<stdio.h>
#include<cctype>
#include<algorithm>
using namespace std;
int t, n;
const int N = 2e5;
int a[N + 5];
inline int read()
{
    int x=0;short w=0;char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}
int main()
{
    t = read();
    while (t--)
    {
        n = read();
        for (int i = 1; i <= n; ++i)
        {
            a[i] = read();
        }
        int j = n - 1;
        while (a[j] >= a[j + 1] && j >= 1) --j;
        while (a[j] <= a[j + 1] && j >= 1) --j;
        printf("%d\n", j);
    }
    return 0;
}