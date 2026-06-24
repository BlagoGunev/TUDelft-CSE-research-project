#include<bits/stdc++.h>
using namespace std;
#ifdef Anson
	#define debug
#else
	#ifdef debug
		#undef debug
	#endif
#endif
const int lgN=21,N=(1<<lgN);
int n,m,bit[N];unsigned long long f[N],g[N],ans[N];
void fwt(unsigned long long f[],int inv) {
	for(int mid=1;mid<n;mid=(mid<<1))
		for(int i=0;i<n;i+=(mid<<1))
			for(int j=i;j<mid+i;++j)f[mid+j]+=f[j]*inv;
	return;
}
int main() {
#ifdef Anson
	#ifdef debug
		puts("function main");
	#endif
	freopen("C:\\Users\\Administrator\\Documents\\input.txt","r",stdin);
#else
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	for(int i=0;i<N;i++) {
		bit[i]=bit[i>>1];
		if(i&1)bit[i]=bit[i]+2;
	}
	scanf("%d ",&m);n=(1<<m);
	for(int i=0;i<n;i++)f[i]=((unsigned long long)(getchar()-'0')<<bit[i]);
	scanf(" ");for(int i=0;i<n;i++)g[i]=((unsigned long long)(getchar()-'0')<<bit[i]);
	fwt(f,1);fwt(g,1);
	for(int i=0;i<n;i++)ans[i]=f[i]*g[i];fwt(ans,-1);
	for(int i=0;i<n;i++)putchar(((ans[i]>>bit[i])&3ull)+'0');
	return 0;
}
#ifdef Anson
	#undef Anson
#endif
#ifdef debug
	#undef debug
#endif