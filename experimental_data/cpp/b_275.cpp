#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

#define PB push_back
#define MOD 1000000007
#define MP make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int main()
{
	int n,m;
	cin >> n >> m;
	int i,j,k,l;
	int flag = 0;
	char arr[n][m];
	for(i=0;i<n;i++){
		int tmp=0;
		for(j=0;j<m;j++){
			cin >> arr[i][j];
			if(tmp==0 && arr[i][j]=='B')
				tmp=1;
			if(tmp==1 && arr[i][j]=='W')
				tmp=2;
			if(tmp==2 && arr[i][j]=='B')
				flag=1;
		}
	}
	for(i=0;i<m;i++){
		int tmp=0;
		for(j=0;j<n;j++){
			if(tmp==0 && arr[j][i]=='B')
				tmp=1;
			if(tmp==1 && arr[j][i]=='W')
				tmp=2;
			if(tmp==2 && arr[j][i]=='B')
				flag=1;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(arr[i][j]=='W')
				continue;
			for(k=0;k<n;k++){
				for(l=0;l<m;l++){
					if(arr[k][l]=='W')
						continue;
					if(arr[i][l]!='B' && arr[k][j]!='B')
						flag=1;
				}
			}
		}
	}
	if(flag==1)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}