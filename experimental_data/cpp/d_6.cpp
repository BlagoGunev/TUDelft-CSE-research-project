#include<bits/stdc++.h>

using namespace std;

long long num[15];

int flag[1000];

long long  n , d1 , d2;

inline long long read()

{

    long long x  = 0;

    int f = 1;

    char ch=getchar();

	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}

	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return x*f;

}



bool dfs(long long  l , long long t , long long last)

{

    if(t == 0)

    {

        int jud = 0;

        for(int i = 1 ; i <= n ; ++i)

        {

            if(num[i] >= 0)

            {

                return 0;

            }

        }

        return 1;

    }

    if(num[l] < 0)

        return dfs(l + 1 , t , last);

    for(int i = min(n - 1 , max(last , l)) ; i <= min(n - 1 , l + 1) ; ++i)

    {

        num[i] -= d1 ;

        num[i - 1] -= d2;

        num[i + 1] -= d2;

        if(dfs(l , t - 1 , i))

        {

            flag[t] = i;

            return 1;

        }

        num[i] += d1;

        num[i - 1] += d2;

        num[i + 1] += d2;

    }

    return 0;

}

int main()

{



    n = read() ; d1 = read() ; d2 =read();

    for(int i = 1 ; i <= n ; ++i)

    {

        num[i] = read();



    }

    for(int i = 1 ; ; ++i)

    {

        memset(flag , 0 ,sizeof(flag));

        if(dfs(1 , i , 2))

        {

            printf("%d\n",i);

            char c;

            for(int j =  1; j <=  i; ++j)

                printf("%d " ,flag[j]);

            putchar('\n');

            return 0;

        }



    }

    return 0;

}