#include <stdio.h>

int main(void)
{
	int chest = 95;  // �����ѷ��� ũ�⸦ ������ ����
	char size;  // ���� ����� �����ؼ� ������ ����

	if (chest <= 90)  // 'S'����� ���� ���� ����
	{
		size = 'S';
	}
	else if ((chest > 90) && (chest <= 100))  // 'M'����� ���� ���� ����
	{
		size = 'M';
	}
	else  // �� �̻��� ������� 'L'�� ���
	{
		size = 'L';
	}

	printf("SIZE : '%C'\n", size);  // if���� ���� ����ũ���� ������ �´� ������ ���

	return 0;

}