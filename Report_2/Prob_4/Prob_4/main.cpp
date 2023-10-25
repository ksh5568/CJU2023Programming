#include <stdio.h>
#define G 9.81  // 중력가속도 메크로 설정 (단위 : m/s^2)
#define H 100.00  // 초기 높이 메크로 설정 (단위 : m)
#define KG 1  // 케틀벨 무게 메크로 설정 (단위 : kg)

int main(void)
{
	double nTIME = 0.0000;  // 시간에 대한 변수
	double nLAND = 0.0000;  // 지면에 대한 변수 설정

	printf("This is a program that calculates free fall motion.\n");  // "자유낙하 운동을 계산하는 프로그램입니다." 출력
	printf("When Youngsu lets a 1kg kettlebell fall freely from a height of 100m,\n");  // "영수가 1kg의 케틀벨을 100m 높이에서 자유롭게 떨어뜨렸을 때" 출력
	printf("how long does it take for it to reach the ground?\n");  // "지면에 도달하긱까지의 걸리는 시간은?" 출력

	do
	{
		nLAND = H - 0.5 * G * (nTIME * nTIME);  // 자유낙하운동 공시
		nTIME = nTIME + 0.0001;  // 0,0001s씩 증가

	} while (nLAND > 0.0);  // 지면보다 높으면 계속하여 반복

	printf("\n");
	printf("Time : %.3lf s\n", nTIME);  // 계산된 시간 출력
}
