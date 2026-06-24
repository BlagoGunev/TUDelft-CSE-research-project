#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<string>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define CL(a,b) memset(a,b,sizeof(a))

const int M=1000020;
const int N=50;
const int inf=1<<29;
const double eps=1e-8;
const double pi=acos(-1.0);

char s[M];
int pos[30];
int cnt,len;
int n;

int main()
{
    scanf("%d",&n);
    cnt=1;
    len=0;
    while(1)
    {
        for(int i=0;i<26;i++)
        {
            if(!pos[i] || cnt-pos[i]==4 || cnt-pos[i]==7)
            {
                s[len]=('a'+i);
                pos[i]=cnt;
                len++;
                cnt++;
                break;
            }
        }
        if(cnt>n) break;
    }
    s[len]=0;
    puts(s);
//  system("pause");
    return 0;
}