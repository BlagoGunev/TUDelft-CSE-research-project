#include<bits/stdc++.h>

#define int long long

#define ll long long

#define ld long double

#define R(i,a,b) for(int i=(a),i##E=(b);i<=i##E;i++)

#define L(i,a,b) for(int i=(b),i##E=(a);i>=i##E;i--)

const ld eps=1e-10l;

using namespace std;



struct qua

{

	ld a,b,c,d;

	inline qua(ld A=0,ld B=0,ld C=0,ld D=0):a(A),b(B),c(C),d(D) {}

	inline qua operator + (qua A) 

	{

		return qua(a+A.a,b+A.b,c+A.c,d+A.d);

	}

	inline qua operator - (qua A)

	{

		return qua(a-A.a,b-A.b,c-A.c,d-A.d);

	}

	inline qua operator * (qua A)

	{

		return qua(

			a*A.a-b*A.b-c*A.c-d*A.d,

			a*A.b+b*A.a+c*A.d-d*A.c,

			a*A.c-b*A.d+c*A.a+d*A.b,

			a*A.d+b*A.c-c*A.b+d*A.a

		);

	}

	inline qua conj()//共轭

	{

		return qua(a,-b,-c,-d);

	}

	inline ld norm()//|q|^2

	{

		return a*a+b*b+c*c+d*d;

	}

	inline qua inv()

	{

		return conj()*qua(1.l/norm());

	}

	inline int check_int()

	{

		return fabsl(roundl(a)-a)<eps&&fabsl(roundl(b)-b)<eps&&fabsl(roundl(c)-c)<eps&&fabsl(roundl(d)-d)<eps;

	}

	inline qua qround()

	{

		qua q1=qua(roundl(a),roundl(b),roundl(c),roundl(d));

		qua q2=qua(floorl(a)+.5l,floorl(b)+.5l,floorl(c)+.5l,floorl(d)+.5l);

		return (q1-*this).norm()<(q2-*this).norm()?q1:q2;

	}

	inline qua operator / (qua A)

	{

		return A.inv() * *this;

	}

	inline qua operator % (qua A)

	{

		qua ret=(*this/A).qround();

		return *this-A*ret;

	}

	inline void printf()

	{

		cout<<b<<" "<<c<<" "<<d<<'\n';

	}

	inline void print()

	{

		cout<<llroundl(b)<<" "<<llroundl(c)<<" "<<llroundl(d)<<'\n';

	}

}a[11111],g;

qua gcd(qua a,qua b)

{

	//b.print();

	return b.norm()<eps?a:gcd(b,a%b);

}

ll gcd(ll a,ll b)

{

	return !b?a:gcd(b,a%b);

}



int n;

ll G;

vector<ll>v;

signed main()

{

	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cin>>n;

	R(i,1,n)

	{

		cin>>a[i].b>>a[i].c>>a[i].d;



		g=gcd(g,a[i]);

		G=gcd(G,(ll)a[i].norm());

	}

	for(ll i=1;i*i<=G;i++) if(G%(i*i)==0) v.emplace_back(i);

	reverse(v.begin(),v.end());

	//cout<<G<<endl;

	for(auto x:v)

	{

		//cout<<x<<'\n';

		qua q=gcd(g,qua(x));



		ll r=(ll)q.norm();

		if(r!=x) continue;

		qua q0=q.conj() / qua(r * r);

		// cout<<"qqqqqqqqqq:"<<'\n';

		// q.print();

		// q.printf();

		// q0.print();

		// q0.printf();

		int ok=1;

		R(i,1,n) if((q0*a[i]*q).check_int()==0)

		{

			// (q0*a[i]*q).print();			

			// (q0*a[i]*q).printf();

			ok=0;

			break;

		}

		if(ok)

		{

			cout<<r*r<<'\n';

			(q*qua(0,1)*q.conj()).print();

			(q*qua(0,0,1)*q.conj()).print();

			(q*qua(0,0,0,1)*q.conj()).print();

			return 0;

		} 

	}

}