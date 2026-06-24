#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long int ll;

const int SIZE = 1000009;

char s[SIZE];



ll dsum[SIZE];

int dtotal;



ll usum[SIZE];

int utotal;



int main()

{

    int N;

    scanf("%d%s", &N, s + 1);



    for(int i = 1; i <= N; i++)

    {

        if(s[i] == 'U')

        {

            ++utotal;

            usum[utotal] = i + usum[utotal - 1];

        }

        else

        {

            ++dtotal;

            dsum[dtotal] = i + dsum[dtotal - 1];

        }

    }



    int meetd = 0;

    int meetu = 0;

    for(long long int i = 1; i <= N; i++)

    {

        meetd += s[i] == 'D';



        int lu = meetu;

        int rd = dtotal - meetd;

        int mn = min(lu, rd);



        ll ans = (dsum[meetd + mn] - dsum[meetd] - (usum[meetu] - usum[meetu - mn])) * 2;



        if(s[i] == 'U')

        {

            if(lu >= rd)

                ans += N + 1 - i;

            else

                ans += (dsum[meetd + mn + 1] - dsum[meetd + mn] - i) * 2 + i;



        }

        else

        {

            if(rd >= lu)

                ans += i;

            else

                ans += (i - usum[meetu - mn] + usum[meetu - mn - 1]) * 2 + N + 1 - i;

        }

        meetu += s[i] == 'U';

        printf("%lld ", ans);

    }

    printf("\n");





}