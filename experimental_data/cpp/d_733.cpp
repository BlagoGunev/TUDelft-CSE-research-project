#include<bits/stdc++.h>

#define ll long long

#define pii pair<int,int>

#define piii pair<pair<int,int>,pair<int,int>>

#define ff first

#define ss second

#define mp make_pair

#define pb push_back

#define SIZE 10000002

#define MOD 1000000007

#define LD long double

using namespace std;



inline ll getnum()

{

    char c = getchar();

    ll num,sign=1;

    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;

    for(num=0;c>='0'&&c<='9';)

    {

        c-='0';

        num = num*10+c;

        c=getchar();

    }

    return num*sign;

}



piii P[200003];

int A[5];



int main()

{

    int n=getnum(),ans=0,sel,sel2=-1;



    for(int i=1;i<=n;i++)

    {

        for(int j=1;j<=3;j++)A[j]=getnum();

        sort(A+1,A+4);

        P[i]={{A[2],A[3]},{A[1],i}};



        if(ans<A[1])ans=A[1],sel=i;

    }



    sort(P+1,P+n+1);



    for(int i=1;i<=n;i++)

    {

        if(P[i].ff==P[i+1].ff)

        {

            int x=P[i].ss.ff+P[i+1].ss.ff;

            x=min(min(P[i].ff.ff,P[i].ff.ss),x);

            if(ans<x)ans=x,sel=P[i].ss.ss,sel2=P[i+1].ss.ss;

        }

    }



    if(sel2==-1)

    {

        puts("1");

        cout<<sel;

    }

    else

    {

        puts("2");

        cout<<sel<<' '<<sel2;

    }

}