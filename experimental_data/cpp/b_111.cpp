#include <cstdio>
using namespace std;

const int SIZE = 100009;
int N;

int table[SIZE];
bool ptable[SIZE];
int primes[SIZE];
int total;
int fac[128];
int exp[128];

int go(int loc, int v, int bound, int idx)
{
    if(!loc)
    {
        int ret = table[v] < bound;
        table[v] = idx;
        return ret;
    }
    else
    {
        int ret = 0;
        for(int j = 0; j <= exp[loc - 1]; j++, v *= fac[loc - 1])
            ret += go(loc - 1, v, bound, idx);
        return ret;
    }
}

int main()
{
    for(long long int i = 2; i < SIZE; i++)
        if(!ptable[i])
        {
            primes[total++] = i;
            for(long long int j = i * i; j < SIZE; j += i)
                ptable[j] = true;
        }

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        int now = 0;
        int t = x;
        for(int j = 0; j < total && primes[j] * primes[j] <= t; j++)
            if(t % primes[j] == 0)
            {
                exp[now] = 0;
                fac[now] = primes[j];
                while(t % primes[j] == 0)
                    t /= primes[j], exp[now]++;

                now++;
            }

        if(t > 1)
        {
            fac[now] = t;
            exp[now] = 1;
            now++;
        }

        printf("%d\n", go(now, 1, i - y, i));
    }


    return 0;
}