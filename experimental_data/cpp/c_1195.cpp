#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll m,n,t,tmp[2];
ll a[2][(int)1e5+10];
ll d[2][(int)1e5+10];


template<typename T>
inline void re(T &N)
{
	char c; while((c=getchar())< '0'||c> '9');
	N=c-'0';while((c=getchar())>='0'&&c<='9')N=N*10+c-'0';
}
int main()
{
//	freopen("data.txt","r",stdin);
	re(n);
	for(int i=1;i<=n;i++)re(a[0][i]);
	for(int i=1;i<=n;i++)re(a[1][i]);
	tmp[0]=d[0][n]=a[0][n];
	tmp[1]=d[1][n]=a[1][n];
	for(int i=n-1;i>=1;i--)
	{
		d[0][i]=tmp[1]+a[0][i];
		d[1][i]=tmp[0]+a[1][i];
		tmp[0]=max(tmp[0],d[0][i]);
		tmp[1]=max(tmp[1],d[1][i]);
	}
	printf("%I64d\n",max(tmp[0],tmp[1]));
	return 0;
}