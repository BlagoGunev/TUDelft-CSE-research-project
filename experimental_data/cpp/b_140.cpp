#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>

#define EPS 1e-7
#define PI 3.1415926535897932384626433832795


using namespace std;

bool islet(char ch){
    return ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z');
}

long long mulmod(long long a, long long b, long long MOD){
        if (b == 0) return 0;
        long long res = mulmod(a, b >> 1, MOD);
        res += res;
        res %= MOD;
        return (b & 1)? (a + res) % MOD : res;
}

long long nod(long long a, long long b){
    while (a!=0 && b!=0){
		if (a>b){
			a%=b;
		}
		else{
			b%=a;
		}
	}
	return a+b;
}


int main(){
    ios::sync_with_stdio(0);
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    //cout.setf(ios::fixed); cout.precision();
	//time_t startTime = time (NULL);

	//begin code
	int n;
	cin>>n;
	int a[313][313],b[313];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (a[i][j]!=i+1){
				bool pp=0;
				for (int k=0;k<n;k++){
					if (a[i][j]>b[k] && i+1!=b[k]){
						pp=1;
						break;
					}
					if (a[i][j]==b[k]) break;
				}
				if (!pp){
					cout<<a[i][j]<<' ';
					break;
				}
			}
		}
	}
	//end code

	//cout<<"\nSuccessful completed in "<<time (NULL)-startTime<<" second(s).\n";
    return 0;
}