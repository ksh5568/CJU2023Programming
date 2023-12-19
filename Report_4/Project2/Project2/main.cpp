#include <stdio.h>
#include <math.h>

#define D_NUMBER {-5, 3, 3, -4, 3}

// 구조체 정의
typedef struct
{
	double nX;  // 한점의 x좌표
	double nY;  // 한점의 y좌표
	double nA;  // 2차 방정식의 a값
	double nB;  // 2차 방정식의 b값
	double nC;  // 2차 방정식의 c값

}Num;

// 고등학교 수학과정에서 최단거리 구하는 공식 함수 정의
void Distance_Calculation(Num i_list)
{
	double temp = 0;

	temp = fabs((i_list.nA * i_list.nX) + (i_list.nB * i_list.nY) + i_list.nC) / (sqrt(pow(i_list.nA, 2) + pow(i_list.nB, 2)));
	
	// 첫번째 결과값 출력
	printf("Result_Distance#1 : %.2lf\n", temp);
}

// 백터 내적을 이용한 최단거리 구하는 공식 함수 정의
void Distance_vector(Num i_list)
{
	double n_dot = 0;
	double n_vol = 0;
	double n_res = 0;

	// 2차 방정식에서의 방향 벡터
	double la_vector = - (i_list.nA / i_list.nC);
	double lb_vector = - (i_list.nA / i_list.nB);

	n_dot = (la_vector * i_list.nX) + (lb_vector * i_list.nY);  // 벡터의 내적을 계산
	n_vol = sqrt(pow(la_vector, 2) + pow(lb_vector, 2));  // 벡터의 크기 계산

	n_res = fabs(n_dot) / n_vol;

	// 두번째 결과값 출력
	printf("Result_Distance#2 : %.2lf\n", n_res);
}

int main(void)
{
	Num i_list = D_NUMBER;

	// 프로그램 설명 출력
	printf("This is a program that calculates distance.\n");
	printf("\n");

	// 거리를 계산하는 두가지 방식의 함수 호출
	Distance_Calculation(i_list);
	Distance_vector(i_list);

	return 0;
}
