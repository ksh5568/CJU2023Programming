#include <stdio.h>
#define ONE 1.0
#define TWO 2

// 'Determinant'를 구하는 함수 정의
double Determinant(double matrix[2][2])
{
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// 행렬을 계산하는 함수 정의
void Calculate_Matrix(double matrix[2][2], double inverse[2][2])
{
	double det = Determinant(matrix);

	if (det != 0)
	{
		double indet = ONE / det;

		inverse[0][0] = matrix[1][1] * indet;
		inverse[0][1] = -matrix[0][1] * indet;
		inverse[1][0] = -matrix[1][0] * indet;
		inverse[1][1] = matrix[0][0] * indet;
	}
	else  // 오류가 있을시 다시 입력 받도록 설정
	{
		printf("Please enter again.\n");
	}
}

int main(void)
{
	// 각 변수 초기화
	double matrix[2][2] = { 0 };
	double inverse[2][2] = { 0 };
	int i = 0, j = 0;

	printf("Enter the 2x2 matrix\n");

	// 행과 열에 맞게 수를 입력 받는 반복문 출력
	for (i = 0; i < TWO; i++)
	{
		for (j = 0; j < TWO; j++)
		{
			printf("Enter the [%d][%d] : ", i, j);
			scanf_s("%lf", &matrix[i][j]);
		}
	}

	// 행렬 계산하는 함수 호출
	Calculate_Matrix(matrix, inverse);

	// 결과값 출력
	printf("\n");
	printf("Result...\n");
	for (i = 0; i < TWO; i++)
	{
		printf("|");
		for (j = 0; j < TWO; j++)
		{
			printf("%5.2f|", inverse[i][j]);
		}
		printf("\n");
	}
	return 0;
}
