#include <cstdio>

using namespace std;



int main()
{
    int N, i, c;
    char code[90];

    scanf("%d%s", &N, code);
    if(code[N - 1] == '0')
        code[N++] = '0';

    i = 0;
    while(i < N){
        c = 0;
        if(code[i] == '1'){
            do{
                ++c;
                ++i;
            }
            while(i < N && code[i] == '1');
            printf("%d", c);
        }
        else{
            ++i;
            while(i < N && code[i] == '0')
            {
                ++i;
                printf("0");
            }
        }
    }

    return 0;
}