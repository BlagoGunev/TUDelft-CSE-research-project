#include <cstdio>

inline void print( int i )
{
	if( i == 0 )
		printf("F\n");
	if( i == 1 )
		printf("M\n");
	if( i == 2 )
		printf("S\n");
}

int main()
{
	int i,a[5] = {0},b[5] = {0};
	char str[10] = {'\0'};
	
	for( i = 0 ; i < 3 ; ++i )
		{
			scanf("%s",str);
			if( str[0] == 'r' )
				++a[0], b[0] = i;
			if( str[0] == 's' )
				++a[1], b[1] = i;
			if( str[0] == 'p' )
				++a[2], b[2] = i;
		}
	if( a[0] == 1 && a[1] == 2 )
		print(b[0]);
	else if( a[1] == 1 && a[2] == 2 )
		print(b[1]);
	else if( a[2] == 1 && a[0] == 2 )
		print(b[2]);
	else printf("?\n");

	return(0);
}