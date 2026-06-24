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

const int N=2e5+10,S=8000;

int n,m;

string s[N];

map<string,vector<string> >mp;

ll ans;

void solve1(vector<string>&v)

{

	for(int i=0;i<(int)v.size();i++)

		for(int j=i+1;j<(int)v.size();j++)

		{

			int l=0,r=m-1;

			while(v[i][l]==v[j][l])l++;

			while(v[i][r]==v[j][r])r--;

			ans+=2-is_sorted(v[i].begin()+l,v[i].begin()+r+1)-is_sorted(v[j].begin()+l,v[j].begin()+r+1);

		}

}

void solve2(vector<string>&v)

{

	ans+=v.size()*(v.size()-1);

	for(int i=0;i<(int)v.size();i++)

	{

		string t=v[i];

		for(int l=0;l<m;l++)

			for(int r=l+1;r<m;r++)

			{

				string tmp=t;

				sort(tmp.begin()+l,tmp.begin()+r+1);

				ans-=(t[l]!=tmp[l]&&t[r]!=tmp[r]&&binary_search(v.begin(),v.begin()+i,tmp));

			}

	}

}

int main()

{

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		cin>>s[i];string t=s[i];

		sort(t.begin(),t.end());

		mp[t].push_back(s[i]);

	}

	m=(int)s[1].size(),ans=1337ll*n*(n-1)/2;

	for(auto it:mp)

	{

		vector<string>v=it.second;

		ans-=1337ll*v.size()*(v.size()-1)/2;

		sort(v.begin(),v.end());

		if(v.size()<=S)solve1(v);

		else solve2(v);

	}

	printf("%lld",ans);

	IO::pchar(0);

	return 0;

}