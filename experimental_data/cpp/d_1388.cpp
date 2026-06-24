#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define F(i,j,k) for(int i=(j);i<=(k);i++)
#define DF(i,j,k) for(int i=(j);i>=(k);i--)
#define M make_pair
#define P pair
#define dui priority_queue
using namespace std;
template<typename T>inline void read(T &n){
    T w=1;n=0;char ch=getchar();
    while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch^48);ch=getchar();}
    n*=w;
}
template<typename T>inline void write(T x){
    ull y=0;
    T l=0;
    if(x<0){x=-x;putchar('-');}
    if(!x){putchar(48);return;}
    while(x){y=y*10+x%10;x/=10;l++;}
    while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
    write(x);
    puts("");
}
template<typename T>inline void writes(T x){
    write(x);
    putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=a>b?a:b;}
template<typename T>inline void checkmin(T &a,T b){a=a<b?a:b;}
const int N=2e5+100;
int cnt,head[N],nxt[N],to[N];
LL val[N],ans;
int an1[N],an2[N],cnt1,cnt2,du[N];
inline void addedge(int x,int y){
	nxt[++cnt]=head[x];
	to[cnt]=y;
	head[x]=cnt;
}
queue<int> q;
int main(){
 	//freopen(".in","r",stdin);
 	//freopen(".out","w",stdout);
 	int n;read(n);
 	F(i,1,n)read(val[i]);
 	F(i,1,n){int x;read(x);if(x!=-1){du[x]++;addedge(i,x);}}
 	F(i,1,n)if(!du[i])q.push(i);
 	while(!q.empty()){
 		int tx=q.front();q.pop();
 		ans+=val[tx];
 		if(val[tx]<=0){
		 	cnt2++;
			an2[cnt2]=tx;
			for(int i=head[tx];i;i=nxt[i]){du[to[i]]--;if(!du[to[i]])q.push(to[i]);}
		}
 		else {
 			cnt1++;
 			an1[cnt1]=tx;
 			for(int i=head[tx];i;i=nxt[i]){
 				du[to[i]]--;
 				val[to[i]]+=val[tx];
 				if(!du[to[i]])q.push(to[i]);
 			}
 		}
 	}
 	writeln(ans);
 	F(i,1,cnt1)writes(an1[i]);
 	DF(i,cnt2,1)writes(an2[i]);
 	puts("");
    return 0;
}