#include <stdio.h>
#include <math.h>
#define TEN 10.0

int main(void)
{
	double num = 0.0;  // 입력 받을수 변수 지정
	double num_a = 0.0;  // 입력 받은수에 제곱근을 입력할 변수 지정
	double sum = 0.0;  // 총합 변수 지정
	double avg = 0.0;  // 평균값 변수 지정
	double dis = 0.0;  // 분산에 대한 변수 지정
	double std = 0.0;  // 표준편차에 대한 변수 지정
	int i = 0;  // 반복하는 수 변수 지정

	printf("Enter the 10 number :\n");  // 10개의 숫자를 입력하세요
	for(i=0; i<TEN; i++)  // i가 10까지 반복하면서 1씩 증가는 함
	{
		scanf_s("%lf", &num);  // 입력 받은수를 저장
		sum += num;  // 총합을 구하는 공식
		num_a += pow(num, 2);  // 입력 받은 수의 제곱근을 다른 변수에 저장
	}

	avg = sum / TEN;  // 평균값 계산

	dis = (num_a + 10*pow(avg, 2) - (2 * avg * sum)) / 10;  // 분산 구하는 공식

	std = sqrt(dis);  // 표준편차 구하는 공식

	printf("Sum : %.2lf\n", sum);  //총합값 출력
	printf("avg : %.2lf\n", avg);  // 평균값 출력
	printf("Dispersion : %.2lf\n", dis);  // 분산값 출력
	printf("StdDispersoin : %.2lf\n", std);  // 표준편차값 출력

}
