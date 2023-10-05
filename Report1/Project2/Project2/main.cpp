#include <stdio.h>
#define SPRING (3<=a && a <=5) ? printf("spring\n") :  // 봄에 대한 범위 메크로 설정
#define SUMMER (6<=a && a <=8) ? printf("summer\n") :  // 여름에 대한 범위 메크로 설정
#define FALL (9<=a && a <=11) ? printf("fall\n") :  // 가을에 대한 범위 메크로 설정
#define WINTER (12==a || 1<= a && a <=2) ? printf("winter\n") :  // 겨울에 대한 범위 메크로 설정
#define WRONG (12 < a) ? printf("This month does not correspond to the four seasons\n") :  // 사계절에 해당되지 않는 수 오류에 대한 메크로 설정

int main(void)
{
	int a=0;  // 사계절이 입력되는 변수 초기화

	printf("Enter the month : ");  // a값 입력 받기
	scanf_s("%d", &a);  // a값 정수로 입력

	SPRING(a); // a값 각 매크로에 대입 및 출력
	SUMMER(a);
	FALL(a);
	WINTER(a);
	WRONG(a);

	return 0;

}
