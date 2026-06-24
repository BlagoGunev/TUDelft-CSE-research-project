#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

struct IO_Tp
{
	inline bool is_digit(const char ch)
	{
		return '0' <= ch && ch <= '9';
	}
	
	inline IO_Tp& operator>>(int& res)
	{
		res = 0;
		static char ch;
		while (ch = getchar(), !is_digit(ch))
			;
		do
			(res *= 10) += ch & 15;
		while (ch = getchar(), is_digit(ch));
		return *this;
	}
} IO;

const int Max_N(200005);

int N, A[Max_N], k[Max_N], lcur[Max_N], rcur[Max_N];
int ST[20][Max_N];
int cur, stack[Max_N];
int64 Ans;

inline int query(const int l, const int r)
{
	int w(k[(r - l + 1) >> 1]);
	return ST[w][l] | ST[w][r - (1 << w) + 1];
}

int main(int argc, char** argv)
{
	
	IO >> N;
	A[0] = A[N + 1] = 1 << 30;
	for (int i(1); i <= N; ++i)
	{
		IO >> A[i], ST[0][i] = A[i];
		while (A[stack[cur]] < A[i])
			--cur;
		lcur[i] = stack[cur];
		stack[++cur] = i;
	}
	stack[cur = 0] = N + 1;
	for (int i(N); i; --i)
	{
		while (A[stack[cur]] <= A[i])
			--cur;
		rcur[i] = stack[cur];
		stack[++cur] = i;
	}
	
	for (int i(0); (1 << i) <= N; ++i)
		for (int j(1 << i); j != (1 << (i + 1)) && j <= N; ++j)
			k[j] = i + 1;
	for (int w(1); (1 << w) <= N; ++w)
		for (int i(1); i + (1 << w) - 1 <= N; ++i)
			ST[w][i] = ST[w - 1][i] | ST[w - 1][i + (1 << (w - 1))];
	
	for (int i(1); i <= N; ++i)
	{
		int l(lcur[i]), r(i);
		int neqcur1, neqcur2;
		while (l + 1 != r)
		{
			int mid((l + r + 1) >> 1);
			(query(mid, i) != A[i] ? l : r) = mid;
		}
		neqcur1 = l;
		l = i, r = rcur[i];
		while (l + 1 != r)
		{
			int mid((l + r) >> 1);
			(query(i, mid) == A[i] ? l : r) = mid;
		}
		neqcur2 = r;
		Ans += static_cast<int64>(i - lcur[i]) * (rcur[i] - i) - static_cast<int64>(i - neqcur1) * (neqcur2 - i);
	}
	
	printf("%I64d", Ans);
	
	return 0;
}