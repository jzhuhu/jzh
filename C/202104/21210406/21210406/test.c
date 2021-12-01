//#include <stdio.h>
//int main()//主函数  也就是程序的入口，有且只有一个,int 是整形的意思，main前面的int是表示main函数调用返回一个整形值
//{ 
//	printf("hello jzh\n");//print f=print function-打印函数,这是库函数，也就是C语言本身提供给我们的函数，要想别人打招呼，即#代表指令形式，include包含，stdio.h是文件名<>是语法std-standard标准；i-input；o-output
//	return 0;
//}
////void main()
////{
////	return 0;
////
////}
//#include <stdio.h>
//int main()
//{
//	printf("hehe\n");
//	return 0;
//}
//char ---字符数据类型
//#include <stdio.h>
//int main()
//{
//
//	//char ch = 'A';
//	//printf("%c\n", ch);//%c--打印字符格式的数据；%d--打印整形；%f--打印小数；%p--以地址的形式打印；%x--打印16进制
//	//int age = 20;
//	//printf("%d\n", age);//打印十进制数据
//	//short int--短整型；int--整形；long--长整形；float--
//	/*float f = 5;
//		printf("%f\n", f);*/
//	/*double d = 3.14;
//	printf("%lf\n", d);*/
//	return 0;
//}
#include <stdio.h>
int main()
{
	printf("%d\n", sizeof(char));//sizeof=1,代表着1个字节，bit-byte-kb-mb-gb。计算机是硬件---通电（正点1、负电0，字节--一个字节8个比特位
	
	printf("%d\n", sizeof(short));//sizeof=2
	printf("%d\n", sizeof(int));//sizeof=4
	printf("%d\n", sizeof(long));//sizeof=4/8
	printf("%d\n", sizeof(long long));//sizeof=8
	printf("%d\n", sizeof(float));//sizeof=4
	printf("%d\n", sizeof(double));//sizeof=8
	return 0;
}