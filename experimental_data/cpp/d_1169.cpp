/*
[WHEN YOU CAN'T REACH THE DESTINATION CHANGE THE DESTINATION]
*/
#include <set>          
#include <map>           
#include <list>
#include <ctime>
#include <deque>   
#include <queue>      
#include <bitset>        
#include <vector>
#include <list>
#include <stack>
#include <random>         
#include <string>       
#include <numeric>      
#include <utility>     
#include <iterator> 
#include <fstream>
#include <iostream> 
#include <iomanip>  
#include <algorithm> 
#include <functional>  
#include <unordered_map>  
#include <unordered_set>
#include <cmath>   
#include <cstring>  
#include <cstdio>    
#if !defined Header_DR
#define Header_DR
#pragma warning(disable:4996)
#define intt long long
#define cin user_input
#define cout output
#define PI 3.14159265358979323846l
#define code_jam 0
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define all(v) v.begin(),v.end() 
#define ve vector
#define pb push_back                    
#define srt(x) sort(x.begin(),x.end())         
#define mod static_cast<long long> ( 998244353)     
#define sumx(x) accumulate(x.begin(),x.end(),0LL)
#define endl "\n"
#endif
#ifdef _WIN32
#define getcx _getchar_nolock
#endif
#ifdef __unix__
#define getcx getchar_unlocked
#endif
#ifdef __APPLE__
#define getcx getchar_unlocked
#endif
#if!defined FAST_IO
#undef cin
#undef cout
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define cin user_input
#define cout output
#endif
using namespace std;
namespace Xrocks {}
using namespace Xrocks;
namespace Xrocks
{
	class in {}user_input;
	class out {}output;
	in& operator >> (in& X, int &Y)
	{
		scanf("%d", &Y);
		return X;
	}
	in& operator >> (in& X, char *Y)
	{
		scanf("%s", Y);
		return X;
	}
	in& operator >> (in& X, float &Y)
	{
		scanf("%f", &Y);
		return X;
	}
	in& operator >> (in& X, double &Y)
	{
		scanf("%lf", &Y);
		return X;
	}
	in& operator >> (in& X, char &C)
	{
		scanf("%c", &C);
		return X;
	}
	in& operator >> (in& X, string &Y)
	{
#undef cin
		cin >> Y;
#define cin user_input
		return X;
	}
	in& operator >> (in& X, long long &Y)
	{
		scanf("%lld", &Y);
		return X;
	}
	template<typename T>
	in& operator >> (in& X, vector<T> &Y)
	{
		for (auto &x : Y)
			cin >> x;
		return X;
	}

	template<typename T>
	out& operator << (out& X, const  T &Y)
	{
#undef cout
		cout << Y;
#define cout output
		return X;
	}
	template<typename T>
	out& operator << (out& X, vector<T> &Y)
	{
		for (auto &x : Y)
			cout << x << " ";
		return X;
	}
	out& operator <<(out& X, const int &Y)
	{
		printf("%d", Y);
		return X;
	}
	out& operator <<(out& X, const char &C)
	{
		printf("%c", C);
		return X;
	}
	out& operator <<(out& X, const string &Y)
	{
		printf("%s", Y.c_str());
		return X;
	}
	out& operator <<(out& X, const long long &Y)
	{
		printf("%lld", Y);
		return X;
	}
	out& operator <<(out& X, const float &Y)
	{
		printf("%f", Y);
		return X;
	}
	out& operator <<(out& X, const double &Y)
	{
		printf("%lf", Y);
		return X;
	}
	out& operator <<(out& X, const char Y[])
	{
		printf("%s", Y);
		return X;
	}
	template<typename T>
	T max(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T max(T A, T B, args... S)
	{
		return max(A > B ? A : B, S...);
	}
	template<typename T>
	T min(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T min(T A, T B, args... S)
	{
		return min(A < B ? A : B, S...);
	}
	template<typename T>
	void vectorize(int y, ve<T> &A)
	{
		A.resize(y);
	}
	template<typename T, typename... args>
	void vectorize(int y, ve<T> &A, args&&... S)
	{
		A.resize(y);
		vectorize(y, S...);
	}
	long long fast(long long a, long long b, long long pr = mod)
	{
		if (b == 0)
			return 1 % pr;
		long long ans = 1 % pr;
		while (b)
		{
			if (b & 1)
				ans = (ans * a) % pr;
			b >>= 1;
			a = (a * a) % pr;
		}
		return ans;
	}
	int readInt()
	{
		int n = 0;
		//    scanf("%d", &n);
		//    return n;
		int ch = getcx();
		int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long readLong()
	{
		long long n = 0;
		//scanf("%lld",&n);
		//return n;
		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long readBin()
	{
		long long n = 0;
		//scanf("%lld",&n);
		//return n;
		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '1') { if (ch == '-')sign = -1; ch = getcx(); }

		while (ch >= '0' && ch <= '1')
			n = (n << 1) + (ch - '0'), ch = getcx();
		return n;
	}
	long long inv_(long long val, long long pr = mod)
	{
		return fast(val, pr - 2, pr);
	}
}
// x,y
pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b)
{
	return { (a.first + b.first),(a.second + b.second) };
}
#define maxn 500000
char S[maxn];
set<int> s[10];
class solve
{
	
public:
	solve()
	{
		for(int i=1;i<10;i++)
		{
			int f=0;
			for(int j=0;j<(1<<i);j++)
			{
				ve<int> w(i);
				for(int k=0;k<i;k++)
				{
					w[k]=(j>>k)&1;
				}
				if(check(w))
					s[i].insert(j);
			}
		}
		scanf("%s",S);
		int n=strlen(S);
		long long ans=0;
		for(int i=2;i<n;i++)
		{
			int CV=0;
			for(int j=0;j<9 && j<=i;j++)
			{
				if(S[i-j]=='1')
					CV|=(1<<j);
				if(s[j+1].find(CV)!=s[j+1].end())
				{
					ans+=i-j+1;
					break;
				}
			}
			
		}
		cout << ans;
	}
	bool check(ve<int> &v)
	{
		for(int i=1;i<=v.size();i++)
		{
			for(int j=i;j+i<v.size();j++)
			{
				if(v[j]==v[j-i] && v[j]==v[j+i])
					return true;
			}
		}
		return false;
	}
	
};

int32_t main()
{
	int t = 1, i = 1;
	//freopen("C:\\Users\\cleaner\\Downloads\\input.in","r",stdin);
	//freopen("C:\\Users\\cleaner\\Downloads\\output.txt","w",stdout);
	if (code_jam)
		scanf("%d", &t);
	while (t--)
	{
		if (code_jam)
			printf("Case #%d: ", i++);
		new solve;
	}
#ifdef __unix__
	cout << "\n";
#endif
	return 0;
}