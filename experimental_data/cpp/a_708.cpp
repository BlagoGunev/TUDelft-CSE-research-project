#include <stdio.h>

#include <string.h>

#define MAXN 100005

using namespace std;

char star[MAXN];

int main()

{

    while(scanf("%s", star) != EOF)

    {

        int len = strlen(star);

        int l = -1, r = -1;

        for(int i = 0; i < len; i++)

        {

            if(star[i] != 'a')

            {

                l = i;

                break;

            }

        }

        if(l == -1)

        {

            star[len - 1] = 'z';

            printf("%s\n", star);

            continue;

        }

        for(r = l; r < len; r++)

        {

            if(star[r] == 'a')

            {

                break;

            }

        }

        for(int i = l; i < r; i++)

        {

            star[i]--;

        }

        printf("%s\n", star);

    }

    return 0;

}