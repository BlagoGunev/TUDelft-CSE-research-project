#include<iostream>

#include<string>

#include<stdio.h>

using namespace std;

string a, b;

int i, j;

int cha[26],chb[26];

int main()

{

    cin >> a >> b;

    if (a.length()<b.length())

        printf("need tree\n");

    else

    {

        i = 0, j = 0;

        while (i < a.length() && j < b.length())

        {

            ++cha[a[i] - 'a'];

            if (a[i] == b[j])++j;

            ++i;

        }

        if (j == b.length())

           printf("automaton\n");

        else

        {

            i = 0;

            while (i < b.length())++chb[b[i++] - 'a'];

            i = 0;

            while (i < 26)

            {

                if (cha[i] < chb[i++])break;

            }

            if (i == 26)

            {

                if (a.length() == b.length())printf("array\n");

                else printf("both\n");

            }

            else printf("need tree\n");

        }

    }

    return 0;

}