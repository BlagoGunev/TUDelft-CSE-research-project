#include<bits/stdc++.h>

using namespace std;

inline int read()

{

	char c=getchar();int x=0,f=1;

	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}

	while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}

	return x*f;

}

const int N=550;

char s[N][N];

int c[N][N],a[N][N],cnt,ans;

int main()

{

	int n=read(),m=read();

	for(int i=1;i<=n;i++)

		scanf("%s",s[i]+1);

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			c[i][j]=s[i][j]=='B';

	for(int i=1;i<=n;i++)

		for(int j=1;j<=m;j++)

			a[i][j]=(c[i][j]+c[i][j+1]+c[i+1][j]+c[i+1][j+1])&1,cnt+=a[i][j];

	int flag=0;

	for(int i=1;!flag&&i<n;i++)

	{

		for(int j=1;j<m;j++)

			if(a[n][m]&&a[i][j]&&a[i][m]&&a[n][j])

			{

				cnt-=4,ans+=3;flag=1;

				break;

			}

	}

	cout<<ans+cnt<<endl;

	return 0;

}