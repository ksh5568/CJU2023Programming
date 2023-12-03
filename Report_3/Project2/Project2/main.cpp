#include <stdio.h>

// 'Determinant'�� ���ϴ� �Լ� ����
double Determinant(double matrix[2][2])
{
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// ����� ����ϴ� �Լ� ����
void Calculate_Matrix(double matrix[2][2], double inverse[2][2])
{
	double det = Determinant(matrix);

	if (det != 0)
	{
		double indet = 1.0 / det;

		inverse[0][0] = matrix[1][1] * indet;
		inverse[0][1] = -matrix[0][1] * indet;
		inverse[1][0] = -matrix[1][0] * indet;
		inverse[1][1] = matrix[0][0] * indet;
	}
	else  // ������ ������ �ٽ� �Է� �޵��� ����
	{
		printf("Please enter again.\n");
	}
}

int main(void)
{
	// �� ���� �ʱ�ȭ
	double matrix[2][2] = { 0 };
	double inverse[2][2] = { 0 };
	int i = 0, j = 0;

	printf("Enter the 2x2 matrix\n");

	// ��� ���� �°� ���� �Է� �޴� �ݺ��� ���
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Enter the [%d][%d] : ", i, j);
			scanf_s("%lf", &matrix[i][j]);
		}
	}

	// ��� ����ϴ� �Լ� ȣ��
	Calculate_Matrix(matrix, inverse);

	// ����� ���
	printf("\n");
	printf("Result...\n");
	for (i = 0; i < 2; i++)
	{
		printf("|");
		for (j = 0; j < 2; j++)
		{
			printf("%5.2f|", inverse[i][j]);
		}
		printf("\n");
	}
	return 0;
}