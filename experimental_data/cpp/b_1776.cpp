//zyx模板

#include<bits/stdc++.h>



#define int long long

#define rep(i, a, b) for (int i=a; i<=b; i++)

#define mem(a, b) memset(a, b, sizeof(a))

#define lowbit(x) ((x)&(-x))

#define sq(x) ((x)*(x))

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#define endl "\n"

#define debug(x) cout << #x << " = " << x << endl;

#define debug2(x,y) cout << #x << " = " << x << "   " << #y << " = " << y << endl;

using namespace std;



const int maxn=3e2+5;

//const int maxm=1e3+5;

const int mod=998244353;

const int log2maxn=18+5;		//log2(262144) == 18，精确值

const int INF=2147483647;

const double eps = 1e-8;

int ans, n, m, k;

bool flag;

char ch[maxn];

int ar[maxn];

string s;



inline int qpow(int a,int b,int c){int res=1%c;a%=c;while(b>0){if(b&1)res=res*a%c;a=a*a%c;b>>=1;}return res;}

inline int qpow(int a,int b){int res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}

inline int gcd(int a,int b){return b ? gcd(b , a % b) : a ;}

int cmp_lf(double a, double b)  //浮点数比较，相等返回0，a大返回1，b大返回-1

{

	if (fabs(a - b) < eps) return 0;

	if (a > b) return 1;

	return -1;

}



int h;

int f[maxn][maxn];

int x[maxn];

int g(int l, int r)		//l、r之间可以节约的方块数

{

	return h+1-(x[r]-x[l]+1)/2;

}



inline void solve()

{

	//init

	cin>>n>>h;

	rep(i,1,n) cin>>x[i];



	//cal

	mem(f, 0x3f);

	rep(i,1,n)		f[i][i]=h;

	for (int len=2; len<=n; len++)

	{

		for (int l=1; l+len-1<=n; l++)

		{

			int r=l+len-1;

			// f[l][r] = min(f[l][r], (r-l+1)*h);

			for (int k=l; k<r; k++)

			{

				f[l][r]=min(f[l][r], f[l][k]+f[k+1][r]-g(l, r));

				f[l][r]=min(f[l][r], f[l][k]+f[k+1][r]);

			}

			// debug2(l, r)

			// debug(f[l][r])

		}

	}



	ans = f[1][n];

	cout<<ans<<endl;



	

	return;

}



inline void solve_init()

{

	return;

}



signed main()

{

	#ifndef ONLINE_JUDGE

        freopen("in.txt","r",stdin);

        freopen("out.txt","w",stdout);

        clock_t start, end;

        start = clock();

    #endif



	IOS		//关流，自带分号

	int _ci=1;		//下划线开头的变量表示不重要，只是暂时用用

	// cin>>_ci;

	solve_init();

	while (_ci--)

	{

		solve();

	}



    #ifndef ONLINE_JUDGE

        end = clock();

        cout << endl << "Runtime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";

    #endif

	

	return 0;

}