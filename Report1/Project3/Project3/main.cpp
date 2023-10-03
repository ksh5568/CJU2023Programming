#include <stdio.h>
// 윤년 계산하는 공식 메크로 설정
#define LEAP ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0) ? printf("It's a leap year\n") : printf("It's not leap year\n");

int main(void)
{
	int year = 0; // 년도값 초기화

	printf("Enter the year : ");  // 년도값 입력 받기
	scanf_s("%d", &year);  // 년도값 정수로 입력

	LEAP(year);  // 윤년 메클로 불러오기

	return 0;
}