#include<bits/stdc++.h>
#include<unordered_map>
/*
*▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*    ▀▀       ▀▀▀▀▀▀    ▀     ▀▀▀▀▀▀      ▀    ▀
*   ▀  ▀      ▀         ▀     ▀            ▀  ▀
*  ▀    ▀     ▀ ▀ ▀     ▀     ▀ ▀ ▀         ▀
* ▀ ▀▀▀▀ ▀    ▀         ▀     ▀             ▀
*▀        ▀   ▀         ▀     ▀             ▀
*▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/
using namespace std;
void afify()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define ll long long
#define ld long double
#define mk make_pair
#define loop(i,intial,n)  for(int i=int(intial);i<n;i++)
#define loopn(j,n) for(int j=int(n);j>=0;j--)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(v) v.begin(),v.end()
///////////////////////////////////////
#define SCD(a) scanf("%d",&a)
#define SCD2(a,b) scanf("%d %d",&a,&b)
#define SCLL(a) scanf("%lld",&a)
#define SCLL2(a,b) scanf("%lld %lld",&a,&b)
#define PRD(a) printf("%d\n",a)
#define PRLL(a) printf("%lld\n",a)
///////////////////////////////////////
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<vpii> vvpii;
typedef stringstream ss;
const ll oo = (ll) 10e9+7;
const double EPS = 1e-4;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//ifstream ifs("input.txt");
//ofstream ofs("output.txt");

int main()
{
    afify();   
   string s;
   cin>>s;
   int j=0;
   bool test=0;
   string cmp= "heidi";
   loop(i,0,s.length()){
	   if(s[i]==cmp[j]){
		   j++;
	   }
	   if(j>=5){
		   test=1;
		   break;
	   }
   }
   if(test){
	   cout<<"YES"<<endl;}
   else {
	   cout<<"NO"<<endl;
   }
	return 0; 
}