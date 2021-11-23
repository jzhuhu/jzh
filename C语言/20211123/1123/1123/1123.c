#if 0
#include<stdio.h>
#include<stddef.h>
size_t strlen(char const *string)
{
	int length;
	for (length = 0; *string++ != '\0';)
	{
		length++;
	}
	return length;
}
int main()
{
	
	printf("%d", strlen("jiaxiaoxiao666\r\n"));
	return 0;
}
#elif 0
#include<stdio.h>
#include<string.h>
int main()
{
	char message[] = "jiaxiaoxiaoshishuaige\r\n";
	strcpy_s(message, sizeof("jzh66") / sizeof(char), "jzh66");
	printf("%s", message);
	return 0;

}
#elif 0
#include <stdio.h>
#include <string.h>
int main(){
	char dest[50] = { 0 };
	char src[50] = { "jzh66" };
	strcpy_s(dest, sizeof(src) / sizeof(char),src);
	puts(dest);
	return 0;
}
#elif 0
#include<stdio.h>
#include<string.h>
int main()
{
	char message[30] = "jzh";
	strcpy_s(message,20,"jzh");
	
	strcat_s(message,20, " shi");
	
	strcat_s(message,20, " shuai ge");
	printf("%s", message);
	printf("%d", sizeof(char));
	return 0;
}
#elif 0
#include<stdio.h>
#include<string.h>
int main()
{
	int a;
	char message[] = "jzh";
	char message2[] = "jzhss";
	a=strcmp(message, message2);
	printf("%d", a);
	return 0;
}
#elif 0
#include<stdio.h>
#include<string.h>
int main()
{
	char *a;
	char message[] = "jzh shi shuai ge!";
	a=strchr(message, 'h');
	printf("a=%c\r\n",*a);
	printf("%x\n",a);
	a = strrchr(message, 'o');
	printf("a=%c\r\n", *a);
	printf("%x", a);
	return 0;
}
#elif 0
#include<stdio.h>
#include<string.h>
int main()
{
	char *a;
	char message1[] = "jzh shi shuai ge!";
	char message2[] = "shi";
	a = strstr(message1, message2);
	printf("a=%c\r\n", *a);
	printf("%x", a);
	return 0;
}
#elif 0
#include<ctype.h>
#include<stdio.h>
int main()
{
	printf("%c", toupper('a'));
	putchar(10);
	printf("%c", tolower('A'));


}
#elif 1
#include<ctype.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10] = "jzh66";
	//memset(&a[3],'0',5);
	//memset(&a[3], 0, 5);
	memset(a, '0', 5);
	puts(a);



}
#endif