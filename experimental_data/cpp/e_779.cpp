#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

const int Nmax = 1e3 + 17;
const int Tmax = 5e3 + 17;
const int mod = 1e9 + 7;

set<pair<string, int>> mem;
char name[Nmax];
char value[Nmax];

char var[Tmax][Nmax];
int table[Tmax][3];
bool isConst[Tmax] = {};

bool state[Tmax][2];

int func(int a, int b, int op) {
	if (op == 0) return a ^ b;
	else if (op == 1) return a | b;
	else return a & b;
}

vector <int> qmin;
vector <int> qmax;


int main(void) {
	//freopen("input.txt", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &name);
		mem.insert(make_pair(string(name), i));

		scanf("%s%s", &value, &value);

		if (isdigit(*value)) {
			strcpy(var[i], value);
			isConst[i] = true;
		}
		else {
			if (*value == '?') table[i][0] = -1;
			else table[i][0] = mem.lower_bound(make_pair(string(value), -1))->second;

			scanf("%s", value);
			if (value[0] == 'X') table[i][2] = 0;
			else if (value[0] == 'O') table[i][2] = 1;
			else table[i][2] = 2;

			scanf("%s", value);
			if (*value == '?') table[i][1] = -1;
			else table[i][1] = mem.lower_bound(make_pair(string(value), -1))->second;

		}
	}

	for (int z = m - 1; z >= 0; z--) {
		int countZero = 0;
		int countOne = 0;

		for (int i = 0; i < n; i++) {
			if (isConst[i]) {
				state[i][0] = var[i][z] & 0x01;
				state[i][1] = var[i][z] & 0x01;
			}
			else {
				countZero += state[i][0] = func(table[i][0] == -1 ? 48 : state[table[i][0]][0], table[i][1] == -1 ? 48 : state[table[i][1]][0], table[i][2]) & 0x01;
				countOne += state[i][1] = func(table[i][0] == -1 ? 49 : state[table[i][0]][1], table[i][1] == -1 ? 49 : state[table[i][1]][1], table[i][2]) & 0x01;
			}
		}

		if (countZero != countOne) {
			if (countZero < countOne) {
				qmin.push_back(0);
				qmax.push_back(1);
			}
			else {
				qmin.push_back(1);
				qmax.push_back(0);
			}
		}
		else {
			qmin.push_back(0);
			qmax.push_back(0);
		}
	}

	for (int i = m - 1; i >= 0; i--) printf("%d", qmin[i]);
	printf("\n");
	for (int i = m - 1; i >= 0; i--) printf("%d", qmax[i]);
}