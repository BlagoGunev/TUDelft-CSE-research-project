#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

string strings[10500];
bool used[10500];
list<int> lists[11];
vector<string> results;

int main()
{
    int n;
    char d;
    char buffer[128];
    int s = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", buffer);
        strings[i] = string(buffer);
        s += strings[i].length();
    }
    int need = s / (n / 2);
    fgets(buffer, sizeof(buffer), stdin);
    scanf("%c", &d);
    sort(strings, strings + n);
    for(int i = 0; i < n; ++i)
    {
        lists[strings[i].length()].push_back(i);
    }
    //printf("==========\n");
    for(int i = 0; i < n; ++i)
    {
        if( used[i] )
        {
            continue;
        }
        string s0 = strings[i];
        string s1;
        if( need - s0.length() == s0.length() )
        {
            s1 = strings[*(++lists[need - s0.length()].begin())];
            used[*(++lists[need - s0.length()].begin())] = true;
        }
        else
        {
            s1 = strings[(lists[need - s0.length()].front())];
            used[(lists[need - s0.length()].front())] = true;
        }
        used[i] = true;
        string result0 = s0 + d + s1;
        string result1 = s1 + d + s0;
        if( result0 < result1 )
        {
            results.push_back(result0);
            //printf("%s\n", result0.c_str());
        }
        else
        {
            results.push_back(result1);
            //printf("%s\n", result1.c_str());
        }
        lists[s0.length()].pop_front();
        lists[s1.length()].pop_front();
    }
    sort(results.begin(), results.end());
    for(unsigned i = 0; i < results.size(); ++i)
    {
        printf("%s\n", results[i].c_str());
    }
    return 0;
}