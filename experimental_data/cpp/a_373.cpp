/*
Author : r20rock
Task:
Algo:
*/

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<list>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iomanip>

using namespace std;

#define     PI       3.1428571
#define     ULL      unsigned long long int
#define     LL        long long int
#define     MOD      1000000007

#define     GETI(k)     scanf("%d",&k)
#define     GETULL(k)    scanf("%llu",&k)
#define     GETLL(k)    scanf("%Ld",&k)
#define     GETF(k)     scanf("%lf",&k)
#define     GETC(k)     scanf("%c",&k)
#define     GETS(k)     scanf("%s",k)

#define     PUTI(k)     printf("%d",k)
#define     PUTULL(k)    printf("%llu",k)
#define     PUTLL(k)    printf("%Ld",k)
#define     PUTF(k)     printf("%lf",k)
#define     PUTC(k)     printf("%c",k)
#define     PUTS(k)     printf("%s",k)
#define     PUTK(k)     printf(k)
#define     NL  printf("\n")


template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}

template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template< class T > T abs(T &n)
{
    return (n < 0 ? -n : n);
}

int main()
{
    int tc,n,k;
    tc=1;
    for(int tt=1; tt<=tc; tt++)
    {
        int a[11]= {0},p=1;
        string s[4];
        cin>>k;
        for(int i=0; i<4; i++)
            cin>>s[i];

        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if(s[i][j] !='.')
                    a[s[i][j]-'0']++;


        for(int  i=1; i<=9; i++)
        {
            if(a[i] > (2*k))
            {
                p=0;
            }
        }

        if(p)
            cout<<"YES";
        else
            cout<<"NO";

    }
    return 0;
}