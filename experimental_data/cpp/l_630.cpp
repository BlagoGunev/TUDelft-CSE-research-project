#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <algorithm>

// #pragma warning ( disable : 4996 ) 

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;


int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	int d4 = N / 10000;
	int d3 = (N / 1000) % 10;
	int d2 = (N / 100) % 10;
	int d1 = (N / 10) % 10;
	int d0 = N % 10;
	long long K = (((10*d4+d2)*10+d0)*10+d1)*10+d3;
	cerr << K << endl;
	long long K2 = (K*K) % 100000;
	long long K4 = (K2*K2) % 100000;
	long long res = (K4*K) % 100000;
	printf("%05d\n", (int)res);
 	return 0;
}