#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define all(x) (x).begin(),x.end()
template<class T>
auto ary(T *a,int l,int r){
	return vector<T>{a+l,a+1+r};
}
template<class T>
auto each(int l,int r,const T &f){
	auto x=f(l);
	vector<decltype(x)>t{x};
	for(int i=l+1;i<=r;i++)t.push_back(f(i));
	return t;
}
template<bool x>
using If=typename enable_if<x>::type;
template<int i,class T>
If<i==0> otp(ostream &out,T a){
	out<<get<i>(a);
}
template<int i,class T>
If<i!=0> otp(ostream &out,T a){
	otp<i-1>(out,a),out<<','<<get<i>(a);
}
template<class T>
ostream& operator << (ostream &out,vector<T> a);
template<class...T>
ostream& operator << (ostream &out,tuple<T...>a){
	return out<<'(',otp<sizeof...(T)-1>(out,a),out<<')';
}
template<class T>
ostream& operator << (ostream &out,vector<T> a){
	out<<'[';
	for(auto x:a)out<<x<<',';
	return out<<']';
}
#ifdef DEBUG
template<class T>
void debug(T x){
	cerr<<x<<endl;
}
template<class T,class...S>
void debug(T x,S...y){
	cerr<<x<<' ',debug(y...);
}
#else
#define debug(...) void()
#endif
const int N=1e2+10;
int n,m,q;
struct node{
	int x,y,q;
	bool operator == (const node &a)const{
		return x==a.x&&y==a.y;
	}
}rp[10],bp[10],B,Q,S;
int rg[N][N],bg[N][N];
void go(node &a,char c){
	if(c=='U')a.x--;
	else if(c=='D')a.x++;
	else if(c=='L')a.y--;
	else if(c=='R')a.y++;
	else assert(0);
}
int rs,bs;
void end(){
	printf("FINAL SCORE: %d %d\n",rs,bs);
	exit(0);
}
#undef assert
#define assert(x) for(;!x;)puts("Wrong")
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			static char str[9];
			scanf("%s",str);
			if(str[0]=='.'&&str[1]=='.')continue;
			if(str[0]=='R'){
				if(str[1]=='G')rg[i][j]=1;
				else rp[str[1]-'0']={i,j,0};
			}else if(str[0]=='B'){
				if(str[1]=='G')bg[i][j]=1;
				else bp[str[1]-'0']={i,j,0};
			}else{
				if(str[1]=='B')B={i,j,0};
				else if(str[1]=='S')S={i,j,0};
				else if(str[1]=='Q')Q={i,j,0};
				else assert(0);
			}
		}
	}
	scanf("%d",&q);
	for(int t=0;t<q;t++){
		static char str[9];
		scanf("%s",str);
		if(str[0]=='R'){
			int i=str[1]-'0';
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%s",str);
				if(str[1]=='Q')rp[i].q=1;
				else if(str[1]=='S'){
					printf("%d RED CATCH GOLDEN SNITCH\n",t);
					rs+=10;
					end();
				}else assert(0);
			}else if(str[0]=='T'){
				rp[i].q=0;
				// debug(Q.x,Q.y);
				if(rg[Q.x][Q.y]){
					printf("%d BLUE GOAL\n",t);
					bs++,Q={(n+1)/2,(m+1)/2};
				}else if(bg[Q.x][Q.y]){
					printf("%d RED GOAL\n",t);
					rs++,Q={(n+1)/2,(m+1)/2};
				}
			}else{
				go(rp[i],str[0]);
				if(rp[i].q)go(Q,str[0]);
				if(rp[i]==B){
					rp[i]={0,0,0};
					printf("%d R%d ELIMINATED\n",t,i);
				}
			}
		}else if(str[0]=='B'){
			int i=str[1]-'0';
			scanf("%s",str);
			if(str[0]=='C'){
				scanf("%s",str);
				if(str[1]=='Q')bp[i].q=1;
				else if(str[1]=='S'){
					printf("%d BLUE CATCH GOLDEN SNITCH\n",t);
					bs+=10;
					end();
				}else assert(0);
			}else if(str[0]=='T'){
				bp[i].q=0;
				if(rg[Q.x][Q.y]){
					printf("%d BLUE GOAL\n",t);
					bs++,Q={(n+1)/2,(m+1)/2};
				}else if(bg[Q.x][Q.y]){
					printf("%d RED GOAL\n",t);
					rs++,Q={(n+1)/2,(m+1)/2};
				}
			}else{
				go(bp[i],str[0]);
				if(bp[i].q)go(Q,str[0]);
				if(bp[i]==B){
					bp[i]={0,0,0};
					printf("%d B%d ELIMINATED\n",t,i);
				}
			}
		}else{
			if(str[1]=='B'){
				scanf("%s",str);
				go(B,str[0]);
				for(int i=0;i<10;i++){
					if(bp[i]==B){
						bp[i]={0,0,0};
						printf("%d B%d ELIMINATED\n",t,i);
					}
				}
				for(int i=0;i<10;i++){
					if(rp[i]==B){
						rp[i]={0,0,0};
						printf("%d R%d ELIMINATED\n",t,i);
					}
				}
			}else if(str[1]=='S'){
				scanf("%s",str);
				go(S,str[0]);
			}else{
				scanf("%s",str);
				go(Q,str[0]);
			}
		}
	}
	end();
	return 0;
}