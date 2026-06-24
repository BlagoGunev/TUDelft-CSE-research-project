#include "bits/stdc++.h"

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

typedef long double ld;

ld PI = acos((ld)-1.0);

const ld eps = 1e-9;

//#define ENABLE_FREAD

namespace io_impl
{
	inline bool maybe_digit(char c)
	{
		return c >= '0' && c <= '9';
	}

	struct io_s
	{
	private:
		bool negative;
		bool ok = true;
		char ch = next_char();

		int precious;
		long double epslion;

#ifdef ENABLE_FREAD
		inline char next_char() {
			static char buf[100000], *p1 = buf, *p2 = buf;
			return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
		}
#else
		char next_char() const
		{
			return getchar();
		}
#endif
	public:

#pragma region read int

		template <typename T>
		bool rn(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF)
			{
				negative = ch == '-';
				ch = next_char();
			}
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			} while (maybe_digit(ch = next_char()));
			if (negative) _v = -_v;
			return true;
		}

		template <typename T>
		void rn_unsafe(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch))
			{
				negative = ch == '-';
				ch = next_char();
			}
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			} while (maybe_digit(ch = next_char()));
			if (negative) _v = -_v;
		}

		template <typename T>
		T rn()
		{
			T v = T();
			rn_unsafe(v);
			return v;
		}

#pragma endregion

#pragma region read unsigned

		template <typename T>
		bool run(T& _v)
		{
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF) ch = next_char();
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			} while (maybe_digit(ch = next_char()));
			return true;
		}

		template <typename T>
		void run_unsafe(T& _v)
		{
			_v = 0;
			while (!maybe_digit(ch)) ch = next_char();
			do
			{
				_v = (_v << 1) + (_v << 3) + ch - '0';
			} while (maybe_digit(ch = next_char()));
		}

		template <typename T>
		T run()
		{
			T v = T();
			run_unsafe(v);
			return v;
		}

#pragma endregion

#pragma region read float

		template <typename T>
		bool rd(T& _v)
		{
			negative = false;
			_v = 0;
			while (!maybe_digit(ch) && ch != EOF)
			{
				negative = ch == '-';
				ch = next_char();
			}
			if (ch == EOF)return ok = false;
			do
			{
				_v = (_v * 10) + (ch - '0');
			} while (maybe_digit(ch = next_char()));
			static int stk[70], tp;
			if (ch == '.')
			{
				tp = 0;
				T _v2 = 0;
				while (maybe_digit(ch = next_char()))
				{
					stk[tp++] = ch - '0';
				}
				while (tp--)
				{
					_v2 = _v2 / 10 + stk[tp];
				}
				_v += _v2 / 10;
			}
			if (ch == 'e' || ch == 'E')
			{
				ch = next_char();
				static bool _neg = false;
				if (ch == '+') ch = next_char();
				else if (ch == '-') _neg = true, ch = next_char();
				if (maybe_digit(ch))
				{
					_v *= pow(10, run<LL>() * (_neg ? -1 : 1));
				}
			}
			if (negative) _v = -_v;
			return true;
		}

		template <typename T>
		T rd()
		{
			T v = T();
			rd(v);
			return v;
		}

#pragma endregion

