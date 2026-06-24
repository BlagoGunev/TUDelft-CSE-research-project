#pragma GCC optimize("O3")
//#pragma GCC target("avx")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <iomanip>
#include <list>
using namespace std;
#define re return
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define fi first
#define se second
#define ss second.second
#define sf second.first
#define ff first.first
#define fs first.second
#define sqrt(x) sqrt(abs(x))
#define mp make_pair
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define er erase
#define in insert
#define fo(i,n) for((i)=0;(i)<(n);(i)++)
#define ro(i,n) for((i)=n-1;(i)>=0;(i)--)
#define fr(i,j,n) for((i)=(j);(i)<(n);(i)++)
#define rf(i,j,n) for((i)=((n)-1);(i)>=(j);(i)--)
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
void eras(map<int,int> &m,int x)
{
    m[x]--;
    if (!m[x]) m.erase(x);
}
const int N=(int)3e5+100;
const int M=(int)1e7+10;
const int inf=(int)1e8;
const double eps=1e-9;
#define filename ""
    bool was[26][26];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen(filename".in","r",stdin);
    //freopen(filename".out","w",stdout);
    //freopen("ans.txt","w",stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k,i,j;
    cin>>n>>k;
    string s="";
    if (k==1)
    {
        s="a";
    }
    else
    {
        fo(i,k)
        {
            s+=(char)(i+'a');
            s+=(char)(i+'a');
        }
        ro(i,k-1)
        {
            s+=(char)(i+'a');
            fr(j,i+2,k)
            {
                s+=(char)(j+'a');
                s+=(char)(i+'a');
            }
        }
        s=s.substr(0,s.length()-1);
    }
    while(n)
    {
        if (n>=s.length())
        {
            cout<<s;
            n-=s.length();
        }
        else
        {
            cout<<s.substr(0,n);
            n=0;
        }
    }
}