#include<bits/stdc++.h>

using namespace std;

#define all(v)		((v).begin()), ((v).end())

#define sz(v)		((int)((v).size()))

#define clr(v, d)	memset(v, d, sizeof(v))

#define pb					push_back

#define MP					make_pair

#define ff  first

#define ss second

#define mod(a,b)  (a%b+b)%b



typedef long long         ll;

const int MAX = 1e7 + 5;





int p[MAX];

long long vis[MAX];

vector< pair<int, long long> > prime;

void sieve()

{

    for(int i = 2; i * i < MAX; i++)

        if(p[i] == 0)

            for(int j = i; j < MAX; j += i)

                p[j] = i;

    for(int i = 2; i < MAX; i++)

        if(p[i] == 0) p[i] = i;

}

void start()

{

    long long cnt = 0, b = 0;

    for(int i = MAX - 1; i >= 2; i --)

    {

        b = vis[i];

        vis[i] += cnt;

        cnt += b;

    }

    for(int i = MAX - 1; i >= 2; i --)

        if(p[i] != i)

        {

            vis[p[i]] += vis[i];

            vis[i / p[i]] += vis[i];

        }

        else if(vis[i])

            prime.push_back({i, vis[i]});

}



long long PP(long long n, int p)

{

    long long ans = 0, a = p;

    while (n >= a)

    {

        ans += (n / a);

        a *= p;

    }

    return ans;

}





bool solve(long long mid)

{

    for(int i = 0; i < prime.size(); i++)

    {

        long long v = PP(mid, prime[i].first);

        if(prime[i].second > v) return 0;

    }

    return 1;

}





int main ()

{

    int n, x;

    cin >> n;

    for(int i = 0; i < n; i++)

    {

        scanf("%d", &x);

        vis[x] ++;

    }

    

    sieve();

    start();

    long long l = 1, h = 1e14;

    long long ans = 0;

    while (l <= h)

    {

        long long mid = (l + h + 1) / 2;

        if(solve(mid))

        {

            h = mid - 1;

            ans = mid;

        }

        else l = mid + 1;

    }

    cout << ans << endl;

}