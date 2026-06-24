#include <iostream>

#include <vector>

#include <set>

#include <map>

#include <iterator>

#include <utility>

#include <algorithm>

#include <cmath>

#include <queue>

#include <stack>

#define pb push_back

#define ll long long

#define fo(k,n) for(int i=(k);i<(n);i++)

#define yes cout<<"YES"<<endl;

#define no cout<<"NO"<<endl

#define read(a) for(int i=0;i<n;i++)cin>>(a)[i];

#define mapa(m,a) for(int i=0;i<n;i++)(m)[(a)[i]];

using namespace std;

const int x[4]={0,1,0,-1};

const int y[4]={1,0,-1,0};

int mat[51][51];

bool vis[51][51];

long long gcd(long long int a, long long int b)

{

  if (b == 0)

    return a;

  return gcd(b, a % b);

}

long long lcm(int a, int b)

{

    return (a / gcd(a, b)) * b;

}

int main(int argc, char *argv[])

{

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t;

    cin>>t;

    while(t--){

    	int n;

    	cin>>n;

    	int q=n*4;

    	vector<int>v;

    	for(int i=0;i<n;i++){

    		v.pb(q);

    		q-=2;

    		}

    	for(auto it:v)cout<<it<<" ";

    	cout<<endl;

    	}

}