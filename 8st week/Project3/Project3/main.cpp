#include <stdio.h>

int rec_func(int n);  // �Լ� ����

int main(void)
{
	int num = 0;  // �Է� ���� �� ���� ����
	int res = 0;  // ����� ���� ����

	printf("Enter the number : ");  // ���ڸ� �Է��ϼ��� ���
	scanf_s("%d", &num);  // ���ڸ� �Է� ���� ���� ����
	
	res = rec_func(num);  // �Լ�ȣ��, ��ȯ�� res ����

	printf("res : %d\n", res);  // ��ȯ�� res �� ���

	return 0;
}

int rec_func(int num)  // �Լ� ���� ����
{
	if (num < 1) return 0;  // �Է¹��� ������ 0������ ��� ��ȯ
	return (num + rec_func(num - 1));  // ������ ���ϴ� ����
}