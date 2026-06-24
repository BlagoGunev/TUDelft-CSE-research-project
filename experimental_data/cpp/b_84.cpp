#include <bits/stdc++.h>
/*---------------------------
Author		: Md. Atiqul Islam (deadlineruhe)
University 	: AIUB
E-mail  	: deadlineruhe@gmail.com
Problem Name:
Algorithm  	:
Complexity  :
Difficulty  :
-----------------------------*/
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;
//Constant Declaration

const int SIZ=1000000;
const int INF=(1<<29);
const double EPS = 1e-11;
const double PI = acos(-1.0);
/*--------------------------*/
// some essential funtion
/*----------------------------------*/
void SWAP(int &a,int &b){	int t=a;a=b;b=t;}
int MAX(int a,int b){	return a>b?a:b;  }
int MIN(int a,int b){	return a<b?a:b;  }
int GCD(int a,int b){	while(b){b ^= a ^=b ^= a %=b;}	return a;}
/*----------------------------------*/
typedef int64_t li;
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	map<int,int>M;
	set<int>S;
	int n,i,total,a,prev;
	li res;
	while(scanf("%d",&n) == 1){
		res = n;
		scanf("%d",&a);
		prev = a;
		for(i = 1,total = 1; i < n; i++){
			scanf("%d",&a);
			if(prev == a){
				total++;
			}else {
				//printf("%d %d\n",a,total);
				prev = a;
				res += (total * (li)(total - 1)) / 2;
				total = 1;
			}
		}
		res += (total * (li)(total - 1)) / 2;
		printf("%lld\n",res);
	}
	return 0;
}