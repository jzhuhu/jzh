#if 0
#include<stdio.h>
int strcopy(char *buffer,const char *string)
{
	while (*string!='\0')
	{
		*buffer++ = *string++;
	}
}
int main()
{
	int i;
	char buffread[40]=" ";
	const char string[] = "jzh shi shuai ge";
	strcopy(buffread, string);
	for (i = 0; i < sizeof(buffread);i++)
	{
		if (buffread[i] != '\0')
		{
			printf("%c", buffread[i]);
		}
	}
}
#elif 0
#include<stdio.h>

int main()
{
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("%d", *(*(a + 1) + 1));
}
#elif 0
#include<stdio.h>
#include<string.h>
//const char keyword[ ] = { "do", "for", "it", "register", "return" };
#define N_KEYWORD (sizeof(keyword)/sizeof(keyword[0]))
int lookup_keyword(char const *const desired_word, const char *keyword_table[])
{
	char const **kwp;
	for (kwp = keyword_table; *kwp != NULL; kwp++)
	{
		if (strcmp(desired_word, *kwp) == 0)
		{
			return kwp - keyword_table;
		}
	}
}
int main()
{
	int a;
	//int *api[10];
	//int i;
	//for (i = 0; i < N_KEYWORD; i++)
	//{
	//	*api[10] = &keyword[i];
	//}
	char const *keyword[] = { "do", "for", "it", "register", "return",NULL };
	a = lookup_keyword("it", keyword);
	printf("%d\t", a);
	return 0;
}
#elif 1
#include<stdio.h>
#include<string.h>
//const char keyword[] = { "do", "for", "it", "register", "return" };
#define N_KEYWORD (sizeof(keyword)/sizeof(keyword[0]))
int lookup_keyword(char const *const desired_word, const char *keyword_table[], int const_size)
{
	char const **kwp;
	for (kwp = keyword_table; *kwp!=NULL; kwp++)
	{
		if (strcmp(desired_word, *kwp) == 0)
		{
			return kwp - keyword_table;
		}
	}
}
int main()
{
	int a;

	char const  *keyword[][9] = {"do","for","it","register","return",NULL};
	a = lookup_keyword("it", keyword, 5);
	printf("%d\t", a);
	return 0;
}

#endif