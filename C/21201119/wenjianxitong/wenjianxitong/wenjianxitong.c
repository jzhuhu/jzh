#if 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch;
	FILE *fp;
	char filename[10];
	errno_t err;
	printf("please inout filename:");
	//scanf_s("%s",filename);
	//getchar();
	err=fopen_s(&fp, filename, "w");

	/*if ((fp = fopen_s("filename", "w")) == NULL)
	{
		printf("cannot open the file \n");
		exit(0);
	}*/
	printf("please input strings ,end of #:");
	ch = getchar();
	while (ch != 'j')
	{
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10);
	return 0;
}
#elif 1
#include<stdio.h>
struct Student
{
	int num;
	float score;
	struct Student *next;
};
int main()
{
	struct Student a, b, c, *p, *head;
	a.num = 100;
	a.score = 98.5;
	b.num = 101;
	b.score = 98.6;
	c.num = 102;
	c.score = 88.6;
	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	p = head;
	do
	{
		printf("%ld\t%5.1lf\n", p->num, p->score);
		p = p->next;
	} while (p != NULL);
	return 0;



}


#endif