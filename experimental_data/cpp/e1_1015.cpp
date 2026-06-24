#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint()
{
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//
const int N=110;
bool ok[N][N];
string s[N];
int n,m,hh[N][N];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
//
bool isvalid(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||s[x][y]=='.')return false;
	return true;
}
vector<iiii >ans;
void go(int x,int y,int h)
{
	rep(i,4)if(!isvalid(x+h*dx[i],y+h*dy[i]))return;
	ok[x][y]=true;
	rep(i,4)ok[x+h*dx[i]][y+h*dy[i]]=true;
	hh[x][y]=h;
	go(x,y,h+1);
}
int main()
{
	n=getint();m=getint();
	rep(i,n)cin>>s[i];
	rep(i,n)rep(j,m)if(s[i][j]=='*')
	{
		go(i,j,1);
	}
	rep(i,n)rep(j,m)if(s[i][j]=='*'&&!ok[i][j])return !printf("%d\n",-1);
	int res=0;
	rep(i,n)rep(j,m)if(hh[i][j]>0)res++;
	cout<<res<<endl;
	rep(i,n)rep(j,m)if(hh[i][j]>0)printf("%d %d %d\n",i+1,j+1,hh[i][j]);
	return 0;
}