/*
ID: barish21
LANG: C++14
TASK: test
*/

/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

/***TEMPLATE***/
#define intt long long

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(s) (intt)s.size()

#define ms0(arr) memset(arr,0,sizeof arr)
#define ms63(arr) memset(arr,63,sizeof arr)

#define forn(i,a,b) for(intt i=a;i<=b;i++)
#define rofn(i,a,b) for(intt i=a;i>=b;i--)
#define setf(it,myset) for(set<intt>::iterator it=myset.begin();it!=myset.end();it++)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define VI vector<intt>
#define PII pair<intt,intt>
#define VPII vector< PII >

#define posl(ch) (int)(ch-'a'+1)
#define posL(ch) (int)(ch-'A'+1)

#define IO ios_base::sync_with_stdio(false);cin.tie();
/***************/

/***Additional Functions***/
intt powmod(intt a,intt b,intt mod){intt res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
intt gcd(intt a,intt b){if(!b)return a;return (b,a%b);}
intt lcm(intt a,intt b){return a*b/gcd(a,b);}
intt is_prime(intt n){if(n==1)return 0;if(n==2)return 1;forn(i,2,sqrt(n))if(n%i==0)return 0;return 1;}
intt is_integer(double n){if(floor(n)==ceil(n))return 1;return 0;}

intt sto_int(string s){stringstream ss(s);intt n;ss>>n;return n;}
string to_string(intt n){stringstream ss;ss<<n;string s=ss.str();return s;}

/**************************/

vector < string > v1, v2;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    IO;
    intt n;
    cin >> n;
    forn (i, 1, n)  {
        string s1, s2;
        cin >> s1 >> s2;
        string tmp1 = "", tmp2 = "";
        tmp1 += s1[0], tmp1 += s1[1], tmp1 += s1[2];
        tmp2 += s1[0], tmp2 += s1[1], tmp2 += s2[0];
        v1.pb(tmp1);
        v2.pb(tmp2);
    }
    intt f1 = 1, f2 = 1;
    forn (i, 0, v1.size() - 1)
        forn (j, i + 1, v1.size() - 1)
            if (v1[i] == v1[j]) {
                f1 = 0;break;
            }
    forn (i, 0, v2.size() - 1)
        forn (j, i + 1, v2.size() - 1)
            if (v2[i] == v2[j]) {
                f2 = 0;break;
            }
    if (f1) {
        cout << "YES" << endl;
        forn (i, 0, v1.size() - 1)
            cout << v1[i] << endl;
        return 0;
    }
    if (f2) {
        cout << "YES" << endl;
        forn (i, 0, v2.size() - 1)
            cout << v2[i] << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}