#include <stdio.h>


int main(void)
{
	int a = 0;  // 첫번쨰 수 저장할 변수
	int b = 0;  // 두번쨰 수 저장할 변수
	int res = 0;  // 결과값 저장할 변수
	char symbol;  // 연산기호 결정해서 저장할 변수

	printf("Enter the basic operations : ");  // 사칙연사 입력
	scanf_s("%d", &a);  // 첫번째 수 저장
	scanf_s("%c", &symbol);  // 두번째 수 저장
	scanf_s("%d", &b);  // 연산기호 저장

	switch (symbol)
	{
	case '+':   // 연산기호가 더하기 일 때 수식 계산
		res = a + b;
		break;

	case '-':   // 연산기호가 빼기 일 때 수식 계산
		res = a - b;
		break;

	case '*':   // 연산기호가 곱하기 일 때 수식 계산
		res = a * b;
		break;

	default:  // 그 외 나머지는 나누기로 수식 계산
		res = a / b;
		break;
	}

	printf("%d%c%d=%d\n", a, symbol, b, res);  // if문을 통해 입력 받은 변수들 수식에 맞게 출력

	return 0;
}