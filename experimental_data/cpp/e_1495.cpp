#include<bits/stdc++.h>

#define HCL_AK_IOI 114514

#define fs(i,x,y,z) for(register int i=x;i<=y;i+=z)

#define ft(i,x,y,z) for(register int i=x;i>=y;i+=z)

#define int long long

#define ull unsigned long long

#define db double

#define ms(a,b) memset(a,b,sizeof(a))

#define sz(a) sizeof(a)

#define box(x,y) (x*100000+y)

using namespace std;

const int N=5000001,inf=1e9+7;

inline int read(){

	int date=0,w=1;char c=0;

	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}

	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}

	return date*w;

}

#define lowbit(x) (x&(-x))

int n,m,seed,base,t[N],a[N],ans[N],p[200001],k[200001],b[200001],w[200001],s[3],cnt,cur=1;//t是一个bot的阵营，a是一个bot有几张牌 

int rnd(){

	int ret=seed;

	seed=(seed*base+233)%inf;

	return ret;

}

void rd(){

	n=read(),m=read();

	fs(i,1,m,1) p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();

	for(int i=1;i<=m;i++){

		seed=b[i]; base=w[i];

		fs(j,p[i-1]+1,p[i],1){

			t[j]=rnd()%2+1;

			a[j]=rnd()%k[i]+1;

		}

	}

}

signed main(){

	rd();

	fs(i,1,n,1) s[t[i]]+=a[i];

	if(s[1]>s[2]){//优先让1阵营最小——出完牌 

		swap(s[1],s[2]);

		fs(i,1,n,1) t[i]=3-t[i];

	}//cur代表从谁开始 

	if(t[1]!=1){

		ans[1]++,a[1]--;

		fs(i,2,n,1) if(t[i]==1){cur=i;break;}

	}

	while(cnt||s[1]){

		if(t[cur]==1){

			ans[cur]+=a[cur];//这个人要润掉几张

			cnt+=a[cur],s[1]-=a[cur],a[cur]=0;//这个A对应后边的第一个B，cnt代表A现在的和 

		}else{

			int d=min(a[cur],cnt);//现在到B了，可以润掉几发，如果A比较逊那就只下放cnt 

			ans[cur]+=d,cnt-=d,a[cur]-=d;//B得润几发出来 

		} 

		cur=(cur==n)?1:cur+1;//润下一个 

	}

	int otp=1;

	fs(i,1,n,1) otp=(otp*(((ans[i]^(i*i))%inf+1)%inf))%inf;

	cout<<otp;

	return 0;

}

/*

A对应后边较前的B，B代表前边较后的A 

*/