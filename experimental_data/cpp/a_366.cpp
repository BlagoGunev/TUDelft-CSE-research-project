using namespace std;

#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

#define FORR(i,a,b) for(int i=a;i<=b;i++)

#define MOD 1000000007

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define INF 2lli * (1e18)

typedef long long int lli;

typedef vector<int> vi; 

typedef vector<vi> vvi; 

typedef pair<int,int> ii;

typedef map<int, int>::iterator it_type;

 int main(){



 	int m;

 	cin>>m;



 	vector<int> p;

 	int a,b,c,d;

 	FOR(i,4){

 		cin>>a>>b>>c>>d;

 		if(a>b)

 			swap(a,b);

 			if(c>d)

 			swap(c,d);

 		if(a+c<=m)

 		{

 			cout<<i+1<<" "<<a<<" "<<m-a;

 			return 0;

 		}

 	}

 	cout<<-1;

 	return 0;}