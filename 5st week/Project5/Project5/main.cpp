#include <stdio.h>

int main(void)
{
	int year = 0;  // '����⵵' ������ ����
	int month = 0;  // '��' ������ ����
	int day = 0;  // '��' ������ ����
	int res = 0;  // ���� ����� ����� ������ ����

	printf("Enter the birth date : ");  // '����⵵', '��', '��' �Է�
	scanf_s("%d%d%d", &year, &month, &day);  // �� ������ ����

	res = year - month + day;  // ����� ���


	if (res % 10 == 0)  // ������� '10'�� ������ �������� '0'�ΰ�츦 �Ǵ���
	{
		printf("You are very good\n");  // �������� '0'�� ��� 'very goog'���
	} 
	else
	{
		printf("You are so so\n");  // �������� '0'�� �ƴ� ��� 'so so'���
	}

	return 0;
}