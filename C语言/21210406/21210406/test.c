//#include <stdio.h>
//int main()//������  Ҳ���ǳ������ڣ�����ֻ��һ��,int �����ε���˼��mainǰ���int�Ǳ�ʾmain�������÷���һ������ֵ
//{ 
//	printf("hello jzh\n");//print f=print function-��ӡ����,���ǿ⺯����Ҳ����C���Ա����ṩ�����ǵĺ�����Ҫ����˴��к�����#����ָ����ʽ��include������stdio.h���ļ���<>���﷨std-standard��׼��i-input��o-output
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
//char ---�ַ���������
//#include <stdio.h>
//int main()
//{
//
//	//char ch = 'A';
//	//printf("%c\n", ch);//%c--��ӡ�ַ���ʽ�����ݣ�%d--��ӡ���Σ�%f--��ӡС����%p--�Ե�ַ����ʽ��ӡ��%x--��ӡ16����
//	//int age = 20;
//	//printf("%d\n", age);//��ӡʮ��������
//	//short int--�����ͣ�int--���Σ�long--�����Σ�float--
//	/*float f = 5;
//		printf("%f\n", f);*/
//	/*double d = 3.14;
//	printf("%lf\n", d);*/
//	return 0;
//}
#include <stdio.h>
int main()
{
	printf("%d\n", sizeof(char));//sizeof=1,������1���ֽڣ�bit-byte-kb-mb-gb���������Ӳ��---ͨ�磨����1������0���ֽ�--һ���ֽ�8������λ
	
	printf("%d\n", sizeof(short));//sizeof=2
	printf("%d\n", sizeof(int));//sizeof=4
	printf("%d\n", sizeof(long));//sizeof=4/8
	printf("%d\n", sizeof(long long));//sizeof=8
	printf("%d\n", sizeof(float));//sizeof=4
	printf("%d\n", sizeof(double));//sizeof=8
	return 0;
}