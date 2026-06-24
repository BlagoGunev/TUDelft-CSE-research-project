#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define pr pair<int,int>
#define mp make_pair
#define x first
#define y second
using namespace std;
const int maxn=1e6+5;
int Q,len,f[maxn],g[maxn],cnt=1;
char Opt[15];
struct qur
{
	int opt,x;
	string s;
}q[maxn],a[maxn];
bool cmp(qur &X,qur &Y)
{
	if(X.s.size()!=Y.s.size()) return X.s.size()>Y.s.size();
	if(X.s!=Y.s) return X.s<Y.s;
	return X.x<Y.x;
}
struct Que
{
	priority_queue<pr,vector<pr>,greater<pr> > q1,q2;
	void ins(pr X){q1.push(X);}
	void del(pr X){q2.push(X);}
	int siz(){return q1.size()-q2.size();}
	pr top()
	{
		while(q1.size()&&q2.size()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
struct node
{
	int fa;
	unordered_map<char,int> nxt;
	Que v;
}t[maxn<<1];
void ins(int x)
{
	int now=1;
	for(char i:a[x].s)
	{
		if(!t[now].nxt.count(i)) cnt++,t[now].nxt[i]=cnt,t[cnt].fa=now;
		now=t[now].nxt[i];
	}
	g[a[x].x]=now;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		cin>>Opt;
		if(Opt[1]=='d') q[i].opt=1,cin>>q[i].x>>q[i].s,len++,a[len].s=q[i].s,a[len].x=q[i].x;
		else if(Opt[1]=='e') q[i].opt=2,cin>>q[i].x;
		else if(Opt[1]=='p') q[i].opt=3,cin>>q[i].s;
		else if(Opt[1]=='a') q[i].opt=4,cin>>q[i].x;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++) f[a[i].x]=i,ins(i);
	int loc=1,dep=0;
	for(int i=1;i<=Q;i++)
	{
		if(q[i].opt==1)
		{
			int x=g[q[i].x];
			while(x) t[x].v.ins(mp(f[q[i].x],q[i].x)),x=t[x].fa;
		}
		else if(q[i].opt==2)
		{
			int x=g[q[i].x];
			while(x) t[x].v.del(mp(f[q[i].x],q[i].x)),x=t[x].fa;
		}
		else if(q[i].opt==3)
		{
			if(dep) dep+=q[i].s.size();
			else
			{
				for(int j=0;j<q[i].s.size();j++)
				{
					if(t[loc].nxt.count(q[i].s[j])) loc=t[loc].nxt[q[i].s[j]];
					else
					{
						dep=q[i].s.size()-j;
						break;
					}
				}
			}
		}
		else
		{
			if(dep)
			{
				if(dep<=q[i].x) q[i].x-=dep,dep=0;
				else dep-=q[i].x,q[i].x=0;
			}
			while(q[i].x&&loc!=1) loc=t[loc].fa,q[i].x--;
		}
		if(dep==0&&t[loc].v.siz()) printf("%d\n",t[loc].v.top().y);
		else printf("-1\n");
	}
	return 0;
}