//
//  main.cpp
//  Pasha and String
//
//  Created by 서승현 on 2015. 3. 27..
//  Copyright (c) 2015년 서승현. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

char s[200005];
bool a[100005];

int main(int argc, const char * argv[])
{
    int m;
    scanf("%s %d", s + 1, &m);
    
    while(m--)
    {
        int i; scanf("%d", &i);
        a[i] = !a[i];
    }
    
    for(int i = 1, j = strlen(s + 1);i <= j;++i, --j)
    {
        if(a[i]) std::swap(s[i], s[j]);
        a[i + 1] ^= a[i];
    }
    printf("%s", s + 1);
    
    return 0;
}