#include<bits/stdc++.h>

#define ll long long

#define pii pair<int,int>

#define piii pair<int,pair<int,int> >

#define ff first

#define ss second

#define mp make_pair

#define pb push_back

#define SIZE 10000002

#define MOD (long long)1000000007

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



ll A[500004],L[500004],R[500004];



int main()

{

    int n=getnum();

    ll sum=0;

    for(int i=1;i<=n;i++)

    {

        A[i]=getnum();

        sum+=A[i];

    }



    if(sum%3!=0)

    {

        puts("0");

        return 0;

    }



    sum/=3;

    ll sum2=0,ans=0;



    for(int i=1;i<=n;i++)

    {

        sum2+=A[i];

        if(sum2==sum)L[i]=1;

        L[i]+=L[i-1];

    }



    sum2=0,ans=0;

    for(int i=n;i>=2;i--)

    {

        sum2+=A[i];

        if(sum2==sum)ans+=L[i-2];

    }



    cout<<ans;

}