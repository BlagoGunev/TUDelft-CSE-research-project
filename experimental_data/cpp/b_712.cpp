#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>



using namespace std;



const int MAX = 100010;



char s[MAX];

int a[5];



int main(){

    while (scanf("%s", s) != EOF){



        memset(a, 0, sizeof(a));

        int len = strlen(s);



        if (len % 2){

            printf("-1\n");

            continue;

        }



        for (int i=0; i<len; i++){

            if (s[i] == 'U'){

                a[0]++;

            }

            if (s[i] == 'D'){

                a[1]++;

            }

            if (s[i] == 'L'){

                a[2]++;

            }

            if (s[i] == 'R'){

                a[3]++;

            }

        }



        int low1 = abs(a[0] - a[1]);

        int low2 = abs(a[2] - a[3]);



        printf("%d\n", (low1+low2) / 2);

    }

    return 0;

}