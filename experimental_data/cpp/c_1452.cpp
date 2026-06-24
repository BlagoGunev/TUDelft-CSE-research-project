#include<bits/stdc++.h>
#define lowbit(i) ((i)&(-(i)))
#define lson(i) ((i)<<1)
#define rson(i) ((i)<<1|1)
#define sqr(x) ((x)*(x))
#define fi first
#define se second
#define mp(x,y) make_pair((x),(y))
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> pii;
typedef vector<int> vii;
typedef vector<pii> vpi;
typedef queue<int> qii;

const int inf=0x3f3f3f3f;
const int maxn=200003;

int n,T;
char c[maxn];

int main(){
	scanf("%d",&T);
	while(T--){
		int s1=0,s2=0,res=0;
		scanf("%s",c+1);
		n=strlen(c+1);
		for(int i=1;i<=n;++i){
			if(c[i]=='(')++s1;
			else if(c[i]=='[')++s2;
			else if(c[i]==')'){
				if(s1){
					--s1;++res;
				}
			}else{
				if(s2){
					--s2;++res;
				}
			}
		}
		printf("%d\n",res);
	}
	
	return 0;
}