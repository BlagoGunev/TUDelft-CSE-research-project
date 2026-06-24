/* Author haleyk10198 */

#include <iostream>

#include <fstream>

#include <sstream>

#include <cstdlib>

#include <cstdio>

#include <vector>

#include <map>

#include <queue>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <iomanip>

#include <ctime>

#include <string>

#include <set>



#define MOD 1000000007

#define INF 2147483647

#define PI 3.14159

#define ll long long

#define pii pair<int,int>

#define mp(x,y) make_pair((x),(y))



using namespace std;



string str;

set<string> output;

bool dp[10010][2];



int main(){

	cin>>str;

	dp[str.length()-2][0]=dp[str.length()-3][1]=true;

	for(int pos=str.length()-4;pos>4;pos--){

		dp[pos][0]=dp[pos+2][1]||(dp[pos+2][0]&&str.substr(pos,2).compare(str.substr(pos+2,2))!=0);

		dp[pos][1]=dp[pos+3][0]||(dp[pos+3][1]&&str.substr(pos,3).compare(str.substr(pos+3,3))!=0);

	}

	for(int pos=5;pos<str.length();pos++){

		if(dp[pos][0])

			output.insert(str.substr(pos,2));

		if(dp[pos][1])

			output.insert(str.substr(pos,3));

	}

	printf("%d\n",output.size());

	for(set<string>::iterator it=output.begin();it!=output.end();it++)

		printf("%s\n",it->c_str());

	return 0;

}