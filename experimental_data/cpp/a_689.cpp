#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;

const int MAXN = 20;

int n;

bool use[MAXN];

char aa[MAXN],bb[MAXN];



int main()

{

	memset(use,0,sizeof(use));

	gets(aa);gets(bb);

	n = aa[0] - '0';

	for(int i = 0; i < n; i ++)

		use[bb[i] - '0'] = true;

	if(use[1] && use[0]) 

	{	puts("YES");return 0; }

	

	if(use[1] && use[9]) 

	{	puts("YES");return 0; }

	

	if(use[2] && use[0]) 

	{	puts("YES");return 0; }

	

	if(use[3] && use[7]) 

	{	puts("YES");return 0; }

	

	if(use[3] && use[0]) 

	{	puts("YES");return 0; }

	

	if(use[1] && use[6] && use[7]) 

	{	puts("YES");return 0; }

	

	if(use[2] && use[7] && use[6])

	{	puts("YES");return 0; }

	

	if(use[2] && use[7] && use[9])

	{	puts("YES");return 0; }

	

	if(use[2] && use[4] && use[9])

	{	puts("YES");return 0; }

	

	if(use[3] && use[4] && use[9])

	{	puts("YES");return 0; }

	

	puts("NO");

	return 0;

}