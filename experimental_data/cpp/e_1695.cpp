#include<bits/stdc++.h>

#define ll long long

#define lll __int128

#define db double

#define ld long double

#define pii pair<int,int>

#define fi first

#define se second

using namespace std;

namespace IO

{

	const int SZ=1<<20;

	char gchar()

	{

	    static char buf[SZ];

	    static int i=SZ;

	    if(i==SZ)i=0,fread(buf,1,SZ,stdin);

	    return buf[i++];

	}

	void pchar(char c)

	{

	    static char buf[SZ];

	    static int i=0;

	    if(c)buf[i++]=c;

	    if(!c||i==SZ)fwrite(buf,1,i,stdout),i=0;

	}

	void pstr(string s,char end='\n')

	{

		for(char c:s)pchar(c);

		pchar(end);

	}

	template<typename T>void read(T &x)

	{

	    x=0;int f=1;

	    static char c;

	    while((c=gchar())>'9'||c<'0')if(c=='-')f=-1;

	    x=c-'0';

	    while((c=gchar())>='0'&&c<='9')

			x=(x<<1)+(x<<3)+(c^48);

		x*=f;

	}

	template<typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}

	template<typename T>void i_write(T x)

	{

	    if(x>9)i_write(x/10);

	    pchar(x%10+'0');

	}

	template<typename T>void write(T x,char end='\n')

	{

	    if(x<0)pchar('-'),x=-x;

	    if(x>9)i_write(x/10);

	    pchar(x%10+'0');

	    pchar(end);

	}

}

using IO::read;

using IO::write;

const int N=6e5+10;

int n,h[N],stk[N],top;

struct edge

{

	int u,v,id;

};

vector<edge>e[N];

bool vis[N];

void dfs(int u)

{

	for(int i=h[u];i<(int)e[u].size();i=h[u])

	{

		h[u]=i+1;

		if(vis[e[u][i].id])continue;

		vis[e[u][i].id]=1;

		dfs(e[u][i].v);

	}

	stk[++top]=u;

}

int ans0[2][N];

char ans1[2][2][N];

int main()

{

	read(n);

	for(int i=1,x,y;i<=n;i++)

		read(x,y),e[x].push_back((edge){x,y,i}),e[x].push_back((edge){x,y,n+i}),

		e[y].push_back((edge){y,x,i}),e[y].push_back((edge){y,x,n+i});

	for(int i=1,now=0;i<=n<<1;i++)

	{

		top=0,dfs(i);

		if(top<2)continue;

		if(top<4){puts("-1");return 0;}

		for(int j=1;j<top/2;j+=2)

		{

			ans1[0][0][now+j]=ans1[0][1][now+j]='L';

			ans1[0][0][now+j+1]=ans1[0][1][now+j+1]='R';

		}

		if((top/2)&1)ans1[0][0][now+top/2]='U',ans1[0][1][now+top/2]='D';

		ans1[1][0][now+1]='U',ans1[1][1][now+1]='D';

		for(int j=2;j<top/2;j+=2)

		{

			ans1[1][0][now+j]=ans1[1][1][now+j]='L';

			ans1[1][0][now+j+1]=ans1[1][1][now+j+1]='R';

		}

		if((top/2)%2==0)ans1[1][0][now+top/2]='U',ans1[1][1][now+top/2]='D';

		for(int j=1;j<=top/2;j++)ans0[0][now+j]=stk[j],ans0[1][now+j]=stk[top-j];

		now+=top/2;

	}

	write(2,' '),write(n);

	for(int i=0;i<2;i++,IO::pchar('\n'))

		for(int j=1;j<=n;j++)

			write(ans0[i][j],' ');

	IO::pchar(0);

	for(int i=0;i<2;i++)

		for(int j=0;j<2;j++,putchar('\n'))

			for(int k=1;k<=n;k++)

				putchar(ans1[i][j][k]);

	return 0;

}