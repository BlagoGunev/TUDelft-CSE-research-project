#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <memory.h>

using namespace std;

#define FOR(i,b) for (int i = 0; i < (b); i++)
#define MP(A,B) make_pair(A,B)

int main()
{
	vector<char> sol[4];
	
	int start =0;
	
	int N;
	scanf("%d",&N);

	bool help =true;
	
	while(start+2<=N)
	{
//		cout<<"Start : "<<start<<endl;
		if(help)
		{
			sol[0].push_back('a');
			sol[0].push_back('a');
			
			sol[1].push_back('c');
			sol[1].push_back('c');
		}
		else
		{
			sol[0].push_back('b');
			sol[0].push_back('b');
			
			sol[1].push_back('d');
			sol[1].push_back('d');
		}
		
		start+=2;
		help = !help;
	}
	
	if(N%2!=0)
	{
		sol[0].push_back('f');
		sol[1].push_back('f');
	}
	
	N--;
	
	sol[2].push_back('g');
	sol[3].push_back('g');
	
	help =true;
	
	start =0;
	
	while(start+2<=N)
	{
		if(help)
		{
			sol[2].push_back('k');
			sol[2].push_back('k');
			
			sol[3].push_back('l');
			sol[3].push_back('l');
		}
		else
		{
			sol[2].push_back('m');
			sol[2].push_back('m');
			
			sol[3].push_back('o');
			sol[3].push_back('o');
		}
		
		start+=2;
		help = !help;
	}
	
	if(N%2!=0)
	{
		sol[2].push_back('y');
		sol[3].push_back('y');
	}
	
	// print out
	
	FOR(i,4)
	{
		for(vector<char>::iterator it = sol[i].begin();it!=sol[i].end();it++)
		{
			printf("%c",*it);
		}
		
		printf("\n");
	}
	
	return 0;
}