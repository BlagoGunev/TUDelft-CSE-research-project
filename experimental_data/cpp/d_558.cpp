#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int int64;

struct Event {
	int64 where;
	int what;
	Event (const int64 & a = 0, const int & b = 0) : where (a), what (b) {
		return;
	}
};

inline bool operator < (const Event & a, const Event & b) {
	if (a.where != b.where)
		return a.where < b.where;
	return a.what > b.what;
}

vector <Event> events;
const int INF = 0x3F3F3F3F;
int64 l, r, p;
int h, q, i, ans;

int main () {
	events.push_back (Event (0, 0));
	scanf ("%d%d", & h, & q);
	p = ((int64) (1)) << (h - 1);
	while (q --) {
		scanf ("%d%I64d%I64d%d", & i, & l, & r, & ans);
		l = (l << (h - i)) - p;
		r = ((r + 1) << (h - i)) - p;
		if (ans) {
			events.push_back (Event (0, 1));
			events.push_back (Event (l, -1));
			events.push_back (Event (r, 1));
		}
		else {
			events.push_back (Event (l, 1));
			events.push_back (Event (r, -1));
		}
	}
	events.push_back (Event (p, INF));
	sort (events.begin (), events.end ());
	l = -1;
	r = 0;
	for (i = 0; i < (int) (events.size ()); i ++) {
		r += events [i].what;
        if (! r) {
        	if (l != -1 || events [i + 1].where > events [i].where + 1)
        		goto UNDEFINED;
			l = events [i].where;
        }
	}
	if (l == -1)
		goto NO_SOLUTION;
	else
		goto SOLVED;

	NO_SOLUTION:
	printf ("Game cheated!\n");
	goto END;

	UNDEFINED:
	printf ("Data not sufficient!\n");
	goto END;

	SOLVED:
	printf ("%I64d\n", p + l);
	goto END;

	END:
	return 0;
}