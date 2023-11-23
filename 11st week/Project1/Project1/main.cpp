#include <stdio.h>
#define ONE 1  // '1'에 대한 수 메크로 정의
#define TEN 10  // '10'에 대한 수 메크로 정의

void swap(double *pa, double *pb);  // 두 실수를 바꾸는 함수 선언
void line_up(double *sor);  // 정렬 시키기 위한 함수 선언

int main(void)
{
	// 각 변수 초기화
	double ary[TEN] = {};  
	int i = 0;
	
	printf("Enter 10 real values : ");  // 10개의 실수 입력

	// 반복문을 통하여 배열에 해당하는 수 저장
	for (i = 0; i < TEN; i++)
	{
		scanf_s("%lf", &ary[i]);
	}

	line_up(ary);  // 두 실수를 바꾸는 함수 호출


	// 결과값 출력
	for (i = 0; i < TEN; i++)
	{
		printf("Output Sorted Values : %.1lf\n", ary[i]);
	}
	
	return 0;
}

void swap(double *pa, double *pb) // 두 실수를 바꾸는 함수 정의
{
	double temp = 0.0;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double *sor)  // 정렬 시키기 위한 함수 정의
{
	int temp = 0;
	int j = 0;
	int k = 0;

	for (j = 0; j < TEN; j++)
	{
		for (k = j; k < TEN; k++)
		{
			if(sor[j]<sor[k])swap(&sor[j], &sor[k]);  // 조건에 부합하면 두 실수를 바꾸는 함수 호출
		}
	}
	
}