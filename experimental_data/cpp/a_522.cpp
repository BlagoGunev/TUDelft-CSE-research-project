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





const i32 MAX = 200 + 5;



ch str[30];

map<string, i32> comp;

vi tree[MAX << 1];

bit vis[MAX << 1];

i32 dis[MAX << 1];

i32 id;



void dfs(i32 u)

{

	vis[u] = 1;

	ITERATE(tree[u], itr)

	{

		i32 v = *itr;

		if(!vis[v])

		{

			dis[v] = dis[u] + 1;

			dfs(v);

		}

	}

}



i32 main()

{

	i32 n;

	scanf("%d", &n);



	i32 u, v;

	FOR(i, n)

	{

		scanf("%s", str);

		i32 len = strlen(str);

		FOR(i, len)

			if('A' <= str[i] && str[i] <= 'Z')

				str[i] = 'a' + str[i] - 'A';



		string s = string(str);

		if(!comp[s]) comp[s] = ++id;

		u = comp[s];

	

		scanf("%s", str);

		scanf("%s", str);



		len = strlen(str);

		FOR(i, len)

			if('A' <= str[i] && str[i] <= 'Z')

				str[i] = 'a' + str[i] - 'A';



		s = string(str);

		if(!comp[s]) comp[s] = ++id;

		v = comp[s];



		tree[v].PB(u);

	}



	dfs(comp["polycarp"]);

	printf("%d\n", 1 + *max_element(dis + 1, dis + 1 + id));



	return 0;

}