#pragma region read string

		int gets(char* s)
		{
			char* c = s;
			while (ch == '\n' || ch == '\r' || ch == ' ') ch = next_char();
			if (ch == EOF) return (ok = false), *c = 0;
			do
			{
				*(c++) = ch;
				ch = next_char();
			} while (ch != '\n' && ch != '\r' && ch != ' ' && ch != EOF);
			*(c++) = '\0';
			return static_cast<int>(c - s - 1);
		}

		int getline(char* s)
		{
			char* c = s;
			while (ch == '\n' || ch == '\r') ch = next_char();
			if (ch == EOF) return (ok = false), *c = 0;
			do
			{
				*(c++) = ch;
				ch = next_char();
			} while (ch != '\n' && ch != '\r' && ch != EOF);
			*(c++) = '\0';
			return static_cast<int>(c - s - 1);
		}

		char get_alpha()
		{
			while (!isalpha(ch)) ch = next_char();
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		char get_nonblank()
		{
			while (iswspace(ch)) ch = next_char();
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		char get_char()
		{
			const char ret = ch;
			ch = next_char();
			return ret;
		}

		template <typename T>
		void o(T p)
		{
			static int stk[70], tp;
			if (p == 0)
			{
				putchar('0');
				return;
			}
			if (p < 0)
			{
				p = -p;
				putchar('-');
			}
			while (p) stk[++tp] = p % 10, p /= 10;
			while (tp) putchar(stk[tp--] + '0');
		}

		template <typename T>
		void od(T v)
		{
			static int stk[70], tp;
			tp = 0;
			if (fabs(v) < epslion / 10)
			{
				putchar('0');
				if (precious > 0)
				{
					putchar('.');
					for (int i = 0; i < precious; ++i) putchar('0');
				}
				return;
			}
			if (v < 0)
			{
				v = -v;
				putchar('-');
			}
			v += epslion / 2;
			T p = floor(v) + epslion / 10;
			while (fabs(p) > 1 - epslion)
			{
				stk[++tp] = fmod(p, 10), p = floor(p / 10) + epslion;
			}
			if (tp == 0) putchar('0');
			while (tp) putchar(stk[tp--] + '0');
			if (precious == 0) return;
			putchar('.');
			v -= floor(v);
			for (int i = 0; i < precious; ++i)
			{
				v *= 10;
				putchar((int)floor(v) + '0');
				v = fmod(v, 1);
			}
		}

#pragma endregion

#pragma region enhancement

		typedef void io_operator_func(io_s& v);
		typedef char* charptr;

		template <typename T>
		io_s& operator >>(T& x)
		{
			if (numeric_limits<T>::is_signed) rn(x);
			else run(x);
			return *this;
		}

		template <typename T>
		io_s& operator <<(const T& x);

		io_s& operator <<(io_operator_func* v)
		{
			v(*this);
			return *this;
		}

		operator bool() const { return ok; }

		void set_precious(int x)
		{
			precious = x;
			epslion = pow(10, -x);
		}

		int ri() { return rn<int>(); }
		LL rll() { return rn<LL>(); }

		static void new_line(io_s& v)
		{
			putchar('\n');
		}

		static void flush(io_s& v)
		{
			fflush(stdout);
		}
#pragma endregion
	};

#pragma region input fix

	template <>
	inline io_s& io_s::operator >>(char*& x)
	{
		gets(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(float& x)
	{
		rd(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(double& x)
	{
		rd(x);
		return *this;
	}

	template <>
	inline io_s& io_s::operator >>(long double& x)
	{
		rd(x);
		return *this;
	}

#pragma region output fix

	template <>
	inline void io_s::o(const char p)
	{
		putchar(p);
	}

	template <>
	inline void io_s::o(const char* p)
	{
		printf(p);
	}

	template <>
	inline void io_s::o(float p)
	{
		od(p);
	}

	template <>
	inline void io_s::o(double p)
	{
		od(p);
	}

	template <>
	inline void io_s::o(long double p)
	{
		od(p);
	}

	template <typename T>
	io_s& io_s::operator <<(const T& x)
	{
		o(x);
		return *this;
	}

	io_s::io_operator_func* nl = io_s::new_line;
	io_s::io_operator_func* fl = io_s::flush;

#pragma endregion
}

using namespace io_impl;

io_s io;

typedef void InitFunction();
typedef bool SolveFunction(int);

struct env_s
{
private:
	bool global_inited = false;

	bool case_inited = false;
public:
	bool once()
	{
		return global_inited ? false : (global_inited = true);
	}

	bool every()
	{
		return case_inited ? false : (case_inited = true);
	}

	InitFunction *_initOnce, *_init;

	template <InitFunction TInitOnce, InitFunction TInit>
	void configure()
	{
		_initOnce = TInitOnce;
		_init = TInit;
	}

	void init(bool global)
	{
		if (global) if (_initOnce != nullptr)_initOnce();
		if (_init != nullptr) _init();
	}

	void empty_init()
	{
	}

	template <SolveFunction TSolve>
	void solve_single()
	{
		global_inited = false;
		case_inited = false;
		init(true);
		TSolve(0);
	}

	template <SolveFunction TSolve>
	void solve_many()
	{
		global_inited = false;
		int T = io.ri();
		for (int cs = 1; T--; ++cs)
		{
			case_inited = false;
			init(cs == 1);
			if (!TSolve(cs))break;
		}
	}

	template <SolveFunction TSolve>
	void solve_much()
	{
		global_inited = false;
		case_inited = false;
		for (int cs = 1; init(cs == 1), TSolve(cs); ++cs)
			case_inited = false;
	}
} env;

namespace solution
{
#pragma region init

	void init_once()
	{
		srand(time(nullptr));
		io.set_precious(12);
		//io.set_precious(2);
	}

	void init_every()
	{
	}

#pragma endregion

	const int N = 2e3 + 10;
	const int M = 715;

	typedef pair<int, int> P;

	P a[N];

	vector<vector<int>> s;
	map<vector<int>, int> MP;

	int b[2][M];

	void up(int& x, int y)
	{
		if (y < x) x = y;
	}

	void dfs(int p, const vector<int>& v)
	{
		if (p >= 9)
		{
			s.push_back(v);
			MP[v] = s.size() - 1;
			return;
		}
		dfs(p + 1, v);
		if (v.size() < 4)
		{
			vector<int> u = v;
			u.push_back(p);
			dfs(p, u);
		}
	}

	int ID(vector<int> V)
	{
		assert(V.size() <= 4);
		sort(V.begin(), V.end());
		return MP[V];
	}

	bool solve(int _cas)
	{
		dfs(0, {});
		assert(s.size() == M);
		int n;
		io >> n;
		for (int i = 1; i <= n; ++i) io >> a[i].first >> a[i].second, --a[i].first, --a[i].second;
		int now = 0;
		memset(b[now], 0x3f, sizeof(b[now])); int inf = b[now][0];
		b[now][0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			int nxt = 1 - now;
			memset(b[nxt], 0x3f, sizeof(b[nxt]));
			int S = a[i].first, T = a[i].second;
			int pre = a[i - 1].first;
			int l = min(pre, S), r = max(pre, S);
			for (int k = 0; k < M; ++k) if (b[now][k] < inf)
			{
				auto v = s[k];
				v.erase(lower_bound(v.begin(), v.end(), l), upper_bound(v.begin(), v.end(), r));
				if (v.size() == 0)
				{
					up(b[nxt][ID({T})], b[now][k] + r - l);
					continue;
				}
				if(v.size()<4)
				{
					v.push_back(T);
					up(b[nxt][ID(v)], b[now][k] + r - l);
					v.pop_back();
				}
				vector<int> left(v.begin(), lower_bound(v.begin(), v.end(), l));
				vector<int> right(upper_bound(v.begin(), v.end(), r), v.end());
				auto lx = left.begin();
				while(true)
				{
					auto rx = right.begin(); int last = 0;
					while(true)
					{
						int adv = 2 * ((rx == right.begin() ? 0 : (last - r)) + (lx == left.end() ? 0 : (l - *lx))) + r - l;
						vector<int> u = { T };
						for (auto p = left.begin(); p != lx; ++p) u.push_back(*p);
						for (auto p = rx; p != right.end(); ++p) u.push_back(*p);
						if(u.size()<=4)
						{
							up(b[nxt][ID(u)], b[now][k] + adv);
						}
						if (rx == right.end())break; last = *rx++;
					}
					if (lx == left.end())break; ++lx;
				}
			}
			now = nxt;
		}
		int ans = inf;
		for(int k =0; k<M; ++k) if(b[now][k]<inf)
		{
			auto v = s[k];
			auto sz = v.size();
			int left = max(0, a[n].first - v[0]), right = max(0, v[sz - 1] - a[n].first);

			up(ans, b[now][k] + min(left, right) + left + right);
		}
		io << ans + n * 2 << nl;
		return true;
	}
}

int main()
{
	//env.fileInput();
	env.configure<solution::init_once, solution::init_every>();
	env.solve_single<solution::solve>();
	return 0;
}