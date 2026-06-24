#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <map>

#include <queue>

#include <deque>

#include <vector>

#include <cstdlib>

#include <utility>

#include <iostream>

using namespace std;

typedef long long ll;







#define PB(a) push_back(a);

#define INF = 1000000000;

#define REP(i,n) for (int i = 0; i < n; i++)

#define REPI(i,n) for (int i = 1; i <= n; i++)

#define REPN(i,n) for (int i = n-1; i >= 0; i--)

#define REPF(j,i,n) for (int j = i; j < n; j++)







int prime[100005];

int a[100005];

int dop[100005];

vector<pair<int, int> > ans;

int main()

{

    int n;

    scanf("%d",&n);

    for(int i = 1; i <= n; ++i){

        scanf("%d", &a[i]);

        dop[a[i]] = i;

    }

    for(int i = 2; i <= n; ++i) prime[i] = 1;

   	 for (int i = 2; i <= n; ++i)

   	 		

        if (prime[i])

            if (i * 1ll * i <= n)

                for (int j = i * i; j <= n; j += i)

                prime[j] = 0;

                

    int first = 2;

    for(int i = 2; i <= n; ++i){

        if(prime[i] == 1) first = i;

        prime[i] = first;

    }

    int fl = 0;

    for(int i = 1; i <= n; ++i){

        if(dop[i] != i)

        while(dop[i] != i){

            int z = prime[dop[i] - i + 1];

            ans.push_back(make_pair(dop[i], dop[i] - z + 1));

            fl = dop[i];

            dop[a[dop[i] - z + 1]] = dop[i];

            dop[i] = dop[i] - z + 1;

            swap(a[fl], a[fl - z + 1]);

        }

    }

    printf("%d\n",ans.size());

    for(int i = 0; i < ans.size(); ++i){

        printf("%d %d\n", ans[i].second, ans[i].first);

    }

    return 0;

}