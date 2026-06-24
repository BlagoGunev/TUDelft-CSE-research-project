#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)      for(int (i)=(a);(i)<(b);(i)++)
#define PB              push_back
#define INF             2147483647 // 2e9+
#define INFL            9223372036854775807 // 9e18+
#define MP              make_pair
#define PII             pair<int,int>
#define VI              vector<int>
#define S               size()

#ifdef _SOUL_LOCAL
#define print(___v)     {cout<<"L:"<<__LINE__<<" [";if(___v.S)cout<<___v[0];FOR(___i,1,___v.S)cout<<","<<___v[___i];cout<<"]\n";}
#define DEBUG(___x)     cout<<"L:"<<__LINE__<<" "<<#___x<<" = ["<<___x<<"]"<<endl
#else
#define print(___v)
#define DEBUG(___x)
#endif

#define clr(___x, ___v) memset(___x, ___v , sizeof ___x);
#define tr(container, it) for(__typeof__(container.begin()) it = container.begin(); it != container.end(); it++)

typedef long long                   bint;
template<typename T> string tos( T a )  { stringstream ss; string ret; ss << a; ss >> ret; return ret;}

void read(int &_a) {int temp = scanf("%d", &_a);}
void read(int &_a, int &_b) {int temp = scanf("%d %d", &_a, &_b); }
void read(int &_a, int &_b, int &_c) {int temp = scanf("%d %d %d", &_a, &_b, &_c);}

const int SZ = 55;
int N;
int AR[SZ];

int main() {

#ifdef _SOUL_LOCAL
        assert(freopen("in.txt", "r", stdin));
#endif
        while (cin >> N) {
                FOR (x,0,N) {
                        read(AR[x]);                        
                }
                sort(AR, AR + N);
                if (AR[0] == AR[N/2])puts("Bob");
                else puts("Alice");
        }
        
#ifdef _SOUL_LOCAL
        printf("T+[%.3f] sec\n", (double) clock() / CLOCKS_PER_SEC);
#endif

        return 0;
}