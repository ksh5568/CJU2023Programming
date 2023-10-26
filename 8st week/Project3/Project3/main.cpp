#include <stdio.h>

int rec_func(int n);  // 함수 선언

int main(void)
{
	int num = 0;  // 입력 받을 수 변수 지정
	int res = 0;  // 결과값 변수 지정

	printf("Enter the number : ");  // 숫자를 입력하세요 출력
	scanf_s("%d", &num);  // 숫자를 입력 받은 변수 저장
	
	res = rec_func(num);  // 함수호출, 반환값 res 저장

	printf("res : %d\n", res);  // 반환된 res 값 출력

	return 0;
}

int rec_func(int num)  // 함수 정의 시작
{
	if (num < 1) return 0;  // 입력받은 변수가 0이하일 경우 반환
	return (num + rec_func(num - 1));  // 총합을 구하는 공식
}