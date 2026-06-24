#include<iostream>

#include<string>

#include<cmath>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<set>

#include<cstdlib>

#include<list>

#include<iomanip>

#include<map>

#include<queue>

#include<deque>

#define endl "\n"

using namespace std;



int main(){



int N = 0, cnt = 0;

scanf("%i",&N);

while(N--){

	int l = 0, r = 0;

	scanf("%i%i",&l,&r);

	if(l+2 <= r) cnt++;

}

cout << cnt;

return 0;

}