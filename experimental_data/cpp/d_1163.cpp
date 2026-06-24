#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxs 1010
#define maxs2 55
#define maxc 26
char s[maxs],t[maxs2];
int n;
struct AC{
    int cnt,ch[maxs2<<1][maxc],val[maxs2<<1],f[maxs<<1];
    void init(){cnt=0;}
    inline int idx(char c){return c-'a';}
    inline void insert(char *s,int len,int w){
        int u=0;
        for(int i=1;i<=len;++i){
            int c=idx(s[i]);
            if(!ch[u][c])ch[u][c]=++cnt;
            u=ch[u][c];
        }
        val[u]+=w;
    }
    queue<int>q;
    void build(){
        for(int i=0;i<maxc;++i)if(ch[0][i])q.push(ch[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int c=0;c<maxc;++c){
                int v=ch[u][c];
                if(!v){ch[u][c]=ch[f[u]][c];continue;}
                q.push(v);
                f[v]=ch[f[u]][c];
                val[v]+=val[f[v]];
            }
        }
    }
    int dp[maxs][maxs2<<1]; 
    void solve(){
    	int ans=-(1e9);
    	for(int i=0;i<maxs;++i)for(int j=0;j<(maxs2<<1);++j)dp[i][j]=-(1e9);
    	dp[0][0]=0;
    	for(int i=0;i<n;++i)
    	for(int j=0;j<=cnt;++j){
    		int lst=dp[i][j];	
			for(int k=0;k<maxc;++k)
			if(s[i+1]=='*'||idx(s[i+1])==k){	
    			int nxs=ch[j][k];
    			dp[i+1][nxs]=max(dp[i+1][nxs],lst+val[nxs]);
    			if(i+1==n)ans=max(ans,dp[i+1][nxs]);
    		}
		}
		cout<<ans<<endl;
    }
}ac;
void init(){
	scanf("%s",s+1);n=strlen(s+1);
	ac.init();
	scanf("%s",t+1);
	ac.insert(t,strlen(t+1),1);
	scanf("%s",t+1);
	ac.insert(t,strlen(t+1),-1);
	ac.build();
}
void solve(){ac.solve();}
int main(){
	init();
	solve();
	return 0;
}