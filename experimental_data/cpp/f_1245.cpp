#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}
template<class T>T emax(T& t1,T t2){if(t1<t2)t1=t2;return t1;}
template<class T>T emin(T& t1,T t2){if(t1>t2)t1=t2;return t1;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

int l,r;
ll dp[35][2][2][2][2];

inline int getbit(int x,int p){
	return (x&(1<<p));
}

inline bool check(bool c1,bool c2,bool leasta,bool mosta,bool leastb,bool mostb,bool ln,bool rn){
	if(c1&&c2)return false;
	if((c1<ln)&&leasta)return false;
	if((c1>rn)&&mosta)return false;
	if((c2<ln)&&leastb)return false;
	if((c2>rn)&&mostb)return false;
	return true;
}

ll dfs(int pos,bool leasta,bool mosta,bool leastb,bool mostb){
	if(pos==-1)return 1ll;
	if(dp[pos][leasta][mosta][leastb][mostb]!=-1)return dp[pos][leasta][mosta][leastb][mostb];
	ll& ret=dp[pos][leasta][mosta][leastb][mostb];
	ret=0;
	bool bit1=getbit(l,pos);
	bool bit2=getbit(r,pos);
	//cerr<<getbit(l,0);
	//printf("PREV %d %d %d %d %d %d\n",pos,leasta,mosta,leastb,mostb,ret);
	for(int c1=0;c1<2;++c1){
		for(int c2=0;c2<2;++c2){
			if(c1==1&&c2==1||!check(c1,c2,leasta,mosta,leastb,mostb,bit1,bit2))continue;
			bool nxtla=leasta&&(bit1==c1),nxtra=mosta&&(bit2==c1),nxtlb=leastb&&(bit1==c2),nxtrb=mostb&&(bit2==c2);
			//if(pos==1&&nxtla==0&&nxtra==0&&nxtlb==0&&nxtrb==0)printf("HEY!%d %d %d %d %d %d\n",pos,leasta,mosta,leastb,mostb,ret);
		//	if(pos==2&&nxtla==0&&nxtra==)
			ret+=dfs(pos-1,nxtla,nxtra,nxtlb,nxtrb);
		}
	}
	//printf("%d %d %d %d %d %d\n",pos,leasta,mosta,leastb,mostb,ret);
	//cerr<<ret<<endl;
	return ret;
}

void MAIN(){
	memset(dp,-1,sizeof(dp));
	l=read(),r=read();
	printf("%lld\n",dfs(31,1,1,1,1));
}

int main(){
	int T=read();
	while(T--)MAIN();
	return 0;
}