#include<bits/stdc++.h>
#define gc getchar
#define re register
#define rep(i,s,t) for(re int i=s;i<=t;++i)
#define reb(i,s,t) for(re int i=s;i>=t;--i)

template<class T>inline void Readin(T &X){
	X=0;
	register bool F=false;
	register char C=gc();
	while(C<'0' or C>'9'){if(C=='-')F=true;C=gc();}
	while(C<='9' and C>='0')X=(X<<1)+(X<<3)+(C&15),C=gc();
	if(F)X=-X;
}
template<class T>inline void Prt(T X){
	if(X<0)putchar('-'),X=-X;
	if(X>9)Prt(X/10);
	putchar(X%10+'0');
}

using namespace std;
typedef long long ll;

const int N=1e5+5;
int n,A[N];
ll Ans;
ll k,rem;

int main(){
	Readin(n),Readin(k);
	rep(i,1,n)Readin(A[i]);
	sort(A+1,A+1+n);
	rem=k;
	Ans=A[n]-A[1];
	int L=1,R=n;
	while(L<R){
		if(L<n-R+1){
			if(1ll*(A[L+1]-A[L])*L>rem)return not printf("%I64d",Ans-(rem/(ll)L));
			else rem-=1ll*(A[L+1]-A[L])*L;
			++L;
		}
		else{
			if(1ll*(A[R]-A[R-1])*(n-R+1)>rem)return not printf("%I64d",Ans-(rem/(ll)(n-R+1)));
			else rem-=1ll*(A[R]-A[R-1])*(n-R+1);
			--R;
		}
		Ans=A[R]-A[L];
	}
	return not printf("%I64d",Ans);
}