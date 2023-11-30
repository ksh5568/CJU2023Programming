#include <stdio.h>

// 프로필 교환하는 함수 정의
void swap_(const char *i, void *a, void *b)
{
	if (i == "int")  // 정수인 나이 부분 교환
	{
		int a_temp = 0;

		a_temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = a_temp;
	}
	
	if (i == "double")  // 실수인 나이 부분 교환
	{
		double b_temp = 0.0;

		b_temp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = b_temp;
	}
}

int main(void)
{
	// 각 프로필 나이와 신장 변수 정의
	int *a_age = 0;
	int *b_age = 0;
	double *a_height = 0;
	double *b_height = 0;

	//  입력문 출력
	printf("Enter the age and height of the first person : ");
	scanf_s("%d %lf", &a_age, &a_height);
	printf("Enter the age and height of the second person : ");
	scanf_s("%d %lf", &b_age, &b_height);

	//"swap"함수를 이용하여 프로필 변환
	swap_("int", &a_age, &b_age);
	swap_("double", &a_height, &b_height);
	
	// 결과값 출력
	printf("\n");
	printf("The age and height of the first person : %d, %.1lf\n", a_age, a_height);
	printf("The age and height of the second person : %d, %.1lf", b_age, b_height);
	printf("\n");

	return 0;
}