#include <cstdio>
#include <cstring>

int main () {
    char s[100005]="", nos[100005]="", notnos[100005]="";
    int nosl, notnosl;
    nosl = notnosl = 0;
	scanf("%s", &s);
	int start = 0;
	int i;
    bool num = true;
    bool blank = true;
	for (i = 0; i<1 || s[i-1]!='\0'; i++) {
        if (s[i] == ',' || s[i] == ';' || s[i] == '\0') {
            if (blank) {
                notnos[notnosl++]=',';
            } else if (num) {
                for (int j = start; j<i; j++) nos[nosl++] = s[j];
                nos[nosl++] =',';
            } else {
                for (int j = start; j<i; j++) notnos[notnosl++] = s[j];
                notnos[notnosl++] =',';
            }
            start = i+1;
            num = true;
            blank = true;
            continue;
        } else if ( !('0' <= s[i] && s[i] <= '9') ) {
            num = false;
        } else if (start == i && s[i] == '0' && ('0' <= s[i+1] && s[i+1] <= '9')) {
            num = false;
        }
        blank = false;
	}
    nos[nosl]='\0';
    notnos[notnosl]='\0';
    if (nos[0] == '\0') {
        printf("-\n");
    } else {
        nos[strlen(nos)-1]='\0';
        printf("\"%s\"\n", nos);
    }
    if (notnos[0] == '\0') {
        printf("-\n");
    } else {
        notnos[strlen(notnos)-1]='\0';
        printf("\"%s\"\n", notnos);
    }
    return 0;
}