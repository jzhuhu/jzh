#if(0)
#include<stdio.h>
int main()
{
	void hanio(int n, char one, char two, char three);
	int m;
	printf("请输入盘子的数目：\n");
	scanf_s("%d",&m);
	printf("移动%d个盘子的步骤为：\n", m);
	hanio(m, 'A', 'B', 'C');
	return 0;
}
void hanio(int n, char one, char two, char three)
{
	void move(char x, char y);
	if (n==1)
	{
		move(one, three);
	}
	else
	{
		hanio(n - 1, one, three, two);
		move(one, three);
		hanio(n - 1, two, one, three);
	}
}
void move(char x, char y)
{
	printf("%c-->%c\n", x, y);
}
#endif
#if(0)
#include<stdio.h>
void main()
{
	void test(int v);
	int  a[10] = { 1, 2, 3, 4, -1, -2, -3, -4, 2, 3 };
	int i;
	for ( i = 0; i < 10; i++)
	{
		test(a[i]);
	}
	printf("\n");
}
void test(int v)
{
	if (v>0)
	{
		printf("%d\t", v);
	}
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	void test();
	int a[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	test(a);
	putchar('\n');
	return 0;
}
void test(int  b[10])
{
	int i;
	for ( i = 0; i < 10; i++)
	{
		printf("%d\t", b[i]);
	}
}
#endif
#if(0)
#include<stdio.h>
double average(double array[10]);
void main()
{
	double score[10] = { 82, 100, 87.5, 89, 78, 85, 67.5, 92.5, 93, 94 }, result;
	result = average(score);
	printf("平均成绩是%5.2lf\n", result);
	putchar('\n');

}
double average(double array[10])
{
	double result = 0;
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		result += array[i];
	}
	result /= 10;
	return result;
}
#endif
#if(0)
#include<stdio.h>
int s1, s2, s3;
int main()
{
	int vs();
	int v, l, w, h;
	printf("请输入长、宽、高\n");
	scanf_s("%d%d%d", &l, &w, &h);
	v = vs(l, w, h);
	printf("体积=%d\ts1=%d\ts2=%d\ts3=%d\t", v, s1, s2, s3);
}
int vs(int a, int b, int c)
{
	int v;
	v = a*b*c;
	s1 = a*b;
	s2 = b*c;
	s3 = a*c;
	return v;
}
#endif
//有一个一维数组，内放10个学生的成绩，写一个函数，求平均分、最高分和最低分
#if(0)
#include<stdio.h>
float MAX = 0, MIN = 0;
int main()
{
	float average(float array[], int n);
	float ave, score[10];
	int i;
	for ( i = 0; i < 10; i++)
	{
		scanf_s("%f", &score[i]);
	}
	ave = average(score, 10);
	printf("max=%6.2f\tmin=%6.2f\taverage=%6.2\n", MAX, MIN, ave);
	return 0;
}
float average(float array[], int n)
{
	int i;
	float aver, sum = array[0];
	MAX = MIN = array[0];
	for ( i = 0; i < n; i++)
	{
		if (array[i]>MAX)
		{
			MAX = array[i];
		}
		else if (array[i]<MIN)
		{
			MIN = array[i];
		}
		sum = sum + array[i];
	}
	aver = sum/n;
	return aver;
}
#endif
#include<stdio.h>
int main()
{
	int f();
	int a = 2, i;
	for ( i = 0; i < 3; i++)
	{
		printf("%d\n", f(a));
	}
	return 0;
}
int f(int a)
{
	auto b = 0;
	static int c = 3;
	b = b + 1;
	c = c + 1;
	return (a + b + c);
}
