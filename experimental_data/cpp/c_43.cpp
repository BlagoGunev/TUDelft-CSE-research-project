#include<bits/stdc++.h>

using namespace std;

double PI = 3.1415926535897932384626433832795;

#define MOD	1000000007

int main() {

	//freopen("true","r",stdin);

	//freopen("output.txt","w",stdout);

	int n , ans = 0 , one = 0 , two = 0;

	scanf("%d",&n);

	for (int i=0 ; i < n ; ++i){

		int x , ans1=0;

		scanf("%d",&x);

		while(x){

			ans1+= x%10;

			x/=10;

		}

		if (ans1%3 == 0)ans++;

		else if(ans1%3 == 1)one++;

		else two++;

	}

	printf("%d",ans/2+min(one,two));

	return 0;

}