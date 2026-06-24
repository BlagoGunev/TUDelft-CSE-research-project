//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]
//https://github.com/yeetholmes619/Template.git
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#endif
#ifndef DEBUG
#define debug(args...)
#endif
#define curtime             chrono::high_resolution_clock::now()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
using namespace std;
#define ll long long
#define ld long double
#define INF LLONG_MAX
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
template <typename T>
using matrix = vector<vector<T>>;

#define SZ(x) (int)(x.size())
#define mp make_pair
#define allvec(v) v.begin(), v.end()
#define int long long
#define output(value) cout << value << "\n"
const int mod1 =1000000007;
const int mod2 = 998244353;
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); } 
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
	for (auto &it : v)
		cin >> it;
	return istream;
}
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
int n;
vi ax;
vi dx;
int m;
vi ay;
vi dy;

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
        cin>>n;
        ax.assign(n,0);
        cin>>ax;
        dx.assign(n,0);
        cin>>dx;
        cin>>m;
        ay.assign(m,0);
        cin>>ay;
        dy.assign(m,0);
        cin>>dy;
}

void solve(){
        take();
        vector<array<int,2>> nodex;
        vector<array<int,2>> nodey;
        for(int i =0 ; i <n; i++){
                nodex.pb(array<int,2>{ax[i],dx[i]});
        }
        for(int i =0; i < m; i++){
                nodey.pb(array<int,2>{ay[i],dy[i]});
        }
        sort(allvec(nodex),[&](array<int,2> a, array<int,2> b){return a[0] < b[0];});
        debug(nodex);
        sort(allvec(nodey),[&](array<int,2> a, array<int,2> b){return a[0] < b[0];});
        debug(nodey);
        vector<int> best_defencex(size(nodex),0);
        best_defencex[size(nodex)-1] =size(nodex)-1;
        for(int i = size(nodex)-2; i>=0; i--){
                best_defencex[i] = best_defencex[i+1];
                if(nodex[i][1] > nodex[best_defencex[i+1]][1]){
                        best_defencex[i] = i;
                }
        }
        debug(best_defencex);
        vector<int> best_defencey(size(nodey),0);
        best_defencey[size(nodey)-1] =size(nodey)-1;
        for(int i = size(nodey)-2; i>=0; i--){
                best_defencey[i] = best_defencey[i+1];
                if(nodey[i][1] > nodey[best_defencey[i+1]][1]){
                        best_defencey[i] = i;
                }
        }
        debug(best_defencex);
        auto get_nextx = [&](int i)->int{
                auto f = [&](array<int,2> x){
                        return x[0] <= nodex[i][1];
                };
                auto it = partition_point(allvec(nodey),f);
                if(it == nodey.end())
                        return -1;
                return best_defencey[it - nodey.begin()];
        };
        auto get_nexty = [&](int i)->int{
                auto f = [&](array<int,2> y){
                        return y[0] <= nodey[i][1];
                };
                auto it = partition_point(allvec(nodex),f);
                if(it == nodex.end())
                        return -1;
                return best_defencex[it - nodex.begin()];
        };
        matrix<int> dp(2,vi(max(size(nodex),size(nodey)),-2));
        function<int(int,int)> game = [&](int turn, int index)->int{
                debug(turn,index);
                if(dp[turn][index] == -1)
                        return dp[turn][index] = 2;
                if(dp[turn][index] != -2)
                        return dp[turn][index];
                dp[turn][index]++;
                int &ans = dp[turn][index];
                int idnext = (turn) ? get_nexty(index) : get_nextx(index);
                if(idnext == -1){
                        return ans = 1;
                }
                debug(idnext);
                ans = game(turn^1,idnext);
                if(ans == 2)
                        return ans;
                ans ^= 1;
                return ans;
        };

        array<int,3> ansf = {0,0,0};
        for(int i =0 ; i < size(nodex); i++){
                int ans = game(0,i);
                debug(dp);
                ansf[ans]++;
        }
        cout<<ansf[1]<<" "<<ansf[2]<<" "<<ansf[0]<<"\n";













}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 1 ; i <= t; i++) {
		//cout << "Case #" << i << ": ";
        debug(i);
		solve();
	}
#ifdef YEET
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
#endif
    return 0;
}