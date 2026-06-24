#include <bits/stdc++.h>

using namespace std;





struct cpx

{

  cpx(){}

  cpx(double aa):a(aa),b(0){}

  cpx(double aa, double bb):a(aa),b(bb){}

  double a;

  double b;

  double modsq(void) const

  {

    return a * a + b * b;

  }

  cpx bar(void) const

  {

    return cpx(a, -b);

  }

};



cpx operator +(cpx a, cpx b)

{

  return cpx(a.a + b.a, a.b + b.b);

}



cpx operator -(cpx a, cpx b)

{

  return cpx(a.a - b.a, a.b - b.b);

}



cpx operator *(cpx a, cpx b)

{

  return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);

}



cpx operator /(cpx a, cpx b)

{

  cpx r = a * b.bar();

  return cpx(r.a / b.modsq(), r.b / b.modsq());

}







const int MAXP = 1<<19;



typedef cpx base;



base *W[2][20];



const long double PI = acos(-1);

int N;



void initfft()

{

	for (int i = 1; i < 20; i++)

	{

		int len = (1<<i);

		double ang = 2*PI/(1<<i);

		base wlen (cos(ang), sin(ang));

		base w (1);

		W[0][i] = new base[len/2];

		for (int j = 0; j < len/2; j++)

		{

			W[0][i][j] = w;

			w = w*wlen;

		}

	}

	for (int i = 1; i < 20; i++)

	{

		int len = (1<<i);

		double ang = -2*PI/(1<<i);

		base wlen (cos(ang), sin(ang));

		W[1][i] = new base[len/2];

		base w (1);

		for (int j = 0; j < len/2; j++)

		{

			W[1][i][j] = w;

			w = w*wlen;

		}

	}

}



void fft (base a[], bool invert) {

	int n = N;

 	for (int i=1, j=0; i<n; ++i) {

		int bit = n >> 1;

		for (; j>=bit; bit>>=1)

			j -= bit;

		j += bit;

		if (i < j)

			swap (a[i], a[j]);

	}

	int ind = 0;

	if (invert)

		ind = 1;

 	base w (1);

 	int ii = 1;

 	for (int len=2; len<=n; len<<=1) {

		for (int i=0; i<n; i+=len) {

			for (int j=0; j<len/2; ++j) {

				w = W[ind][ii][j];

				base u = a[i+j],  v = a[i+j+len/2] * w;

				a[i+j] = u + v;

				a[i+j+len/2] = u - v;

			}

		}

		ii++;

	}

	if (invert)

		for (int i=0; i<n; ++i)

			a[i] = a[i] / n;

}



base fb[2][MAXP + 5];

int res[MAXP + 5];

base A[MAXP +5];



void multiply (const vector<int> & a, int b) {

	for (int i = 0; i < N; i++)

		A[i] = base(0,0);

	for (int i = 0; i < a.size(); i++)

		A[i] = base(a[i]);

	fft (A, false);

	for (size_t i=0; i<N; ++i)

		A[i] = A[i]*fb[b][i];

	fft (A, true);

	for (size_t i=0; i<N; ++i)

		res[i] = int (A[i].a + 0.5);

}



const int MAXS = 10005;

const int MAXN = 200005;

const int MAXB = MAXN / MAXS + 5;

string a;

string b;

int offset;

int n;

short ones[MAXB][MAXN*2];

short zeros[MAXB][MAXN*2];

int ab[MAXN];

int bb[MAXN];



int L(int i)

{

	return i*MAXS;

}



int R(int i)

{

	return min(n-1, (i+1) * MAXS - 1);

}



int getRange(int i, int l, int r, int dif)

{

	if (L(i) >= l && R(i) <= r)

	{

		int ind = dif + offset - L(i);

		return ones[i][ind] + zeros[i][ind];

	}

	if (R(i) < l || L(i) > r)

		return 0;

	int ans = 0;

	int stop = min(r, R(i));

	int ca, cb;

	ca = max(l, L(i));

	int all = stop - ca + 1;

	cb = ca - dif;

	for (; ca+31 <= stop; ca += 32, cb += 32)

	{

		ans +=  __builtin_popcount(ab[ca]^bb[cb]);

	}

	while (ca <= stop)

	{

		ans += (a[ca] != b[cb]);

		cb++;

		ca++;

	}

	return all - ans;

}



int getAns(int l, int r, int dif)

{

	int ans = 0;

	for (int i = 0; L(i) < n; i++)

		ans += getRange(i, l, r, dif);

	return ans;

}





void initBitSet()

{

	for (int i = 0; i < 32; i++)

	{

		for (int j = i; j < a.size(); j+= 32)

		{

			int cnt = 0;

			for (int k = 0; k < 32 && j+k < a.size(); k++)

			{

				if (a[j+k] == '1')

					cnt |= (1<<k);

			}

			ab[j] = cnt;

		}

	}



	for (int i = 0; i < 32; i++)

	{

		for (int j = i; j < b.size(); j+= 32)

		{

			int cnt = 0;

			for (int k = 0; k < 32 && j+k < b.size(); k++)

			{

				if (b[j+k] == '1')

					cnt |= (1<<k);

			}

			bb[j] = cnt;

		}

	}

}



void init()

{

	initfft();

	initBitSet();

	N = 1;

	while (N < max(MAXS, (int)b.size()))

		N <<= 1;

	N <<= 1;

	

	for (int i = b.size() - 1; i >= 0; i--)

	{

		fb[0][b.size() - 1 - i] = base(b[i]-'0');

		fb[1][b.size() - 1 - i] = base(1 - (b[i]-'0'));

	}

	for (int i = b.size(); i < N; i++)

		fb[0][i]= fb[1][i] = base(0);

	offset = b.size() - 1;

	fft(fb[0], false);

	fft(fb[1], false);

	vector<int> left(MAXS);

	for (int i = 0; L(i) < n; i++)

	{

		int start = L(i);

		int end = R(i);

		if (end - start + 1 < MAXS)

		{

			left.resize(end - start + 1);

		}

		for (int j = start; j <= end; j++)

		{

			left[j-start] = a[j] - '0';

		}

		multiply(left, 0);

		int n2 = 2*b.size();

		for (int j = 0; j <= n2; j++)

			ones[i][j] = res[j];

		for (int j = 0; j < left.size(); j++)

			left[j] = 1 - left[j];

		multiply(left, 1);

		for (int j = 0; j < n2; j++)

			zeros[i][j] = res[j];

	}

}



char s[200005];



int main()

{

	scanf("%s", s);

	a = string(s);

	n = a.size();

	scanf("%s", s);

	b = string(s);

	

	init();

	int q;

	scanf("%d", &q);

	while (q--)

	{

		int l1, l2, len;

		scanf("%d %d %d", &l1, &l2, &len);

		int r = l1 + len - 1;

		int dif = l1 - l2;

		printf("%d\n", len - getAns(l1, r, dif));

	}

}