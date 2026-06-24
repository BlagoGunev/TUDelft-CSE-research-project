#include <cstdio>

#include <algorithm>

#include <cstring>



using namespace std;



char str[200100];



int main ()

{

    //freopen ("file.in", "r", stdin);



    gets (str + 1);



    int n = strlen (str + 1);

    for (int i = 2; i <= n; ++i)

    {

        if (str[i] == str[i - 1])

        {

            if (str[i] == 'z') str[i] = 'a';

            else ++str[i];



            if (str[i] == str[i + 1])

                if (str[i] == 'z') str[i] = 'a';

                else ++str[i];

        }

    }



    puts (str + 1);



    return 0;

}