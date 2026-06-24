// Problem: E. Coloring

// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)

// URL: https://codeforces.com/contest/1574/problem/E

// Memory Limit: 256 MB

// Time Limit: 2000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#pragma GCC optimize(2)

#pragma GCC optimize(3)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/hash_policy.hpp>

#define all(x) (x).begin(), (x).end()

#define gb std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define pi acos(-1.0)

#define fi first

#define se second

#define rep(i,a,b) for(int i=a;i<=b;++i)

#define fep(i,a,b) for(int i=b;i>=a;--i)

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

#define DEC(i, a, b) for (int i = (a); i >= (b); --i)

#define int long long 

#define random(x) (rand()%x)

#define endl '\n' 

#define cf int _; cin>> _; while(_--)

 

using namespace std;

using namespace __gnu_pbds;

typedef long long ll;

typedef pair<int, int> PII;

const double eps = 1e-9;

typedef pair<int, PII> PIII;

typedef unsigned long long ULL;

typedef deque<int>::iterator iterator_t;

typedef pair<double, double> PDD;

typedef const int& cint;

const int N = 1e6+10,INF=0x3f3f3f3f;

const int mod=998244353;

//const int INF = (1ULL<<63)-1;

const double PI=acos(-1);

int pw[N];

map<pair<int, int>, int> mp;



struct node{

	int c[3];

	// c[0]表示不合法的数量

    // c[1]表示固定列的数量

    // c[2]表示自由列的数量

	int s[N][2];

	//s 表示把这一列的状态压缩到两行

    // 考虑 s[x]

    // 若s[x][0]和s[x][1] 都有值，说明压缩的列中有连续相同的数字，不合法

    // 其中有一个有值，是固定列

    // 都无值，是自由列

    void erase(int x, int y, int z) {

    	

        c[! s[x][0] + ! s[x][1]] -= 1; 

        s[x][(y ^ z) & 1] -= 1; //状态数量 -1

        c[! s[x][0] + ! s[x][1]] += 1; 

        //上面一种状态转移到下面一种状态

       

    }

    void insert(int x, int y, int z) {

    	

        c[! s[x][0] + ! s[x][1]] -= 1;

        s[x][(y ^ z) & 1] += 1;

        c[! s[x][0] + ! s[x][1]] += 1;

        //同上

    }

    int ans(){

    	return c[0] ? 0 : pw[c[2]];

    }

    void init(int n){

    	c[2]=n;

    }

}R,C;



signed main(){

    gb;

    int n,m,k;

    cin>>n>>m>>k;

    pw[0]=1;

    for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%mod;

    R.init(n);C.init(m);

    int c[2] = {}; //记录重复的值

    // c[0]表示1010这种情况出现过没有

    // c[1]表示0101这种情况出现过没有

    rep(i,0,k-1){

    	int x,y,z;

    	cin>>x>>y>>z;

    	if (mp.count({x, y})) {//若之前被赋值了，先删去

            c[(x ^ y ^ mp[{x, y}]) & 1] -= 1;

            R.erase(x, y, mp[{x, y}]);

            C.erase(y, x, mp[{x, y}]);

            mp.erase({x, y});

        }

    	if(z!=-1){

    		//关于 (x ^ y ^ z) & 1  考虑一行

            //若是 101010  则值为 1 1 1 1 1 1 对应为c[1]=5,c[0]=0;

            //表示有一种情况出现了，重复值为 1 下面同理

            //若是 010101  则值为 0 0 0 0 0 0 重复值为 1

            //若是 110010  则值为 1 0 0 1 1 1 重复值为 0

            c[(x ^ y ^ z) & 1] += 1;

            R.insert(x, y, z);

            C.insert(y, x, z);

            mp[{x, y}] = z;

    	}

    	 //c[1]和c[2]都等于0 ，说明矩阵中没有已填充数字，重复值为2

        //有一个>0,另一个等于0 ，重复值为1

        //两个都>0，说明矩阵中有连续相同的数字，重复值为0

        cout<<(R.ans()+C.ans()+mod-!c[0]-!c[1])%mod<<endl;

    }

    return 0;

}