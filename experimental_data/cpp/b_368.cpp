#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define type long long

using namespace std;


bool set[1000000];
int tab[1000000];
int res[1000000];

int main()
{

  cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int n, m;

  cin>>n>>m;

  for(int i=0; i<n;i++)
  	cin>>tab[i];

  res[n-1] = 1;
  set[tab[n-1]] = 1;

  for(int i=n-2; i>=0 ;i--)
  {
  	if(!set[tab[i]])
  	{
  		set[tab[i]] = 1;
  		res[i] = 1 + res[i+1];
  	}
  	else
  		res[i] = res[i+1];

  }

  for(int i=0; i<m; i++)
  {
  	int t;
  	cin>>t;
  	cout<<res[t-1]<<"\n";
  }

  return 0;
 
}