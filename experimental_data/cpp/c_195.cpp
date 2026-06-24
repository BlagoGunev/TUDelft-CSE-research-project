#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#include <string>
#include <numeric>
#include <functional>
#include <iomanip>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

char s[55];
char throwtype[55];
char msg[55];
char tmp[55];
int main()
{
    int n;
    cin>>n;
    getchar();
    int state=0;
    int basestt=-1;
    int lowest=-1;
    bool showed=false;
    for(int i=0; i<n; i++)
    {
        fgets(s, sizeof(s), stdin);
        if(showed)continue;
        //printf("%s\n",s);
        int l=strlen(s);

        for(int j=0; j<l; j++)
        {
            if(s[j]!=' ')
            {
                if(s[j]=='t'&&s[j+1]=='r')
                {
                    state++;
                }
                else if(s[j]=='c')
                {
                    if(lowest==state)
                    {
                        lowest--;
                        int go=0;
                        for(int k=j+5;k<l;k++)
                        {
                            if(s[k]!=' '&&s[k]!='(')
                            {
                                   int v;
                                   for(v=k;s[v]!=' '&&s[v]!=',';v++)
                                   {
                                       tmp[go++]=s[v];
                                   }
                                   tmp[go]='\0';

                                   if(strcmp(tmp,throwtype)==0)
                                   {
                                        //printf("tmp = %s\n",tmp);
                                       for(int u=v;u<l;u++)
                                       {
                                           if(s[u]=='"')
                                           {
                                               //printf("%d\n",u);
                                               go=0;
                                               for(int h=u+1;s[h]!='"';h++)
                                               {
                                                   msg[go++]=s[h];
                                               }
                                               msg[go]='\0';
                                               printf("%s\n",msg);
                                               showed=true;
                                               break;
                                           }
                                       }
                                   }
                                   break;
                            }

                        }
                    }
                    state--;
                }
                else if(s[j]=='t')
                {
                    lowest=state;
                    int go=0;
                    for(int k=j+5; k<l; k++)
                    {
                        if(s[k]!=' '&&s[k]!='(')
                        {
                            for(int v=k;s[v]!=')';v++)
                            {
                                if(s[v]!=' ')
                                {
                                    throwtype[go++]=s[v];
                                }
                            }
                            throwtype[go]='\0';
                            //printf("throw = %s\n",throwtype);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    if(!showed)printf("Unhandled Exception\n");
    return 0;
}