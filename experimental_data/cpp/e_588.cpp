//pb_ds NOI template 20150710
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <queue>
#define For(i, a, b) for(register int i = a, ___u = b; i <= ___u; ++i)
#define ForDown(i, a, b) for(register int i = b, ___d = a; i >= ___d; --i)
#define cmax(i, j) ((i) < (j) ? (i) = (j) : (i))
#define cmin(i, j) ((i) > (j) ? (i) = (j) : (i))
#define dmax(i, j) ((j) < (i) ? (i) : (j))
#define dmin(i, j) ((i) < (j) ? (i) : (j))
#define ddel(i, j) ((i) > (j) ? (i) - (j) : (j) - (i))
#define dabs(i) ((i) > 0 ? (i) : -(i))
#define dsqr(x) ((x) * (x))
#define lowbit(i) ((i) & -(i))

#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace io
{
	const int MAXBUF = 1 << 22;
	char B[MAXBUF], *S = B, *T = B;
	#define getc() (S == T && (T = (S = B) + fread(B, 1, MAXBUF, stdin), S == T) ? 0 : *S++)
	#define fastcall __attribute__((optimize("-O3")))
	template<class Type> inline Type read()
	{
		register Type aa = 0;
		register bool bb = 0;
		register char ch, *S = io::S, *T = io::T;
		for(ch = getc(); (ch < '0' || ch > '9') && ch != '-'; ch = getc())
			;
		for(ch == '-' ? bb = 1 : aa = ch - '0', ch = getc(); '0' <= ch && ch <= '9'; ch = getc())
			aa += (aa << 3) + aa + ch - '0';
		io::S = S, io::T = T;
		return bb ? -aa : aa; 
	}
	int (*F)() = read<int>;
	
	template<> inline double read()
	{
		register double aa = 0, bb;
		register bool cc = 0;
		register char ch;
		register char *S = io::S, *T = io::T;
		for(ch = getc(); (ch < '0' || ch > '9') && ch != '-'; ch = getc())
			;
		for(ch == '-' ? cc = 1 : aa = ch - '0', ch = getc(); '0' <= ch && ch <= '9'; ch = getc())
			aa = aa * 10 + ch - '0';
		if(ch == '.')
		{
			bb = 1;
			while(ch = getc(), ch >= '0' && ch <= '9')
				aa += (bb *= 0.1) * (ch - '0');
		}
		io::S = S, io::T = T;
		return cc ? -aa : aa;
	}
	
	char buff[MAXBUF], *iter = buff;
	template<class T>inline void P(register T x, register char ch = '\n')
	{
///*lgg*/return void (std::cout << x << ch);
		static int stack[110];
		register int O = 0;
		register char *iter = io::iter;
		if(!x)*iter++ = '0';
		else
		{
			(x < 0) ? x = -x, *iter++ = '-' : 1;
			for(; x; x /= 10)
				stack[++O] = x % 10;
			for(; O; *iter++ = '0' + stack[O--])
				;
		}
		*iter++ = ch, io::iter = iter;
	}

	inline int gets_A(register char *o)
	{
		register char *s = o, ch = getc();
		register char *S = io::S, *T = io::T;
		for(; ch < 'A' || 'Z' < ch; ch = getc())
			;
		for(; 'A' <= ch && ch <= 'Z'; ch = getc())
			*s++ = ch;
		*s = 0;
		io::S = S, io::T = T;
		return s - o;
	}

	inline char get_A()
	{
		register char ch = getc();
		while(ch < 'A' || 'Z' < ch) ch = getc();
		//puts("1");
		return ch;
	}
	
	inline void putc(register char ch) {*iter++ = ch;}
	
	inline void output() {fwrite(buff, 1, iter - buff, stdout), iter = buff;}
}


#define RG register
#define set_file(FILE) freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout)
#define close_file() fclose(stdin), fclose(stdout)
//#include <ext/pb_ds/priority_queue.hpp>
//#include <stdarg.h>

namespace pb_ds
{
	using io::P;
	
