#include<cstdio>
#include<algorithm>
#define MAXN 200000
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q,q2;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int ans,cnt,n,k,a[MAXN+10];
bool flag;
void read(){
	Read(n),Read(k);
	int i,la=0,d=0;
	for(i=1;i<=n;i++){
		Read(a[i]);
		if(a[i]<0)
			d++;
	}
	if(d>k){
		puts("-1");
		return;
	}
	for(i=n;i;i--){
		if(a[i]<0){
			if(la&&la!=i+1){
				cnt+=2;
				q.push(la-i-1);
			}
			la=i;
		}
	}
	if(la)
		cnt++;
	if(a[n]>=0&&la){
		cnt++;
		flag=1;
		for(i=n;a[i]>=0;i--);
		la=i;
	}
	ans=cnt;
	int ttcnt=cnt,td=d;
	q2=q;
	while(!q.empty()&&d+q.top()<=k){
		cnt-=2;
		d+=q.top();
		q.pop();
	}
	ans=min(ans,cnt);
	cnt=ttcnt;
	d=td;
	q=q2;
	if(flag){
		if(d+n-la<=k){
			d+=n-la;
			cnt--;
			while(!q.empty()&&d+q.top()<=k){
				cnt-=2;
				d+=q.top();
				q.pop();
			}
			ans=min(ans,cnt);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	read();
}