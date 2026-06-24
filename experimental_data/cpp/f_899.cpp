#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int id(char x)
{
    if(x>='a'&&x<='z')return x-'a';
    if(x>='A'&&x<='Z')return 26+x-'A';
    return 52+x-'0';
}
char s[MAXN];
struct SegTree
{
    int l,r;
    int s;
    ll h;
}Tree[MAXN<<2];
void Maintain(int v)
{
    Tree[v].h=Tree[v<<1].h|Tree[v<<1|1].h;
    Tree[v].s=Tree[v<<1].s+Tree[v<<1|1].s;
}
void Build(int v,int L,int R)
{
    Tree[v].l=L;Tree[v].r=R;
	if(L==R)
	{
		Tree[v].h=1ll<<id(s[L]);
		Tree[v].s=1;
		return;
	}
	int mid=(L+R)>>1;
	Build(v<<1,L,mid);Build(v<<1|1,mid+1,R);
	Maintain(v);
}
int Find(int v,int k)
{
    if(Tree[v].l==Tree[v].r)return Tree[v].l;
    if(k<=Tree[v<<1].s)return Find(v<<1,k);
    return Find(v<<1|1,k-Tree[v<<1].s);
}
void Update(int v,int L,int R,int x)
{
    if(Tree[v].l>R||Tree[v].r<L)return;
    if(!(Tree[v].h>>x&1))return;
    if(Tree[v].l==Tree[v].r)
    {
        Tree[v].s--;
        Tree[v].h^=1ll<<x;
        return;
    }
    Update(v<<1,L,R,x);Update(v<<1|1,L,R,x);
    Maintain(v);
}
void Dfs(int v)
{
    if(!Tree[v].s)return;
    if(Tree[v].l==Tree[v].r)
    {
        cout<<s[Tree[v].l];
        return;
    }
    Dfs(v<<1);Dfs(v<<1|1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    Build(1,1,n);
    int l,r;
    char x[5];
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%s",&l,&r,&x);
        l=Find(1,l);r=Find(1,r);
        Update(1,l,r,id(x[0]));
    }
    Dfs(1);
    return 0;
}