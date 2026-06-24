#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n;

struct Point {
	int dic[3], Id_of_The_Array;
	bool operator < (const Point &a) const {
		return dic[0] == a.dic[0] ? (dic[1] == a.dic[1] ? (dic[2] == a.dic[2] ? Id_of_The_Array < a.Id_of_The_Array : dic[2] < a.dic[2]) : dic[1] < a.dic[1]) : dic[0] < a.dic[0];
	}
};

Point mdl_arrr[N], mdl_arrr2[N], mdl_arrr3[N], mdl_arrr4[N];

struct Node {
	int x, y;
	Node (int a = 0, int b = 0) {
		x = a, y = b;
	}

	bool operator < (const Node &a) const {
		return x < a.x;
	}
}mdl2_arrr[N], mdl2_arrr2[N];

vector <Point> Stack, Stack2;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < 3; j ++ ) {
			mdl_arrr[i].dic[j] = rd();
		}
		mdl_arrr[i].Id_of_The_Array = i;
	}
	for (int i = 1; i <= n; i ++ ) {
		mdl_arrr4[i] = mdl_arrr[i];
	}
	sort(mdl_arrr + 1, mdl_arrr + n + 1);

	for (int i = 1; i <= n; i ++ ) {
		if (Stack.empty()) {
			Stack.push_back(mdl_arrr[i]);
		}
		else {
			if (Stack.back().dic[0] == mdl_arrr[i].dic[0] && Stack.back().dic[1] == mdl_arrr[i].dic[1]) {
				printf("%d %d\n", mdl_arrr[i].Id_of_The_Array, Stack.back().Id_of_The_Array);
				Stack.pop_back();
			}
			else {
				Stack.push_back(mdl_arrr[i]);
			}
		}
	}

	int LLLen = Stack.size();
	for (int i = 0; i<LLLen; i ++ ) {
		if (Stack2.empty()) {
			Stack2.push_back(Stack[i]);
		}
		else {
			if (Stack2.back().dic[0] == Stack[i].dic[0]) {
				printf("%d %d\n", Stack[i].Id_of_The_Array, Stack2.back().Id_of_The_Array);
				Stack2.pop_back();
			}
			else {
				Stack2.push_back(Stack[i]);
			}
		}
	}
	int mdllen = Stack2.size();
	for (int i = 0; i < mdllen; i += 2) {
		printf("%d %d\n", Stack2[i].Id_of_The_Array, Stack2[i + 1].Id_of_The_Array);
	}
	return 0;
}