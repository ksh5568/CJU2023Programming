#include <stdio.h>
#define PRIME_NUMBER 2

int main(void)
{
	int num = 0;  // �Է� ���� �� ����
	int i = 0;  // �ݺ��� ���� ����
	int j = 0;  // �ݺ��� ���� ����
	int count = 0;  // �ٹٲ��� ���� ī��Ʈ ����

	printf("Enter an integer of 2 or more : ");  // 2�̻��� ���ڸ� �Է��ϼ��� ���
	scanf_s("%d", &num);  // �Է� ���� ���� ����

	if (num < PRIME_NUMBER)  // �Է� ���� ������ 2���� ������
	{
		printf("Please check your number.\n");  // ���ڸ� Ȯ���ϼ��� ���
	}
	else  // �ƴҰ��
	{
		for ( i = 2; i <= num; i++)  // i�� 2�� ���� �� �Է¹��� ���� ��ŭ �ݺ��ϸ鼭 i�� 1�� ����
		{
			for ( j = 2; j <= i; j++)  // j�� 2�� ���� �� i�� ���ų� ���� ������ �ݺ���Ű�鼭 j�� 1�� ����
			{
				if ((i % j) == 0)  // �������� �� ���� 0�ϰ��
				{
					if (i > j)  // i�� j���� Ŭ���
					{
						break;  // ���α׷� ����
					}
					else
					{
							printf("%5d", i);  // i�� 5�� ���
							count++;  // ī��Ʈ ������ 1����
							if (count % 5 == 0)  // ī��Ʈ�� 5�� �������� �� 0�̸�
							{
								printf("\n");  // �ٹٲ� ���
							}
					}
				}
			}

		}
	}
	return 0;
}