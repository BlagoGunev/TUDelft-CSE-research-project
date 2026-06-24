/** I don't know who you are. I don't know what you want.
  * If you are looking for a perfect solution, I can tell you I don't have one.
  * But what I do have are a very particular set of skills. Skills I have acquired after a lot of practice.
  * Skills that make me a nightmare for people like you.
  * If you leave this code now that'll be the end of it. I will not look for you, I will not pursue you.
  * But if you don't, I will look for you, I will find you and I will kill you.
 **/
#include <bits/stdc++.h>
#define ll long long int
#define MAX 105
#define EPS 1e-9
#define MOD 1000000007
#define INF 1e9
#define pn() printf("\n")
#define vint vector <int>
#define vpint vector <pair<int,int> >
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define gc() getchar_unlocked()
#define ms(x,v) memset(x,v,sizeof x)
#define pr_arr(i,x,size) for(i=0;i<size;i++) cout<<x[i]<<" "
#define ff(i,a,b) for(i=a;i<=b;i++)
#define fb(i,a,b) for(i=a;i>=b;i--)
#define gprint(i) cout<<"Case #"<<i<<": "
using namespace std;

vpint adj[MAX];
int visited[MAX];
bool dfs(int u,int v,int col)
{
	int i;
	visited[u]=1;
	if(u==v)
		return 1;
	vpint :: iterator it;
	for(it=adj[u].begin();it!=adj[u].end();it++)
	{
		if(it->sd==col && visited[it->ft]==0)
		{
			if(dfs(it->ft,v,col))
				return 1;
		}
	}
	return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	adj[a].pb(mp(b,c));
    	adj[b].pb(mp(a,c));
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int u,v,cnt=0,i;
    	cin>>u>>v;
    	ff(i,1,100)
    	{
    		ms(visited,0);
    		if(dfs(u,v,i))
    			cnt++;
    	}
    	cout<<cnt<<endl;
    }
    return 0;
}