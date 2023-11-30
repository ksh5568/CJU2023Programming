#include <stdio.h>

// ������ ��ȯ�ϴ� �Լ� ����
void swap_(const char *i, void *a, void *b)
{
	if (i == "int")  // ������ ���� �κ� ��ȯ
	{
		int a_temp = 0;

		a_temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = a_temp;
	}
	
	if (i == "double")  // �Ǽ��� ���� �κ� ��ȯ
	{
		double b_temp = 0.0;

		b_temp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = b_temp;
	}
}

int main(void)
{
	// �� ������ ���̿� ���� ���� ����
	int *a_age = 0;
	int *b_age = 0;
	double *a_height = 0;
	double *b_height = 0;

	//  �Է¹� ���
	printf("Enter the age and height of the first person : ");
	scanf_s("%d %lf", &a_age, &a_height);
	printf("Enter the age and height of the second person : ");
	scanf_s("%d %lf", &b_age, &b_height);

	//"swap"�Լ��� �̿��Ͽ� ������ ��ȯ
	swap_("int", &a_age, &b_age);
	swap_("double", &a_height, &b_height);
	
	// ����� ���
	printf("\n");
	printf("The age and height of the first person : %d, %.1lf\n", a_age, a_height);
	printf("The age and height of the second person : %d, %.1lf", b_age, b_height);
	printf("\n");

	return 0;
}