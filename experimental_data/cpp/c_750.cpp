#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pf printf
#define sf scanf
#define F5 fflush(stdout)
using namespace std;
inline int G(){
	char tt=getchar();int o,f=0;
	while(tt<'0'||tt>'9'){if(tt=='-')f=1;tt=getchar();}
	for(o=0;tt>='0'&&tt<='9';tt=getchar())o=o*10+tt-'0';
	return f?-o:o;
}
typedef long long ll;
const int INF = 0x3c3c3c3c;
int n,i,j,t,k,l=-INF,d,r=INF;
int A[200005];
int main(){
	n=G();
	for(i=1;i<=n;i++){
		t=G();k=G();
		if(k==1)l=max(l,1900-d);
		else r=min(r,1899-d);
		d+=t;
	}
	//cout<<l<<" "<<r<<endl;
	if(l>r) puts("Impossible");
	else if(r==INF) puts("Infinity");
	else cout<<r+d<<endl;
	return 0;
}