#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int ant[70][70];

int main(){
	int n, tt;

	scanf("%d%d",&n,&tt);

	ant[0][0] = n;
	int to;

	to = 0;
	while(1) {
		bool check = false;
		for(int i=0;i<=to;i++){
			for(int j=0;j<=i;j++){
				if(ant[i][j] >=4){
					int temp = ant[i][j] / 4;

					if(i-1 == 0 && j == 0) ant[0][0] += temp * 4;
					else if(i-1 == j) ant[i-1][j] += temp * 2;
					else ant[i-1][j] += temp;

					ant[i+1][j] += temp;

					if(j-1 == 0) ant[i][j-1] += temp * 2;
					else ant[i][j-1] += temp;

					if(i == j+1) ant[i][j+1] += temp * 2;
					else ant[i][j+1] += temp;

					ant[i][j] %= 4;

					if(ant[i+1][j] >= 4) to = max(to, i+1);
					check = true;
				}
			}
		}
		if(!check) break;
	}

	for(int case_=0;case_<tt;case_++){
		int y, x;
		scanf("%d%d",&x,&y);

		if(abs(x) > 65 || abs(y) > 65) 
			cout<<"0\n";
		else
			cout<<ant[max(abs(x),abs(y))][min(abs(x),abs(y))]<<"\n";
	}

	return 0;
}