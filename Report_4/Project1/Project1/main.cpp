#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// ������ �� ������ ��ȭ
	int num = 0;
	double* pi;
	double sum = 0.0;
	int i = 0;

	// �Է� ���� �Ǽ��� ���� ��� �� �Է� ���� ���� ����
	printf("Enter the number of real numbers to enter : ");
	scanf_s("%d", &num);

	// ���� ���� �Ҵ�
	pi = (double*)malloc(num * sizeof(double));
	
	// �޸𸮰� ������ ���� ���� ó�� ���� 
	if (pi == NULL)
	{
		printf("There is not enough memory.\n");
		exit(1);
	}

	// �Ǽ� �Է��� ���
	printf("Enter [%d]'s real number : ", num);
	
	// �Է� ���� �Ǽ��� ����
	for (i = 0; i < num; i++)
	{
		scanf_s("%lf", &pi[i]);
		sum += pi[i];
	}

	// ���� ���
	printf("Total : %.3lf\n", sum);
	
	// �Ҵ��� �޸� ���� ��ȯ
	free(pi);

	return 0;
}