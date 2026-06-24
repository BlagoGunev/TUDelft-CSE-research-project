#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iostream>


using namespace std;


long long k;
long long n;
int in[100100];
int main(){
	cin >> n >> k;
	in[0] = -1; in[n+1] = -1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
	}
	--k;
	sort(in+1, in+n+1);
	int num = k/n + 1;
	int rep = 1;
	for(int i = num-1; in[i] == in[num]; --i) ++rep;
	int x = rep-1;
	for(int i = num+1; in[i] == in[num]; ++i) ++rep;

	int rest = (k%n + n*x)/rep;
	printf("%d %d\n", in[num], in[rest+1]);
	
	return 0;
}