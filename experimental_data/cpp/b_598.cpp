#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

using namespace std;



int main()

{

    string s;

    cin >> s;

    int q;

    scanf("%d",&q);

    while(q--)

    {

		int l, r, k;

		scanf("%d%d%d",&l,&r,&k);

		l--;

		int len = r - l;

		k %= len;

		rotate(s.begin() + l, s.begin() + r - k , s.begin() + r);

    }

    cout << s;

}