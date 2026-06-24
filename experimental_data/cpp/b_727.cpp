#include <iostream>

#include <stdio.h>

#include <cstdio>

#include <algorithm>

#include <math.h>

#include <map>

#include <string>

#include <deque>

#include <vector>

#include <iomanip>



using namespace std;

string s;

int y = 0;

int find(int x){

	int k = x;

	while (k < s.size() && (s[k] < '0' || s[k] > '9'))

		k++;

	char a[1010];

	int i = 0;

	while(k < s.size() &&((s[k] == '.')|| (s[k] <='9' && s[k] >= '0'))){

		a[i] = s[k];

		k++;

		i++;

		}

	double n = 0;

	for(int j = 0; j < i; j++){

		if(a[j]!= '.')

			n = 10*n + a[j] - '0';

		}

	y = k;

	if(a[0] == '0' && a[1] == '.' && a[2] == '0')

		return n;

	if(a[i - 3] != '.')

		return n*100;

	else return n;

	}





int b[1000];

int main(){

#pragma warning(disable : 4996)

#ifdef _DEBUG

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif

	cin >> s;

	long long int m  = 0;

	while(y < s.size()){

		int t = find(y);

		m+= t;

		}

	if(m < 10){

		cout << 0 << '.' << 0 << m;

		return 0;

		}

	if(m < 100){

		cout << 0 << '.' << m;

		return 0;

		}

	long long int mm = m;

	m = m/100;

	int m1 = m;

	int i = 0;

	vector <int> ans;

	while(m1 > 0){

		b[i] = m1%10;

		m1 = m1/10;

		i++;

		}

	for(int j = 0; j < i/2; j++)

		swap(b[j], b[i - 1 - j]);

	if(i %3 == 2){

		ans.push_back(b[0]);

		ans.push_back(b[1]);

		ans.push_back(-1);

		}

	if(i %3 == 1){

		ans.push_back(b[0]);

		ans.push_back(-1);

		}

	for(int j = i%3; j < i;j+=3){

		ans.push_back(b[j]);

		ans.push_back(b[j+1]);

		ans.push_back(b[j+2]);

		ans.push_back(-1);

		}

	for(int i = 0; i < ans.size() - 1; i++){

		if(ans[i] == -1)

			cout << '.';

		else 

			cout << ans[i];

		}



	if(mm %100 != 0){

		cout << '.' << (mm%100)/10 << mm%10;

		}

	return 0;

		}