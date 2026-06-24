#include<bits/stdc++.h>

using namespace std;



int check[28] = {0};

int prevIndex[28] = {-1};



int main()

{

    char str[50005], leftAlpa[28];

    gets(str);



    int len = strlen(str), index, ss = 0, totQues = 0, alpaLeft = 26, start = 0, j = 0;

    bool yes = false;



    for(int i = 0; i < len; i++)

    {

        if(str[i] != '?')

        {

            index = (int)str[i] - 'A';

            check[index]++;

            if(check[index] == 1) { ss++; alpaLeft--; }

            else {

                totQues = 0;

                start = prevIndex[index] + 1;

                ss = i - start + 1;



                for(int j = 0; j < 27; j++) check[j] = 0; //making all zero...

                for(int j = start; j <= i; j++){



                    if(str[j] == '?') totQues++; // counting ?...

                    else check[(int)str[j] - 'A']++;

                }



                check[index]++; alpaLeft = 25;

            }



            prevIndex[index] = i;

        }

        else

        {

            totQues++;

            ss++;

        }



        if(ss == 26 && totQues <= alpaLeft) { yes = true; break; }

    }



    if(yes && len >= 26)

    {

        int lenth = 0;

        for(int i = 0; i < 26; i++) if(check[i] == 0) leftAlpa[lenth++] = char(65+i);



        int finish = start + 25;

        for(int i = 0; i < len; i++)

        {

            if(str[i] == '?')

            {

                if(i >= start && i <= finish) printf("%c",leftAlpa[j++]);

                else printf("A");

            }

            else printf("%c",str[i]);

        }

        cout<<endl;

    }

    else cout<<-1<<endl;



    return 0;

}