#include<bits/stdc++.h>

using namespace std;

#define all(v)		((v).begin()), ((v).end())



vector< pair<int, int> > a;

int n, k;

long long cur1 = 0, cur2 = 0;

long long firstK()

{

    long long sum = 0;

    for(int i = 1; i < k; i++)

    {

        long long x = abs(a[i].first - a[i - 1].first);

        sum += cur2;

        sum += (1LL * x * i);

        cur2 += (1LL * x * i);

        cur1 += abs(a[i].first - a[0].first);

        

    }

    return sum;

}



int main ()

{

    scanf("%d", &n);

    a.resize(n);

    for(int i = 0; i < n; i++)

    {

        scanf("%d", &a[i].first);

        a[i].second = i + 1;

    }

    sort(all(a));

    scanf("%d", &k);

    

    long long sum = firstK();

    int best = 0;

    long long ans = sum;

    for(int i = k, j = 0; i < n; i++, j++)

    {

        long long _old = 1LL * abs(a[j + 1].first - a[j].first) * (k - 1);

        long long _new = 1LL * abs(a[i].first - a[i - 1].first) * (k - 1);

        sum -= cur1;

        cur1 -= _old;

        cur1 += abs(a[i].first - a[j + 1].first);

        cur2 += _new;

        cur2 -= abs(a[i - 1].first - a[j].first);

        sum += cur2;

        if(sum < ans)

        {

            ans = sum;

            best = j + 1;

        }

    }

 //   cout << ans << endl;

    for(int i = 0; i < k; i++)

        printf("%d ", a[i + best].second);

    printf("\n");

}