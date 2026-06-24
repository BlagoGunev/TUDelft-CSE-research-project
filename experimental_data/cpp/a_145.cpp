#include <algorithm>

#include <iostream>

#include <cstring>

#include <vector>

#include <cstdio>

#include <string>

#include <cmath>

#include <queue>

#include <set>

#include <map>

#include<complex>

using namespace std;

typedef long long ll;

typedef double db;

typedef pair<int,int> pii;

typedef vector<int> vi;

#define de(x) cout << #x << "=" << x << endl

#define rep(i,a,b) for(int i=a;i<(b);++i)

#define all(x) (x).begin(),(x).end()

#define sz(x) (int)(x).size()

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)

const int N = 101010;

char s[N] , t[N];

int cnt[10][10];



int main(){

    scanf("%s%s",s , t);

    for(int i=0;s[i];++i) cnt[s[i] - '0'][t[i] - '0']++;

    printf("%d\n",max(cnt[4][7],cnt[7][4]));

    return 0;

}