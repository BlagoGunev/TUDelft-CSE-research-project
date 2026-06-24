#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int dat[103];

int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n; i ++) {
		scanf("%d",&dat[i]);
	}
	sort(dat,dat+n);
	int used = 10;
	int ans = 0, penalty = 0;
	for(int i = 0;i < n;i ++){
		if(used + dat[i] <= 360) {
			used += dat[i];
			ans ++;
			penalty += 0;
		} else if(used+dat[i] <= 720) {
			used += dat[i];
			ans ++;
			penalty += used - 360;
		} else {
			break;
		}
	}
	printf("%d %d\n",ans,penalty);
	return 0;
}