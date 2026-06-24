#include<set>

#include<map>

#include<list>

#include<queue>

#include<stack>

#include<string>

#include<math.h>

#include<time.h>

#include<vector>

#include<bitset>

#include<memory>

#include<utility>

#include<fstream>

#include<stdio.h>

#include<sstream>

#include<iostream>

#include<stdlib.h>

#include<string.h>

#include<algorithm>

using namespace std;

char a[10005];

int main()

{

    #ifdef absi2011

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    #endif

    scanf("%s",a);

    int i;

    for (i=2;a[i]!='\0';i++)

    {

        if ((a[i]-'A') != ((a[i-2]-'A') + (a[i-1]-'A'))%26)

        {

            puts("NO");

            return 0;

        }

    }

    puts("YES");

    return 0;

}