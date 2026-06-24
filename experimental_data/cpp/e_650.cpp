//pb_ds 20160523
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
#define RG register
#define set_file(File) freopen(File ".in", "r", stdin), freopen(File ".out", "w", stdout)
#define close_file() fclose(stdin), fclose(stdout)
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) for(RG int i = a, ___u = b; i != ___u; ++i)
#define cmax(i, j) ((i) < (j) ? (i) = (j) : (i))
#define cmin(i, j) ((i) > (j) ? (i) = (j) : (i))
#define dmax(i, j) ((j) < (i) ? (i) : (j))
#define dmin(i, j) ((i) < (j) ? (i) : (j))
#define ddel(i, j) ((i) > (j) ? (i) - (j) : (j) - (i))
#define dabs(i) ((i) > 0 ? (i) : -(i))
#define dsqr(x) ((x) * (x))
#define lowbit(i) ((i) & -(i))
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
 
namespace io
{
	const int MaxBuff = 1 << 15;
	const int MaxOut = 1 << 24;
	char b[MaxBuff], *S = b, *T = b;
	#define getc() (S == T && (T = (S = b) + fread(b, 1, MaxBuff, stdin), S == T) ? 0 : *S++)
	#define O(x) __attribute__((optimize("-O"#x)))
	#define IL __inline__ __attribute__((always_inline))
	template<class Type> IL Type read()
	{
		RG char ch; RG Type ans = 0; RG bool neg = 0;
		while(ch = getc(), (ch < '0' || ch > '9') && ch != '-')		;
		ch == '-' ? neg = 1 : ans = ch - '0';
		while(ch = getc(), '0' <= ch && ch <= '9') ans = ans * 10 + ch - '0';
		return neg ? -ans : ans;
	}
	IL char get()
	{
		RG char ch;
		while(ch = getc(), ch == ' ' || ch == '\n' || ch == '\r')
			;
		return ch;
	}
	char buff[MaxOut], *iter = buff;
	template<class T> IL void P(RG T x, RG char ch = '\n')
	{
///*lgg*/cout << "output = " << x << endl;
		static int stack[110]; RG int O = 0; RG char *iter = io::iter;
		if(!x)*iter++ = '0';
		else
		{
			(x < 0) ? x = -x, *iter++ = '-' : 1;
			for(; x; x /= 10) stack[++O] = x % 10;
			for(; O; *iter++ = '0' + stack[O--])
				;
		}
		*iter++ = ch, io::iter = iter;
	}
	IL void puts(RG const char *s) {while(*s) *iter++ = *s++;}
	IL void output() {fwrite(buff, 1, iter - buff, stdout), iter = buff;}
}

#define pause() getchar()
#include <map>

namespace pb_ds
{	
	const int MaxN = 500010;
	
	struct Node *null;
	struct Node
	{
		Node *fa, *son[2];
		int val, max;
		bool rev;	
		IL void push_up()
		{
			max = (son[0]->max > son[1]->max) 
				? dmax(son[0]->max, val)
				: dmax(son[1]->max, val);
		}
		IL void do_rev()
		{
			rev ^= 1;
			RG Node *tmp = son[0];
			son[0] = son[1];
			son[1] = tmp;
		}
		IL bool type() const {return fa->son[1] == this;}
		IL bool check() const {return fa->son[type()] == this;}
		IL void rotate()
		{
			RG Node *f = fa; RG bool d = type();
			(fa = f->fa), f->check() ? fa->son[f->type()] = this : 0;
			(f->son[d] = son[!d]) != null ? son[!d]->fa = f : 0;
			(son[!d] = f)->fa = this; f->push_up();
		}
		inline void preview() 
		{
			if(check()) fa->preview(); 
			if(rev)
			{
				if(son[0] != null) son[0]->do_rev();
				if(son[1] != null) son[1]->do_rev();
				rev = 0;
			}
		}
		IL void splay(RG bool need = 1)
		{	
			if(need) preview();
			for(; check(); rotate()) if(fa->check())
				(type() != fa->type()) ? rotate() : fa->rotate();
			push_up();
		}		
		IL void access()
		{
			for(RG Node *i = this, *j = null; i != null; i = (j = i)->fa)
				i->splay(), i->son[1] = j, i->push_up();
		}
		IL void make_root()
		{
			access(), splay(0), do_rev();
		}
		IL void link(RG Node *o)
		{
			make_root(), fa = o;
		}
		IL void cut(RG Node *o)
		{
			make_root(), o->access(), splay(0), son[1] = o->fa = null, push_up();
		}
	} mem[MaxN << 1], *point = mem, *edge = point + MaxN;
	
	struct Edge
	{
		int x, y;
		IL void F()
		{
			x = io::read<int>();
			y = io::read<int>();
			if(x > y) {RG int t = x; x = y; y = t;}
		}
		IL bool operator < (RG const Edge& e) const
		{
			return x < e.x || (x == e.x && y < e.y);
		}
	} e[MaxN], new_e[MaxN];
	bool stay[MaxN], rem[MaxN];
	map<Edge, int> edge_map;
	
	IL void main()
	{	
		null = mem;
	
		RG int (*F)() = io::read<int>;
		RG int n = F();
		RG Node point_normal = (Node) {null, null, null, 0, 0, 0};
		For(i, 0, n) point[i] = point_normal;
		Rep(i, 1, n)
			e[i].F(), edge_map.insert(make_pair(e[i], i));
		RG map<Edge, int>::iterator end = edge_map.end(), iter;
		RG int count = 0;
		Rep(i, 1, n) 
		{
			new_e[i].F();
			if((iter = edge_map.find(new_e[i])) != end)
				stay[iter->second] = rem[i] = 1;
			else ++count;			
		}
		Rep(i, 1, n) 
		{
			edge[i] = (stay[i]) ? point_normal : (Node) {null, null, null, i, i, 0};
			edge[i].link(point + e[i].x);
			edge[i].link(point + e[i].y);
		}
		RG Edge ne;
		RG int rep;
		io::P(count);
		Rep(i, 1, n) if(!rem[i])
		{
			ne = new_e[i]; 
			
			point[ne.x].make_root();
			point[ne.y].access();
			point[ne.y].splay(0);
			
			rep = point[ne.y].max;
			edge[rep].cut(point + e[rep].x);
			edge[rep].cut(point + e[rep].y);
			edge[rep].max = edge[rep].val = 0;
			edge[rep].push_up();
			edge[rep].link(point + ne.x);
			edge[rep].link(point + ne.y);
			
			io::P(e[rep].x, ' ');
			io::P(e[rep].y, ' ');	
			io::P(ne.x, ' ');
			io::P(ne.y);	
		}	
	}
}

int main()
{
	//set_file("prime");
	pb_ds::main();
	io::output();
}
/*
*/