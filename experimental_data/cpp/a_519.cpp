#include <cstdio>

#include <iostream>

#include <cstring>

#include <algorithm>

#include <cmath>



using namespace std;

int sum1,sum2;

char str[20][20];

int main()

{

    while (scanf("%s",str[0])!=EOF)

    {

        for (int i=1;i<8;i++) scanf("%s",str[i]);

        sum1=0;

        sum2=0;

        for (int i=0;i<8;i++)

        {

            int len=strlen(str[i]);

            for (int j=0;j<len;j++)

            {

                if (str[i][j]=='Q') sum1+=9;

                else if (str[i][j]=='B') sum1+=3;

                else if (str[i][j]=='N') sum1+=3;

                else if (str[i][j]=='R') sum1+=5;

                else if (str[i][j]=='P') sum1+=1;

                else if (str[i][j]=='q') sum2+=9;

                else if (str[i][j]=='b') sum2+=3;

                else if (str[i][j]=='n') sum2+=3;

                else if (str[i][j]=='r') sum2+=5;

                else if (str[i][j]=='p') sum2+=1;

            }

        }

        if (sum1==sum2)

        {

            cout<<"Draw"<<endl;

        }

        else if (sum1>sum2)

        {

            cout<<"White"<<endl;

        }

        else cout<<"Black"<<endl;

    }

    return 0;

}