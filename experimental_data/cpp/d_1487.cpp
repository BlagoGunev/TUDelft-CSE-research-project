#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int m = sqrt(2*n);
        if(m <= 2)
            printf("0\n");
        else
        {
            int c = (m*m+1)/2;
            while(c>n)
            {
                m--;
                c = (m*m+1)/2;
            }
            if(m%2==0)
            {
                m/=2;
            }
            else
            {
                m++;
                m/=2;
            }
            m--;
            printf("%d\n", m);
        }
    }
    return 0;
}