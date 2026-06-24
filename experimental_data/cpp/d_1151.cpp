#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int n = 0 , c = 0, m;
    while (!isdigit(c)) m = c - 45 ? 1 : -1 , c = getchar();
    while (isdigit(c))  n = n * 10 + c - 48 , c = getchar();
    return m * n;
}
int bin_pow( int a, int n )
{
    if ( n == 0 ) return 1;
    if ( n % 2 )  return bin_pow( a, n - 1 ) * a;
    int p = bin_pow( a, n / 2 );
    return p * p;
}

int n;
int a, b, s, c[100005];
main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        a = read();
        b = read();
        s += b*n-a;
        c[i] = a-b;
    }
    sort(c+1,c+1+n);
    for(int i=1; i<=n; i++)
    {
        s += i*(c[n+1-i]);
    }
    cout<<s;












}