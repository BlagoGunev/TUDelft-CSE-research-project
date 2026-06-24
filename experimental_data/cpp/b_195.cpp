//convert stl string to char array{string stl, char    *arr=stl.c_str()}
//convert char array to string{char arr[]; string str; str.assign(arr)}
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstring>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,a,b) for(int (i)=a;(i)<(b);(i)++)
#define INF 2000000001
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({LL x;scanf("%lld", &x);x;})
#define _mp make_pair
#define MOD 1000000007
#define MAXN 90000000000LL
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
set<double>ss;
set<double>::iterator it;
int main()
{
 int tt,n,m;
 n=SS;m=SS;
 tt=(int)ceil(m*1.0/2);
 int prev=tt-1;
 int front=tt+1;
 bool cn1,cn2;
 if(m%2) {cn1=true;bool cn2=false;}
 if(m%2==0) {cn1=false;cn2=true;}
 printf("%d\n",tt);
 n--;
 while(n--)
  {
        if(prev<1 && front>m)
         {
            printf("%d\n",tt);
            if(m%2) {cn1=true;bool cn2=false;}
            if(m%2==0) {cn1=false;cn2=true;}
            prev=tt-1;
            front=tt+1;
         }
        else if(cn1 && prev>=1)
         {
            cn1=false,cn2=true;
            printf("%d\n",prev);
            prev--;
         }
        else if(cn2 && front<=m)
         {
            cn2=false,cn1=true;
            printf("%d\n",front);
            front++;

         }
        else if(cn1 && prev<1 && front<=m)
         {
           printf("%d\n",front);
           front++;
           cn1=false,cn2=true;
         }
        else if(cn2 && front>m &&prev>=1)
         {
           printf("%d\n",prev);
           prev--;
           cn2=false,cn1=true;
         }
  }
 return 0;
}