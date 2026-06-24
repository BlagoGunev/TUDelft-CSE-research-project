#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <set>
#include <deque>
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long
#define ld double long
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
const ld pi = 3.141592653589793238;
const ll INF = 9e18;

vector<int> Ans;
vector<int> Ar;
int n;
void comp(int l, int r){
    int c = 0;
    vector<int> Build;
    int flag = 0;
    for(int i = r+1;i<n;i++){
        Build.push_back(Ar[i]);
        if(Ans[c]>Build[c]&&!flag){
            return;
        }
        if(Ans[c]<Build[c]){
            flag = 1;
        }
        c++;
    }
    for(int i = r;i>=l;i--){
        Build.push_back(Ar[i]);
        if(Ans[c]>Build[c]&&!flag){
            return;
        }
        if(Ans[c]<Build[c]){
            flag = 1;
        }
        c++;
    }
    for(int i = 0;i<l;i++){
        Build.push_back(Ar[i]);
        if(Ans[c]>Build[c]&&!flag){
            return;
        }
        if(Ans[c]<Build[c]){
            flag = 1;
        }
        c++;
    }
    Ans = Build;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int TC = 0; TC < t; TC++) {
        cin >> n;
        Ar.clear();
        Ans.clear();
        for (int i = 0; i < n; i++) {
            Ans.push_back(0);
            int a;
            cin >> a;
            Ar.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                comp(i,j);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << Ans[i] << " ";
        }
        cout << "\n";
    }

}