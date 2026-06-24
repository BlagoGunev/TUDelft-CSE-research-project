#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define itor(c) typeof(c.begin())
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define sp set<pair<int,int> >
#define vp vector<pair<int,int> >
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t,i,j,n;
    cin>>n;
    int arr[100001],dp[100001]={0},c[100001]={0};
    for(i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int sz = 1;
    c[1] = arr[0]; 
    dp[0] = 1;
    for( int i = 1; i < n; i++ ) {
        if( arr[i] < c[1] ) {
        c[1] = arr[i]; 
        dp[i] = 1;
        }
        else if( arr[i] > c[sz] ) {
        c[sz+1] = arr[i];
        dp[i] = sz+1;
        sz++;
        }
        else {
        int k = upper_bound( c, c+sz+1, arr[i] )-c; 
        c[k] = arr[i];
        dp[i] = k;
        }
    }
    cout<<sz;
    return 0;
}