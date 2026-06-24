/*********************************************************************\
     ______    __      ______ __        __ ________   _______         |
    |      \   /\     |      \ \        /  |       !        /         |
    |       ! /  \    |       ! \      /   |               /          |
    |______/ /____\   |______/   \    /    |----|      ___/           |
    |       /      \  |    ^\     \  /     |          /               |
    |      /        \ |      \     \/      |_______! /_______         |
   ---    ---      ----     ---    --                                 |
    codeforces = kmparvez                                             |
    mail = parvezmy@gmail.com || kmparvez2@gmail.com                  |
    CSE, Premier University,Chittagong                                |
                                                                      |
**********************************************************************/


#include<bits/stdc++.h>
using namespace std;

#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)

#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ff first
#define ss second
#define pb  push_back
#define mp   make_pair
#define inf  INT_MAX/3
#define mod  1000000007ll
#define PI   acos(-1.0)
#define linf  (1ll<<60)-1
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template<class T>
//faster input
inline T IN(T& num)
{
    num = 0;
    char c = getchar(), f = 0;
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-') f = 1, c = getchar();
    while('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
    if(f) num = -num;
    return num;
}

int a[2000006]={0};
int main()
{
int n;


IN(n);
fore(i,0,n)
{
    int x;
    IN(x);
    a[x]++;
}
int ans = 0;
fore(i,1,2000005)
{
    a[i] = a[i]+(a[i-1]/2);
    ans+=(a[i-1]%2);
}
cout<<ans<<endl;
    return 0;
}