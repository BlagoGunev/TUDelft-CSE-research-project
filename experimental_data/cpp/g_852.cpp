#include <cstdio>
#include <set>
#include <map>
#include <cstring>
using namespace std;
const int maxl=51;
const int maxn=100010;
const int maxm=5010;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

int p[2]={467586783,763489791};
int pw[maxl][2];
int n,m,len;
map<pii,int> s[maxl];
set<pii> vis[4];
pii sv[5],sum;
int pos[5],plen[5];
int nq,ans;
char c;

int pw6(int nq)
{
	if (nq==0) return 1;
	else if (nq==1) return 6;
	else if (nq==2) return 36;
	else return 216;
}

int main()
{
	scanf("%d%d",&n,&m);
	pw[0][0]=pw[0][1]=1;
	for(int i=1;i<maxl;i++)
	{
		for(int j=0;j<2;j++)
			pw[i][j]=pw[i-1][j]*p[j];
	}
	
	c=getchar();
	for(int i=1;i<=n;i++)
	{
		pii tmp=mp(0,0);
		c=getchar();len=0;
		while(c!='\n')
		{
			tmp.x=tmp.x*p[0]+(c-'a'+1);
			tmp.y=tmp.y*p[1]+(c-'a'+1);
			c=getchar();len++;
		}
		s[len][tmp]++;
	}
	
	for(int i=1;i<=m;i++)
	{
		c=getchar();len=0;nq=0;
		for(int i=1;i<5;i++) sv[i]=mp(0,0),plen[i]=0;
		for(int j=0;j<=3;j++) vis[j].clear();
		
		while(c!='\n')
		{
			len++;
			if (c=='?')
			{
				nq++;
				pos[nq]=len;
			}
			else
			{
				sv[nq+1].x=sv[nq+1].x*p[0]+(c-'a'+1);
				sv[nq+1].y=sv[nq+1].y*p[1]+(c-'a'+1);
				plen[nq+1]++;
			}
			c=getchar();
		}
		
		int tot=pw6(nq);ans=0;
		for(int i=0;i<tot;i++)
		{
			sum=mp(0,0);
			int tmp=i,slen=0;
			
			for(int j=1;j<=nq;j++)
			{
				sum.x=sum.x*pw[plen[j]][0]+sv[j].x;
				sum.y=sum.y*pw[plen[j]][1]+sv[j].y;
				if (tmp%6==0) slen++;
				else
				{
					sum.x=sum.x*p[0]+tmp%6;
					sum.y=sum.y*p[1]+tmp%6;
				}
				tmp/=6;
			}
			
			sum.x=sum.x*pw[plen[nq+1]][0]+sv[nq+1].x;
			sum.y=sum.y*pw[plen[nq+1]][1]+sv[nq+1].y;
			if (vis[slen].find(sum)==vis[slen].end()) 
				{
					ans+=s[len-slen][sum];
					vis[slen].insert(sum);
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}