#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 각변수 및 포인터 촉화
	int num = 0;
	double* pi;
	double sum = 0.0;
	int i = 0;

	// 입력 받을 실수의 개수 출력 및 입력 받은 변수 저장
	printf("Enter the number of real numbers to enter : ");
	scanf_s("%d", &num);

	// 저장 공간 할당
	pi = (double*)malloc(num * sizeof(double));
	
	// 메모리가 부족할 때의 예외 처리 구문 
	if (pi == NULL)
	{
		printf("There is not enough memory.\n");
		exit(1);
	}

	// 실수 입력을 출력
	printf("Enter [%d]'s real number : ", num);
	
	// 입력 받은 실수의 총합
	for (i = 0; i < num; i++)
	{
		scanf_s("%lf", &pi[i]);
		sum += pi[i];
	}

	// 총합 출력
	printf("Total : %.3lf\n", sum);
	
	// 할당한 메모리 영역 반환
	free(pi);

	return 0;
}