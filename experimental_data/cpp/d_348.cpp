#include <vector>
#include <list>
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

using namespace std;

typedef long long i64;
const int inf = 1000000007 ;
int n,m;
char s[3010][3010];
void cal(int f[][3010],int x,int y)
{
    f[1][1]=1;
    for(int i=x;i<=n;++i)
        for(int j=y;j<=m;++j)if(s[i][j]!='#')
        {
            f[i][j]=f[i][j-1]+f[i-1][j];
            if(f[i][j]>=inf)    f[i][j]-=inf;
        }
}
int f1[3010][3010],f2[3010][3010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)   scanf("%s",&s[i][1]);
    cal(f1,1,2);
    cal(f2,2,1);
    i64 a=f1[n-1][m],b=f2[n][m-1];
    i64 c=f1[n][m-1],d=f2[n-1][m];
    cout<<(a*b%inf-c*d%inf+inf)%inf<<endl;
    return 0;
}