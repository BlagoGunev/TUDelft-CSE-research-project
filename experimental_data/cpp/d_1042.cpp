#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read()
{
    int X=0;char ch=0;bool flag=0;
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') flag=1;
	for(;isdigit(ch);ch=getchar()) X=(X<<3)+(X<<1)+ch-'0';
	return(flag ? -X : X);
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+1;
int n,cur,a[N],b[N];
ll t,treee[N],cnt[N],ans;
void change(int wz)
{
	for(int i=wz;i<=cnt[0];i+=lowbit(i)) ++b[i];
}
int sum(int wz)
{
	int re=0;
	for(int i=wz;i;i-=lowbit(i)) re+=b[i];
	return re;
}
int main()
{
	scanf("%d",&n);cin>>t;
	for(int i=1;i<=n;i++)
		a[i]=read(),cnt[++cnt[0]]=treee[i]=treee[i-1]+a[i];
	cnt[++cnt[0]]=0;
	sort(cnt+1,cnt+cnt[0]+1);
	cnt[0]=unique(cnt+1,cnt+cnt[0]+1)-cnt-1;
	for(int i=1;i<=cnt[0];i++)
		if(!cnt[i]) cur=i;
	change(cur);
	for(int i=1;i<=n;i++)
		treee[i]=lower_bound(cnt+1,cnt+cnt[0]+1,treee[i])-cnt;
	for(int i=1;i<=n;i++)
	{
		ll tmp=upper_bound(cnt+1,cnt+cnt[0]+1,cnt[treee[i]]-t)-(cnt+1);
		ans+=i-sum(tmp);
		change(treee[i]);
	}
	printf("%I64d",ans);
}