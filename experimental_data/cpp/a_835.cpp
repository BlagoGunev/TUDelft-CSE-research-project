#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;

#define loop(n)          for(int i = 0; i < (n); i++)
#define lp(x, s, e)      for(int x = (s); x < (e); x++)
#define lpe(x, s, e)     for(int x = (s); x <= (e); x++)

#define MP make_pair
#define PB push_back
#define all(a)   a.begin(),a.end()
#define clr(x, val)	memset((x), (val), sizeof(x))
#define endl '\n'

int main()
{
    int s ,v1 , v2 , t1 , t2 , p1 , p2;
    cin >> s >> v1 >> v2 >> t1 >> t2 ;
    p1 = (v1*s)+(t1*2);
    p2 = (v2*s)+(t2*2);
    if(p1<p2)
      cout << "First" << endl;
    else if (p1>p2)
      cout << "Second" << endl;
    else
        cout << "Friendship" << endl;

    return 0;
}