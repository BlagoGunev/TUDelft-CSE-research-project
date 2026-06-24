#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int lld;
typedef unsigned long long int ull;
typedef pair<ull,ull> PU;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(ull i=a;i<=b;i++)
#define FORD(i,a,b) for(ull i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( auto i=a.begin();i!=a.end();i++)

#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod

int main()
{
    std::ios_base::sync_with_stdio (false);
    long n,tmp,te;
    cin>>n;
    bool type[n+1];
    long ski[n+1],path[n+1];
    for(long i=1;i<=n;i++){cin>>type[i];}
    for(long i=1;i<=n;i++){ski[i]=0;}
    for(long i=1;i<=n;i++){cin>>tmp;ski[tmp]++;path[i]=tmp;}
    long m=0,tm=0;
    vector<long>ans,temp;
    for(long i=1;i<=n;i++)
    {
        tm=1;
        temp.clear();
        if(type[i])
        {
            temp.push_back(i);
            te=i;
            while(1)
            {
                tmp=path[te];
                if(ski[tmp]!=1)break;
                if(tmp==path[tmp])break;
                temp.push_back(tmp);
                tm++;
                te=tmp;
            }
            if(tm>m)
            {
                m=tm;
                ans.clear();
                for(vector<long>::iterator it=temp.begin();it!=temp.end();it++)ans.push_back(*it);
            }
        }
    }
    cout<<m<<endl;
    reverse(ans.begin(),ans.end());
    for(vector<long>::iterator it=ans.begin();it!=ans.end();it++)cout<<*it<<' ';
}