#include <stdio.h>

int main(void)
{
	int inputprice = 0; // 투입한 금액 변수 초기화
	int itemprice = 0;  // 물건값 변수 초기화
	int change = 0;  // 거스름돈 변수 초기화
	int c100 = 0;  // 100원 변수 초기화
	int c500 = 0;  // 500원 변수 초기화
	int c1000 = 0;  // 1000원 변수 초기화

	printf("Enter the amount you put in : ");  // 투입한 금액 입력 받기
	scanf_s("%d", &inputprice);  // 투입한 금액 정수로 입력

	printf("Enter the price of the item : ");  // 물건값 입력 받기
	scanf_s("%d", &itemprice);  // 물건값 정수로 입력

	change = inputprice - itemprice;  // 거스름돈 계산 공식

	c1000 = change / 1000;  // 1000원 계산 공식
	c500 = change / 500;  // 500원 계산 공식
	c100 = change / 100;  // 100원 계산 공식

	printf("change money : %d\n", change);  // 계산된 거스름돈 출력
	printf("change 1000 : %d\n", c1000);  // 계산된 1000원의 개수 출력
	printf("change 500 : %d\n", c500);  // 계산된 500원의 개수 출력
	printf("change 100 : %d\n", c100);  // 계산된 100원의 개수 출력

	return 0;
}