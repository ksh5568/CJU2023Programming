#include <stdio.h>
// ���� ����ϴ� ���� ��ũ�� ����
#define LEAP ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0) ? printf("It's a leap year\n") : printf("It's not leap year\n");

int main(void)
{
	int year = 0; // �⵵�� �ʱ�ȭ

	printf("Enter the year : ");  // �⵵�� �Է� �ޱ�
	scanf_s("%d", &year);  // �⵵�� ������ �Է�

	LEAP(year);  // ���� ��Ŭ�� �ҷ�����

	return 0;
}