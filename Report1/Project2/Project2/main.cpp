#include <stdio.h>
#define SPRING (3<=a && a <=5) ? printf("spring\n") :  // ���� ���� ���� ��ũ�� ����
#define SUMMER (6<=a && a <=8) ? printf("summer\n") :  // ������ ���� ���� ��ũ�� ����
#define FALL (9<=a && a <=11) ? printf("fall\n") :  // ������ ���� ���� ��ũ�� ����
#define WINTER (12==a || 1<= a && a <=2) ? printf("winter\n") :  // �ܿ￡ ���� ���� ��ũ�� ����
#define WRONG (12 < a) ? printf("This month does not correspond to the four seasons\n") :  // ������� �ش���� �ʴ� �� ������ ���� ��ũ�� ����

int main(void)
{
	int a=0;  // ������� �ԷµǴ� ���� �ʱ�ȭ

	printf("Enter the month : ");  // a�� �Է� �ޱ�
	scanf_s("%d", &a);  // a�� ������ �Է�

	SPRING(a); // a�� �� �ŵ�ο� ���� �� ���
	SUMMER(a);
	FALL(a);
	WINTER(a);
	WRONG(a);

	return 0;

}