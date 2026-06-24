#include <cstdio>
#include <cstring>


using namespace std;

int main() 
{
	char s[100009];
	int n;
	scanf("%d", &n);
	scanf("%s", &s);
	bool f = false;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == s[i - 1] && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'))
		{
			f = true;
			count++;
			continue;
		}
		if (s[i] != s[i - 1] && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'))
		{
			if (s[i - 1] != 'a' && s[i - 1] != 'e' && s[i - 1] != 'i' && s[i - 1] != 'o' && s[i - 1] != 'u' && s[i - 1] != 'y')
			{
				f = true;
				count++;
				continue;
			}
			if ((s[i - 1] == 'o' || s[i - 1] == 'e') && count == 2)
			{
				printf("%c%c", s[i - 1], s[i - 1]);
			}
			else
			{
				printf("%c", s[i - 1]);
			}
			count = 1;
			continue;
		}
		if (f)
		{
			if ((s[i - 1] == 'o' || s[i - 1] == 'e') && count == 2)
			{
				printf("%c%c", s[i - 1], s[i - 1]);
			}
			else
			{
				printf("%c", s[i - 1]);
			}
			f = false;
			count = 0;
		}
		printf("%c", s[i]);
	}
	if (f)
		{
			if ((s[n - 1] == 'o' || s[n - 1] == 'e') && count == 2)
			{
				printf("%c%c", s[n - 1], s[n - 1]);
			}
			else
			{
				printf("%c", s[n - 1]);
			}
			f = false;
			count = 0;
		}
}