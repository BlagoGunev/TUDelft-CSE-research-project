#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 100006
#define MOD (long long)1000000007
using namespace std;

inline ll getnum()
{
    char c = getchar();
    int num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

ll A[200004];

int main()
{
    int n=getnum()-1,q=getnum()+1,l=1,r=2;

    ll x=getnum(),y=getnum();

    printf("%lld ",x+y);

    A[1]=x+y;

    for(int i=1;i<=n;i++)
    {
        x=getnum(),y=getnum();

        while(l<r&&x>=A[l])l++;

        if(r-l>=q)printf("-1 ");
        else
        {
            if(A[r-1]<x)A[r]=x+y;
            else A[r]=A[r-1]+y;

            printf("%lld ",A[r]);

            r++;
        }
    }
}