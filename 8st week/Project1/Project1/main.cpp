#include <stdio.h>

int get_operation(int x, int y);  // 사친연산 함수 선언

int main(void)
{
	int nA = 0;  // 첫번째수 변수 지정
	int nB = 0;  // 두번째수 변수 지정
	int res = 0;  // 변환값을 저장할 변수 지정

	res = get_operation(nA, nB);

	return 0;
}

int get_operation(int x, int y)  // get_operation 함수 정의 시작
{
	printf("Enter the two number : ");  // "두 수를 입력하세요" 출력 
	scanf_s("%d%d", &x, &y);  // "입력 받은 두 변수를 저장"

	printf("Plus : %d\n", x + y);  // 더하기 출력
	printf("Subtraction : %d\n", x - y);  // 빼기 출력
	printf("Multiplication : %d\n", x * y);  // 곱하기 출력
	printf("Divide : %d\n", x / y);  // 나누기 몫 출력
	printf("Remaider : %d\n", x % y);  // 나누기 나머지 출력

	return 0;  // 결과값 반환
}
