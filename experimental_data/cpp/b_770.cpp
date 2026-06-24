#include <stdio.h>
using namespace std;

int main()
{
    short n;
    char inp[19]={0};
    scanf("%s",&inp);
    n=0;
    while (inp[n]>47&&inp[n]<58) n++;

    short maxi=-1;
    char out[n];

    for ( short i=n-1; i>=0; i--)
    {
        short summ=0;
        for ( short j = 0; j<n;j++)
        {
            summ += inp[j]-48;
        }

        if(summ>maxi)
        {
            maxi=summ;
             for ( short j = 0; j<n;j++)
            {
                out[j] = inp[j];
            }
        }

        bool B = false;
       while( inp[i] == '0')
       {
            B = true;
             inp[i] = '9';
             i--;
       }
       if(B)
       {
           inp[i] -=1;
           i++;
       }
        if (( i !=0)&&(!B))
        {
                inp[i-1] -=1;
                inp[i] = '9';
        }
    }

    short n0=0;
    while (out[n0] == '0') n0++;

    char out2[n - n0 + 1];
    for ( short i=0; i< n - n0; i++)
        out2[i] =out[i+n0];
    out2[n - n0 ] = '\0';

    printf("%s",out2);

    return 0;
}