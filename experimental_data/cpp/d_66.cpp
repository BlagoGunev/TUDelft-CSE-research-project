#include <bits/stdc++.h>
#include<stdio.h>

#include<string.h>

#include<iostream>

#include<sstream>

#include<algorithm>

#include<set>

#include<map>

#include<deque>

#include<queue>

#include<vector>

#include<list>

#include<tr1/unordered_map>

#include<functional>

using namespace std;



inline void print(char pt) {

	printf("%c\n", pt);

}

inline void print(int pt) {

	printf("%d\n", pt);

}

inline void print(long long pt) {

	printf("%lld\n", pt);

}

inline void print(double pt) {

	printf("%.20f\n", pt);

}

inline void print(char pt[]) {

	printf("%s\n", pt);

}

inline void print() {

	printf("\n");

}



inline int scan(int &pt) {

	return scanf("%d", &pt);

}

inline int scan(char &pt) {

	return scanf("%c", &pt);

}

inline int scan(long long &pt) {

	return scanf("%lld", &pt);

}

inline int scan(double &pt) {

	return scanf("%lf", &pt);

}

inline int scan(char pt[]) {

	return scanf("%s", pt);

}



const long long moda = 421412341324321ll;

using namespace std;

int n;



int main() {

	scan(n);

	if (n == 2) {

		print(-1);

		return 0;

	}

	print(2 * 3);

	print(3 * 5);

	print(5 * 2);

	n -= 3;

	long long ansa = 5 * 2;

	while (n--) {

		ansa <<= 1;

		print(ansa);

	}



	return 0;

}