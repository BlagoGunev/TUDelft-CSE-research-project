//
//  main.cpp
//  Codeforces
//
//  Created by Francesco on 05/03/14.
//  Copyright (c) 2014 Francesco. All rights reserved.
//

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define gc getchar

int read_int() {
    char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return ret;
}

int mat[1001][1001];
char res[1000001];

int main() {
    int len_res = 0;
    int n = read_int();
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            mat[i][j] = read_int();
        }
    }
    int q = read_int();
    
    int first_res = 0;
    
    for (int j = 1; j<=n; j++) {
        for (int l = 1; l<= n; l++) {
            first_res+= mat[j][l]*mat[l][j];
        }
    }
    
    int tot = 0;
    for (int i = 0; i<q; i++) {
        int v = read_int();
        if (v != 3) {
            read_int();
            tot++;
        } else {
            int partial_res = first_res+tot;
            res[len_res++] = partial_res%2==0?'0':'1';
        }
    }
    
    printf("%s",res);
    
    return 0;
}