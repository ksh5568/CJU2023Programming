#include <stdio.h>
#define SIX 6  // '6'�� ���� ���� ��Ŭ�� ����

void input_nums(int* lotto_nums)  // �ζ� ��ȣ�� �Է��ϴ� �Լ� ����
{
	// �� ���� �ʱ�ȭ
	int i = 0;
	int j = 0;

	for (i = 0; i < SIX; i++)
	{
		printf("Enter the number : ");
		scanf_s("%d", &lotto_nums[i]);

		if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				// ���� ���� ��� "���� ��"��� ��� �� "i"����
				if (lotto_nums[i] == lotto_nums[j])   
				{
					printf("Same numer\n");
					i--;
					break;
				}
			}
		}
	}
}

void print_nums(int* lotto_nums)  // ����� ���� ����ϴ� �Լ� ����
{
	int i = 0;

	printf("lotto numer : ");
	for (i = 0; i < SIX; i++)
	{
		printf("%5d", lotto_nums[i]);
	}
	printf("\n");
}

int main(void)
{
	int lotto_nums[6];  // �ζ� ��ȣ�� ������ �迭

	input_nums(lotto_nums);  // �Է� �Լ� ȣ��
	print_nums(lotto_nums);  // ��� �Լ� ȣ��

	return 0;
}