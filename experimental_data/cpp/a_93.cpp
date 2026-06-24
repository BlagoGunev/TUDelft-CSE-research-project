#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

typedef pair<long long,long long> pll;

typedef vector<int> vi;

typedef pair<double,double> pdd;

typedef vector<long long> vll;

typedef vector<pii> vpii;

typedef vector<pll> vpll;

typedef vector<pdd> vpdd;

 

#define f first

#define s second

#define mp make_pair

#define pb push_back

#define MOD 1000000007

#define ll long long

ll GCD(ll a, ll b)

{

    return b? GCD(b,a%b) : a;

}

bool chk(string first, string second)

{

    string t1 = first + second;

    string t2 = second + first;

    return t1 < t2;

}

struct sort_pred

{

    bool operator()(const pair<int,int> &left, const pair<int,int> &right)

    {

        return left.second < right.second;

    }

};

long long POW(long long Base, long long Exp)

{

    long long y,ret=1;

    y=Base;

    while(Exp)

    {

        if(Exp&1)

            ret=(ret*y)%MOD;

        y = (y*y)%MOD;

        Exp/=2;

    }

    return ret%MOD;

}

 

vll A,B,C,D,Res,Mark;

string str,str1,s1,s2;

set<string> st;

stack<ll> chlo;

vpll Rec;

map <string, ll> Reg;

string ItoS(ll n)

{

	ll num = n;

	ll tmp;

	string ans ="";

	while(num)

	{

		tmp = num%10;

		ans = ans + (char)('0'+tmp);

		num/=10;

	}

	reverse(ans.begin(),ans.end());

 

	return ans;

}

int cont(ll n)

{

  	ll count = 0;

  	while(n)

  	{

    	count += n & 1;

    	n >>= 1;

  	}

  	return count;

}

bitset<100*1000+7> Magic;

ll fun(ll n)

{

	ll ret;

	Magic.reset();

	Magic[0]=1;

 

	ll i,Sum=0;

 

	for(i=0; i<n; i++)

	{

		Sum+=A[i];

		Magic = Magic | (Magic<<A[i]);

	}

	ret = 0;

	

	if(Magic[Sum/2])

	{

		while(Magic[Sum/2])

		{

			ret++;

			Sum/=2;

			//cout<<"Sum: "<<Sum<<endl;

			if(Sum==1)

					break;

		}

	}

	return ret;

}

set<ll> At,Bt;

set<ll>::iterator itr;

int main()

{

	ll i,j,n,k,m,x,y,z,tmp1,tmp2,tmp3,ind,Max;

 

	//int t;

	//cin>>t;

	//while(t--)

	{

		cin>>n>>m>>x>>y;

		

		x--;	y--;

		

		tmp1 = x/m;

		tmp2 = y/m;

		tmp3 = y%m;

		z = x%m;

		if(tmp1==tmp2 || (z==0 && tmp3==m-1) || (z==0 && y==n-1))

		{

			cout<<1<<endl;

			return 0;

		}

		

		else if(tmp2==tmp1+1 || tmp3==m-1 || z==0 || y==n-1 || z==tmp3+1)

		{

			cout<<2<<endl;

			return 0;

		}

		cout<<3<<endl;

	}

	return 0;

}