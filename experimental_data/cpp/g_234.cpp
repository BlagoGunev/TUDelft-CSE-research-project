#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sci(fd) scanf("%d",&fd)

#define scll(fd) scanf("%lld",&fd)

#define pb push_back

#define mp make_pair

#define MOD 1000000007

#define PI 3.1415926535897932

#define pii pair < int,int > 

#define fi first

#define se second

#define MAX 100009

const ll infi=1000000000000000009;

int n;

vector <int> v;

int main() {

	freopen("input.txt","r",stdin);

	  freopen("output.txt","w",stdout);

	 int i,n,k;

	 sci(n);

	 int c=0,j=2;

	 for(i=1;i<n;i*=2)

	 c++;

	 printf("%d\n",c);

	 for(i=1;i<n;i*=2)

	 {

	     v.clear();

	     for(j=1;j<=n;j+=2*i)

	     {

	         for(k=j;k<=min(j+i-1,n);k++)

	         v.pb(k);

	     }

	     printf("%d ",(int)v.size());

	     for(j=0;j<v.size();j++)

	     {

	         printf("%d ",v[j]);

	     }

	     printf("\n");

	 }

	return 0;

}