#include <bits/stdc++.h>



using namespace std;



typedef signed char 		i8;

typedef unsigned char 		i8u;

typedef signed short 		i16;

typedef unsigned short 		i16u;

typedef signed int 			i32;

typedef unsigned int 		i32u;

typedef signed long long 	i64;

typedef unsigned long long 	i64u;



typedef char 				ch;

typedef bool 				bit;



typedef float 				f32;

typedef double 				f64;



typedef pair<i32, i32> 		pii;

typedef vector<i32>			vi;

typedef vector<pii> 		vp;

typedef vector<vi>			vii;











#define DEBUG(n) 		cerr << '>' << #n << ": "<< n <<endl

#define CLEAR(v) 		memset(v, 0, sizeof(v))

#define NEGATE(v) 		memset(v, -1, sizeof(v))

#define FOR(i, n) 		for(i32 i = 0; i < (n); ++i)

#define FORR(i, a, b) 	for(i32 i = (a); i <= (b); ++i)

#define RFOR(i, n) 		for(i32 i = (n - 1); i >= 0; --i)

#define RFORR(i, a, b) 	for(i32 i = (b); i >= (a); --i)

#define ALL(c)			(c).begin(), (c).end()

#define SZ(c)			(i32)((c).size())

#define PB				push_back

#define X 				first

#define Y 				second

#define ITERATE(c, i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define TIME_START 		clock_t start_time = clock()

#define TIME_END 		cerr << "Time elapsed: " << f64(clock() - start_time) / CLOCKS_PER_SEC * 1000 <<" ms"<<endl







const i32 MAX = 25;

i32 N;

i32 M;



ch s1[MAX];

ch s2[MAX];

i32 cc;

bit vis[MAX][MAX];

stack<pii> s;



i32 dr[4] = {-1, 0, 1, 0};

i32 dc[4] = {0, 1, 0, -1};



inline bit inside(i32 x, i32 y)

{

	return 0 <= x && x < N && 0 <= y && y < M;

}



void dfs(i32 x, i32 y)

{

	vis[x][y] = 1;

	FOR(i, 4)

	{

		i32 newx = x + dr[i];

		i32 newy = y + dc[i];

		if(!inside(newx, newy)) continue;

		if(s1[x] == '>' && i == 1 && !vis[newx][newy])

			dfs(newx, newy);

		if(s1[x] == '<' && i == 3 && !vis[newx][newy])

			dfs(newx, newy);

		if(s2[y] == '^' && i == 0 && !vis[newx][newy])

			dfs(newx, newy);

		if(s2[y] == 'v' && i == 2 && !vis[newx][newy])

			dfs(newx, newy);

	}



	s.push(pii(x, y));

}



void dfs1(i32 x, i32 y)

{

	cc++;

	vis[x][y] = 1;

	FOR(i, 4)

	{

		i32 newx = x + dr[i];

		i32 newy = y + dc[i];

		if(!inside(newx, newy)) continue;

		if(s1[x] == '<' && i == 1 && !vis[newx][newy])

			dfs1(newx, newy);

		if(s1[x] == '>' && i == 3 && !vis[newx][newy])

			dfs1(newx, newy);

		if(s2[y] == 'v' && i == 0 && !vis[newx][newy])

			dfs1(newx, newy);

		if(s2[y] == '^' && i == 2 && !vis[newx][newy])

			dfs1(newx, newy);

	}

}





i32 main()

{

	scanf("%d %d", &N, &M);

	scanf("%s", s1);

	scanf("%s", s2);



	FOR(i, N)

		FOR(j, M)

			if(!vis[i][j])

				dfs(i, j);

	

	CLEAR(vis);

	cc = 0;

	pii a = s.top();

	dfs1(a.X, a.Y);



	if(cc != N * M) printf("NO\n");

	else printf("YES\n");



	return 0;

}