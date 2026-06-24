#include <bits/stdc++.h>

using namespace std;

template <typename T> void read(T &t) {

	t=0; char ch=getchar(); int f=1;

	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }

	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;

}

typedef long long ll;

const int N=10005;

ll h[N]; int L[N],R[N],n;

stack<int> LL,RR; 

int main() {

	read(n);

	for (int i=1; i<=n; i++) read(h[i]); 

	LL.push(0),RR.push(n+1);

	for (int i=1; i<=n; i++) {

		while (LL.size()>1 && h[i]<=h[LL.top()]) LL.pop();

        L[i]=LL.top(),LL.push(i);

    }

    for (int i=n; i>0; i--) {

        while (RR.size()>1 && h[i]<=h[RR.top()]) RR.pop();

        R[i]=RR.top(),RR.push(i);

    }

    L[0]=0,R[n+1]=n+1; ll ans=0;

    

    ll sum=0;

    for (int i=1; i<=n; i++) {

    	int l=i,r=i+1; ll x=0,y=0; 

        while (l>0) x=max(x,h[l]*(i-L[l])),l=L[l];

        while (r<=n) y=max(y,h[r]*(R[r]-i-1)),r=R[r];

        sum=max(sum,x),ans=max(ans,sum+y);

    }

    for (int i=1; i<=n; i++) {

    	int l=L[i],r=R[i],id=i,w=R[i]-L[i]-1;

    	while (1) {

            ans=max(ans,h[id]*(r-l-1)+(h[i]-h[id])*w);

            if (l<=0 && r>n) break;

            if (l<=0) id=r,r=R[r];

            else if (r>n) id=l,l=L[l];

            else if (h[l]>h[r]) id=l,l=L[l];

            else id=r,r=R[r];

        }

    }

    for (int i=1; i<=n; i++) {

        int l=i,r=i; stack<int> s;

        while (l!=0) s.push(l),l=L[l];

        while (1) {

        	while (h[r]+h[s.top()]<=h[i]) s.pop();

        	l=s.top();

        	int len1=R[i]-L[l]-1,len2=R[r]-L[i]-1;

            ans=max(ans,h[l]*len1+(h[i]-h[l])*(r-L[i]-1));

            ans=max(ans,h[L[l]]*(R[i]-L[L[l]]-1)+h[r]*len2);

            ans=max(ans,(h[i]-h[r])*len1+h[r]*len2);

            if (R[r]>n) break; r=R[r];

        }

    }

    cout<<ans<<endl;

    return 0;

}