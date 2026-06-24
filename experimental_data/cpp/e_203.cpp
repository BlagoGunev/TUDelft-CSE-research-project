#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define rank krevedka
#define ran rank
using namespace std;

int c[100500];
int f[100500];


int main()
{
    int n,d,s;
    scanf("%d%d%d",&n,&d,&s);
    int m = s+1;
    long long sum = 0;

    for(int i=0;i<n;i++)
    {
        int l;
        scanf("%d%d%d",c+i,f+i,&l);
        if(l<d) f[i] = s+1;
        if(c[i]>0 && f[i]<m) m = f[i];
        sum += c[i];
    }
    sort(f,f+n);
    int res1 = 0;
    int ts = s;
    for(int i=0;i<n;i++)
    if(f[i]<=ts){ts-=f[i]; res1++;}else break;
    int sum1 = s - ts;
    if(m>s)
    {
        cout << res1<<' '<<sum1<<endl;
        return 0;
    }
    ts = s - m;
    sum++;
    if(sum>n) sum = n;
    int res2 = sum;
    if(res2>n) res2 = n;
    for(int i=0;i<n;i++)
    if(f[i]==m){m=-1; continue;}else
    if(res2<n && f[i]<=ts){res2++; ts-=f[i];} else break;

    int sum2 = s - ts;
    if(res1>res2) cout << res1<< ' '<<sum1<<endl; else
    if(res1<res2) cout << res2<< ' '<<sum2<<endl; else
                  cout << res1<< ' '<<min(sum1,sum2)<<endl;
    return 0;
}