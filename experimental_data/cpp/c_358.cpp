#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> comm,backup;
    string action[3] = {"pushStack","pushQueue","pushBack"};
    for(int i = 0;i < n;i++) {
        int in;
        scanf("%d",&in);
        if(in == 0) {
            // do comm !
            // find the max 3
            backup = comm;
            sort(comm.begin(),comm.end());
            if(comm.size() == 0) printf("0\n");
            else if(comm.size() == 1) {
                // push to stack
                printf("pushStack\n");
                printf("1 popStack\n");
            }
            else if(comm.size() == 2) {
                // push Q ans stack
                printf("pushQueue\n");
                printf("pushStack\n");
                printf("2 popQueue popStack\n");
            }
            else {
                // everything junk just push to front deck
                int comN = 0;
                int cs = comm.size();
                for(int i = 0;i < backup.size();i++) {
                    if(comm.size() == 0 || comN >= 3) {
                    printf("pushFront\n");
                    } else {
                    if(backup[i] == comm[cs-1]) {
                        printf("%s\n",action[comN++].c_str());
                        comm[cs-1] = -1;
                    }
                    else if(backup[i] == comm[cs-2]) {
                        printf("%s\n",action[comN++].c_str());
                        comm[cs-2] = -1;
                    }
                    else if(backup[i] == comm[cs-3]) {
                        printf("%s\n",action[comN++].c_str());
                        comm[cs-3] = -1;
                    }
                    else printf("pushFront\n"); // junk
                    }
                }
                printf("3 popStack popQueue popBack\n");
            }

            //printf("%d",comm[0]);
            comm.clear();
            backup.clear();
        }
        else {
            comm.push_back(in);
        }
    }

    for(int i = 0;i < comm.size();i++) {
        printf("pushStack\n");
    }
}