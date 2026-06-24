#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 1000009;
struct Seg
{
    int total;
    int rev;
    int ans1;
    int ans2;
}segs[SIZE * 6];

char buf[SIZE];
int N, M;
void init(int idx, int l, int r)
{
    if(r - l == 1)
    {
	segs[idx].total = (buf[l] == '7');
	segs[idx].rev = 0;
	segs[idx].ans1 = segs[idx].ans2 = 1; 
    }
    else
    {
	int m = (l + r) / 2;
	init(idx * 2, l, m);
	init(idx * 2 + 1, m, r);
segs[idx].total = segs[idx * 2].total + segs[idx * 2 + 1].total;

	segs[idx].ans1 = max(m - l - segs[idx * 2].total + segs[idx * 2 + 1].ans1,
		     segs[idx * 2].ans1 + segs[idx * 2 + 1].total);
	segs[idx].ans2 = max(segs[idx * 2].total + segs[idx * 2 + 1].ans2,
		             segs[idx * 2].ans2 + r - m - segs[idx * 2 + 1].total);
    }
}
void f(int idx, int l, int r, int s, int e)
{
    if(s <= l && r <= e)
    {
	segs[idx].rev ^= 1;
	segs[idx].total = r - l - segs[idx].total;
	swap(segs[idx].ans1, segs[idx].ans2);
    }
    else
    {
	int m = (l + r) / 2;
	if(segs[idx].rev)
	{
	    segs[idx].rev = 0;
	    f(idx * 2, l, m, l, m);
	    f(idx * 2 + 1, m, r, m, r);
	}

	if(s < m)
	    f(idx * 2, l, m, s, e);
	if(e > m)
	    f(idx * 2 + 1, m, r, s, e);

        segs[idx].total = segs[idx * 2].total + segs[idx * 2 + 1].total;

	segs[idx].ans1 = max(m - l - segs[idx * 2].total + segs[idx * 2 + 1].ans1,
		     segs[idx * 2].ans1 + segs[idx * 2 + 1].total);
	segs[idx].ans2 = max(segs[idx * 2].total + segs[idx * 2 + 1].ans2,
		             segs[idx * 2].ans2 + r - m - segs[idx * 2 + 1].total);
    }
}

int main()
{
    scanf("%d%d", &N, &M);

    scanf("%s", buf);

    init(1, 0, N);

    while(M--)
    {
	scanf("%s", buf);
	if(buf[0] == 'c')
	    printf("%d\n", segs[1].ans1);
	else
	{
	    int l, r;
	    scanf("%d%d", &l, &r);
	    f(1, 0, N, l - 1, r);
	}
    }


    return 0;
}