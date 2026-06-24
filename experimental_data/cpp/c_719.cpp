#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>



using namespace std;



int main(){

	

	char a[200005];

	int N,T;

	scanf("%d %d",&N,&T);

	scanf("\n%s",a);

	int st,ed,index;

	for(int i=0;i<N; i++)

		if(a[i]=='.'){

			index = i;

			break;

		}

	st = -1;

	ed = -1;

	for(int i=index+1; i<N; i++)

		if(a[i]>='5'){

			ed = i;

			break;

		}

	for(int i=ed-1; i>index; i--)

		if(a[i]<='3'){

			st = i;

			break;

		}

	if(ed==-1)

		printf("%s\n",a);

	else{

		if(ed==index+1){

			a[index] = '\0';

			int flag=1;

			for(int i=index-1; i>=0; i--){

				a[i] += flag;

				flag = (a[i]-'0')/10;

				a[i] = ((a[i]-'0')%10) + '0';

			}

			if(flag==1)

				printf("1");

			printf("%s\n",a);

			return 0;

		}

		else{ 

			int len;

			if(st==-1){

				len = ed-index;

				if(T>=len){

					a[index] = '\0';

					int flag=1;

					for(int i=index-1; i>=0; i--){

						a[i] += flag;

						flag = (a[i]-'0')/10;

						a[i] = ((a[i]-'0')%10) + '0';

					}

					if(flag==1)

						printf("1");

					printf("%s\n",a);

					return 0;

				}

				else{

					a[ed-T] += 1;

					a[ed-T+1] = '\0';

					printf("%s\n",a);

					return 0;

				}

			}	

			else{

				len = ed-st;

				if(T>=len){

					a[st] += 1;

					a[st+1] = '\0';

					printf("%s\n",a);

					return 0;

				}

				else{

					a[ed-T] += 1;

					a[ed-T+1] = '\0';

					printf("%s\n",a);

					return 0;

				}

			}

		}		

	}

	

	return 0;

}