	const int MAXN = 200010;
	int fir[MAXN], to[MAXN], next[MAXN], m;
	int have[MAXN];
	int id[MAXN];
	inline void link(RG int a, RG int b)
	{
		static int tot = 1;
		next[++tot] = fir[a], to[fir[a] = tot] = b;
		next[++tot] = fir[b], to[fir[b] = tot] = a;
	}
	int fa[MAXN], dep[MAXN], cnt[MAXN], size[MAXN], chosen[MAXN];
	bool vis[MAXN];
	const int MAXNODE = 4000010;
	std::vector<int> people[MAXN];
	namespace Segment
	{
		int lef[MAXNODE], rig[MAXNODE], size[MAXNODE], tot;
		inline int insert(RG int pos, RG int old, RG int l = 1, RG int r = m)
		{
			RG int at = ++tot;
			size[at] = size[old] + 1;
			if(l < r)
			{
				RG int m = (l + r) >> 1;
				(pos <= m)
					? (lef[at] = insert(pos, lef[old], l, m), rig[at] = rig[old])
					: (lef[at] = lef[old], rig[at] = insert(pos, rig[old], m + 1, r));
	///*lgg*/assert(cnt[at] == cnt[lef[at]] + cnt[rig[at]]);
	///*lgg*/assert(sum[at] == sum[lef[at]] + sum[rig[at]]);
			}
			return at;
		}
		inline int query(RG int A, RG int B, RG int C, RG int D, RG int k)
		{
			RG int l = 1, r = m;
			RG int mid;
			while(l < r)
			{
				RG int lll = size[lef[A]] + size[lef[B]] - size[lef[C]] - size[lef[D]];
				mid = (l + r) >> 1;
///*lgg*/printf("l = %d r = %d mid = %d lll = %d k = %d\n", l, r, mid, lll, k);
				if(k <= lll)
				{
					r = mid;
					A = lef[A];
					B = lef[B];
					C = lef[C];
					D = lef[D];
				}
				else
				{
					l = mid + 1;
					k -= lll;
					A = rig[A];
					B = rig[B];
					C = rig[C];
					D = rig[D];
				}
			}
///*lgg*/assert(!k);
			return l;
		}
	}
	int root[MAXN];
	inline void dfs_init(RG int at)
	{
///*lgg*/assert(!vis[at]);
		vis[at] = 1;
		size[at] = 1;
		dep[at] = dep[fa[at]] + 1;
		cnt[at] = cnt[fa[at]] + have[at];
		root[at] = root[fa[at]];
		For(i, 0, people[at].size() - 1)
		{
			root[at] = Segment::insert(people[at][i], root[at]);
		}
///*lgg*/assert(Segment::size[root[at]] == cnt[at]);
		for(RG int i = fir[at]; i; i = next[i])
			if(!vis[to[i]])
			{
				fa[to[i]] = at;
				dfs_init(to[i]);
				size[at] += size[to[i]];
				if(size[to[i]] > size[chosen[at]])
					chosen[at] = to[i];
			} 
///*lgg*/printf("dfs_init at = %d dep = %d cnt = %d fa = %d size = %d chosen = %d\n", at, dep[at], cnt[at], fa[at], size[at], chosen[at]);
	}
	int top[MAXN], last[MAXN];
	inline void dfs_make(RG int at)
	{
		vis[at] = 0;
		top[at] = (at == chosen[fa[at]]) ? top[fa[at]] : at;
		last[at] = have[at] ? at : last[fa[at]];
///*lgg*/printf("at = %d last = %d top = %d\n", at, last[at], top[at]);
		for(RG int i = fir[at]; i; i = next[i])
			if(vis[to[i]]) dfs_make(to[i]);
	}
	inline int lca(RG int x, RG int y)
	{
		while(top[x] != top[y])
			dep[top[x]] > dep[top[y]]
				? x = fa[top[x]]
				: y = fa[top[y]];
		return dep[x] < dep[y] ? x : y;
	}
	
	inline void main()
	{
		RG int (*F)() = io::F;
		RG int n = F(); m = F();
		RG int q = F();
		For(i, 2, n) link(F(), F());
		RG int temp;
		For(i, 1, m) 
		{
			temp = F();
			++have[temp];
			people[temp].push_back(i);			
		}
		dfs_init(1);
		dfs_make(1);
		RG int x, y, z, a;
		while(q--)
		{
			x = F(), y = F(), a = F();
			z = lca(x, y);
			cmin(a, cnt[x] + cnt[y] - cnt[z] - cnt[fa[z]]);
///*lgg*/printf("z = %d a = %d\n", z, a);
			if(!a) P(0);
			else
			{
				P(a, ' ');
				For(i, 1, a)
					P(Segment::query(root[x], root[y], root[z], root[fa[z]], i), " \n"[i == ___u]);
				
			}		 
		}
	}
		
}

int main()
{
	//set_file("machine");
	pb_ds::main();
	io::output();
	close_file();
}
/*
5 2
1 4 5 3 5
1 2
2 3
1 4
4 5

2 5
2 4


*/