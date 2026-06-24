#include <bits/stdc++.h>

using namespace std;

long long int arr[1005][3];
long long int dep[1005];

int main(void){
	long long int n,i,j,k,ans;
	scanf("%lli",&n);
	for(i = 0; i < n; i++){
		scanf("%lli %lli %lli",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n ; j++){
			if(arr[j][2] < arr[i][2]){
				if((arr[j][0] - arr[i][0])*(arr[j][0] - arr[i][0]) + (arr[j][1] - arr[i][1])*(arr[j][1] - arr[i][1]) <= arr[i][2]*arr[i][2]){
					dep[j]++;
				}
			}
		}
	}
	ans = 0;
	for(i = 0; i < n; i++){
		if(dep[i] == 0 || (dep[i] % 2 ) == 1){
			ans += arr[i][2]*arr[i][2];
		}
		else{
			ans -= arr[i][2]*arr[i][2];
		}
	}
	double ans1 = ans*(3.14159265358979323846264338327950);
	cout<<setprecision(42)<<fixed<<ans1;
}