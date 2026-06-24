// VJ Dot.cpp : �������̨Ӧ�ó������ڵ㡣

//



//#include "stdafx.h"

#include<iostream>

#include<string>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<map>

#include<vector>

using namespace std;

int x, y, n, d;

const int MAXN = 30;

const int MAXX = 1000;

//ori200,200

int xi[MAXN];

int yi[MAXN];

bool dp[MAXX][MAXX];

int dis(int a, int b){

	return (a - 300)*(a - 300) + (b - 300)*(b - 300);

}

bool get(int i, int j){

	if (i == x&&j == y){

		int jjj = 0;

	}

	for (int k = 1; k <= n; ++k){

		if (dp[i + xi[k]][j + yi[k]] == 0){

			return true;

		}

	}

	return false;

}

int main(){

	cin >> x >> y >> n >> d;

	for (int i = 1; i <= n; ++i){

		cin >> xi[i] >> yi[i];

	}

	x += 300;

	y += 300;

	for (int i = 900; i >= 0; --i){

		for (int j = 900; j >= 0; --j){

			if (dis(i, j) > d*d){

				dp[i][j] = 1;//1Ϊ���ֱ�ʤ

			}

			else{

				dp[i][j] = get(i, j);

			}

		}

	}

	if (dp[x][y] == 1)cout << "Anton" << endl;

	else cout << "Dasha" << endl;

	return 0;

}