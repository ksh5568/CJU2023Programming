#include <stdio.h>

int main(void)
{
	double angle = 0.0;  // 각도값 초기화
	double res = 0.0;  // 결과값 초기화
	
	printf("Enter the angle : ");  // 각도값 입력 받기
	scanf_s("%lf", &angle); // 각도값 실수로 입력 

	res = ((int)angle + 180) % 360 - 180;  // +-180도 로변환한 각도값을 결과값에 변환
	printf("Converted posture value : %.2lf\n", res);  // 변환된 각도값을 실수로 출력

	return 0;
}