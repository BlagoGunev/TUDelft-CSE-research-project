#include<bits/stdc++.h>
using namespace std;
#define loop(i,s,e) for(register int i=s;i<=e;++i)
#define anti_loop(i,s,e) for(register int i=s;i>=e;--i)
#define clean(arry,num) memset(arry,num,sizeof(arry))
#define ll long long
template<typename T>void read(T &x){
    char r=getchar();T neg=1;x=0;
    while(r>'9'||r<'0'){if(r=='-')neg=-1;r=getchar();}
    while(r>='0'&&r<='9'){x=(x<<1)+(x<<3)+r-'0';r=getchar();}
    x*=neg;
}
const int maxn=100+10;
int M[maxn];
inline bool work(int n,int m,int k){
	loop(i,1,n){
		if(i==n)
			return true;
		if(M[i]<M[i+1]-k)
			m=m-M[i+1]+M[i]+k;
		else if(M[i+1]-k<0)
			m+=M[i];
		else m+=M[i]-M[i+1]+k;
		if(m<0)
		    return false;
	}
}
int T;
int main(){
	read(T);
	while(T--){
		int n,m,k;
		read(n);
		read(m);
		read(k);
		clean(M,0);
		loop(i,1,n)
			read(M[i]);
		if(work(n,m,k))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}