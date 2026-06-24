#include <bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
*/

using namespace std;

#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> iil;
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define ff first
#define ss second
#define trav(a, x) for(auto& a : x) 
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
const ll INF = 1e18;
const int mod = 1e9 + 7;
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

//*X.find_by_order(2) element at index=2
//X.order_of_key(1) how many elements strictly less than 1

//#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_NOde_update> 

inline int pow_(ll x, ll y,ll p){
  int r = 1; while(y){if(y & 1) r = r * x % p; y >>= 1; x = x * x % p;} return r;
}
inline int inv_(int x){return pow_(x, mod - 2, mod);}
inline int add(int a, int b){a += b; if(a >= mod) a -= mod; return a;}
inline int mul(int a, int b){return a * 1LL * b % mod;}
inline int sub(int a, int b){a -= b; if(a < 0) a += mod; return a;}

string s;

string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

int compare(string s1,string s2)
{
	if(s1.size()>s2.size())return 1;
	else if(s2.size()>s1.size())return 0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>s2[i])
		{
			return 1;
		}
		else if(s2[i]>s1[i])
		{
			return 0;
		}
	}

	return 0;
}

string find(int l)
{
	string s1,s2;
	string ans;
	if(s[l/2]!= '0')
	{
		s1 = s.substr(l/2,l-l/2);
		s2 = s.substr(0,l/2);
		//cout << s1 << " " << s2 << "\n";
		ans = findSum(s1,s2);
	}
	else
	{
		int j = l/2;
		while(s[j] == '0')
		{
			j++;
		}
		s1 = s.substr(j,l-j);
		s2 = s.substr(0,j);
		string sum1 = findSum(s1,s2);
		j = l/2;
		while(s[j] == '0')
		{
			j--;
		}
		s1 = s.substr(j,l-j);
		s2 = s.substr(0,j);

		string sum2 = findSum(s1,s2);

		if(compare(sum1,sum2))ans = sum2;
		else ans = sum1;
	}

	return ans;
}

string find1(int l)
{
	string s1,s2;
	string ans;
	if(s[l/2 + 1]!= '0')
	{
		s1 = s.substr(l/2+1,l - (l/2+1));
		s2 = s.substr(0,l/2+1);
		//cout << s1 << " " << s2 << "\n";
		ans = findSum(s1,s2);
	}
	else
	{
		int j = l/2+1;
		while(s[j] == '0')
		{
			j++;
		}
		s1 = s.substr(j,l-j);
		s2 = s.substr(0,j);
		string sum1 = findSum(s1,s2);
		j = l/2+1;
		while(s[j] == '0')
		{
			j--;
		}
		s1 = s.substr(j,l-j);
		s2 = s.substr(0,j);

		string sum2 = findSum(s1,s2);

		if(compare(sum1,sum2))ans = sum2;
		else ans = sum1;
	}

	return ans;
}

int main()
{
	#ifdef LOCAL_TEST
	freopen("in.txt","r",stdin);
	//freopen("out.txt", "w", stdout);
	#else
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#endif
	ll l;
	cin>>l;
	cin>>s;
	if(l%2 == 0)
	{
		string ans = find(l);
		cout << ans << "\n";	
	}
	else
	{
		string s1 = find(l);
		string s2 = find1(l);
		string ans;
		if(compare(s1,s2))ans = s2;
		else ans = s1;
		cout << ans << "\n";
	}
	return 0;
}