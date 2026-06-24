#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <climits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#define REP(i,n) for( int (i)=0;(i)<(int)(n); ++(i))
#define REPR(i,n) for( int (i) = n; (i)>=0; --(i))
#define REPN(i,x,y) for( int i = x; (i) < (int)(y); (i)++ )
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ZERO(x) memset(x,0,sizeof(x))
#define RI(n) scanf("%d",&(n))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define OI(x) printf("%d\n",(x))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define FT first
#define SD second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
LL LLMAX = 9223372036854775807LL;
const int MOD = 1000000007;
const int maxn = 2000000+10;
char a[maxn],b[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int n;
    RI(n);scanf("%*c");
    fgets(a, sizeof(a), stdin);fgets(b, sizeof(b), stdin);
    int c1=0,c2=0,cp=0;
    REP(i,2*n){
        if(a[i]=='1'&&b[i]=='1')cp++;
        else if(a[i]=='1')c1++;
        else if(b[i]=='1')c2++;
        else;
    }
    int sa=cp/2,sb=cp/2;
    if(cp%2==1)sa++;
    if(cp%2==1&&c2>0){
        sb++;
        c2--;
    }
    sa += c1;sb += c2;
    if(c1 == c2 - 1)sb--;
    if(sa == sb)puts("Draw");
    else if(sa > sb)puts("First");
    else puts("Second");
}