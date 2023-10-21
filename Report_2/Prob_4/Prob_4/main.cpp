#include <stdio.h>
#define G 9.81  // 중력가속도 (단위 : m/s^2)
#define H 100.00  // 초기 높이 (단위 : m)
#define KG 1  // 케틀벨 무게 (단위 : kg)

int main(void)
{
	double nTIME = 0.0000;  // 시간에 대한 변수 설정
	double nLAND = 0.0000;  //  지면 대한 변수 설정

	printf("This is a program that calculates free fall motion.\n");  // 자유낙하 운동에 대한 프로그램이라는 것을 출력
	printf("When Youngsu lets a 1kg kettlebell fall freely from a height of 100m,\n");  // 1kg 케틀벨이 100m 높이에서 떨어질 때를 출력
	printf("how long does it take for it to reach the ground?\n");  // 지면에 도달하기까지 걸리는 시간은 얼마인가를 출력

	do
	{
		nLAND = H - 0.5 * G * (nTIME * nTIME);  // 자유낙하운동 공식
		nTIME = nTIME + 0.0001;  // 반복 될때 0.0001s 씩 증가

	} while (nLAND > 0.0);  // 지면보다 높으면 계속하여 연산
	
	printf("\n");
	printf("Time : %.3lf s\n", nTIME);  // 결과값 출력
}
