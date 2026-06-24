#include <bits/stdc++.h>
using namespace std;

char str[205];
vector<int> ans;

int main(){
    int N;
    scanf("%d", &N);

    int numB = 0;
    int numW = 0;
    scanf(" %s", str);
    for(int i = 0; i < N; i ++){
        if(str[i] == 'B'){
            numB ++;
        }else if(str[i] == 'W'){
            numW ++;
        }
    }

    if(numB%2 == 1 && numW%2 == 1){
        printf("-1");
        return 0;
    }else if(numW == 0 || numB == 0){
        printf("0");
        return 0;
    }

    if(numW%2 == 1){
        swap(numB, numW);
        for(int i = 0; i < N; i ++){
            if(str[i] == 'B'){
                str[i] = 'W';
            }else if(str[i] == 'W'){
                str[i] = 'B';
            }
        }
    }

    for(int i = 0; i < N; i ++){
        int streak = 1;
        char colour = str[0];
        for(int j = 1; j < N; j ++){
            if(str[j] == colour){
                streak ++;
            }else{
                //printf("indx %d ", j);
                if(str[j] == 'B'){
                    if(streak%2 == 1){
                        //printf("%d\n", j);
                        ans.push_back(j);
                        //printf("%s\n", str);
                        swap(str[j], str[j-1]);
                        break;
                    }
                }
                streak = 1;
                colour = str[j];
            }
        }
    }

    while(true){
        bool have = false;
        for(int i = 1; i < N; i ++){
            if(str[i] == 'W' && str[i-1] == 'W'){
                ans.push_back(i);
                str[i] = 'B';
                str[i-1] = 'B';
                numW -= 2;
                have = true;
                //printf("%s\n", str);
            }
        }
        if(!have){break;}
    }

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i ++){
        printf("%d", ans[i]);
        if(i == (int)ans.size()-1){
            printf("\n");
        }else{
            printf(" ");
        }
    }

    return 0;
}