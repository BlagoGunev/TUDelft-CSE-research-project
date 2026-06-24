#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int time1[1000000], time2[1000000];

void exgcd(long long a, long long b, long long &g, long long &x, long long &y){
	if(!b) {x=1; y=0; g=a;}
	else{
		exgcd(b,a%b,g,y,x);
		y-=x*(a/b);
	}
}

long long inv(long long a, long long n){
	long long d,x,y;
	exgcd(a,n,d,x,y);
	return d==1?(x+n)%n:-1;
}

int main(){
	int m; scanf("%d",&m);
	int h1,a1,x1,y1;
	scanf("%d%d%d%d",&h1,&a1,&x1,&y1);
	int h2,a2,x2,y2;
	scanf("%d%d%d%d",&h2,&a2,&x2,&y2);
	memset(time1, -1, sizeof(time1));
	int p1 = -1, q1 = -1;
	for(int i = 0; i<=m; i++){
		if(time1[h1]==-1) time1[h1] = i;
		else{
			//loop detected
			p1 = time1[h1];
			q1 = i - time1[h1];
			break;
		}
		h1 = ((long long)h1*x1+y1)%m;
	}
	memset(time2, -1, sizeof(time2));
	int p2 = -1, q2 = -1;
	for(int i = 0; i<=m; i++){
		if(time2[h2]==-1) time2[h2] = i;
		else{
			p2 = time2[h2];
			q2 = i - time2[h2];
			break;
		}
		h2 = ((long long)h2*x2+y2)%m;
	}
	//printf("%d %d %d %d\n",p1,q1,p2,q2);
	if(time1[a1]==-1||time2[a2]==-1) {puts("-1"); return 0;}
	if(time1[a1]<p1&&time2[a2]<p2) 
		if(time1[a1]==time2[a2]){
			printf("%d\n",time1[a1]);
			return 0;
		}else{
			puts("-1"); return 0;
		}
	if(time1[a1]<p1)
		if(time1[a1]>=time2[a2]&&(time1[a1]-time2[a2])%q2==0){
			printf("%d\n",time1[a1]);
			return 0;
		}else{
			puts("-1");
			return 0;
		}
	if(time2[a2]<p2)
		if(time2[a2]>=time1[a1]&&(time2[a2]-time1[a1])%q2==0){
			printf("%d\n",time2[a2]);
			return 0;
		}else{
			puts("-1");
			return 0;
		}
	long long ans0 = time1[a1], ans1 = time2[a2];
	long long d0 = q1, d1 = q2;
	if(ans1<ans0) {swap(ans1,ans0); swap(d1,d0);}
	long long A = d0, B = ans1 - ans0, N = d1;
	long long g = __gcd(A,N);
	if(B%g) {puts("-1"); return 0;}
	A/=g; N/=g; B/=g;
	long long x = (inv(A,N)*B)%N;
	ans0 += d0*x;
	d0 = d0/__gcd(d0,d1)*d1;
	while(ans0<ans1) ans0+=d0;
	printf("%lld\n",ans0);

	return 0;
}