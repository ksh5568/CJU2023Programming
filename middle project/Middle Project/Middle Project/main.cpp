#include <stdio.h>
#include <math.h>

#define START 1111  // 시작에 대한 수 
#define END 0000  // 종료에 대한 수
#define ENERGY 2222  // 에너지 방정식에 대한 수
#define PRESSURE 3333  //  압력 방정식에 대한 수
#define HEAD 4444  // 수두 방정식에 대한 수
#define G 9.81  // 중력가속도에 대한 수(단위 : m/s^2)
#define ATM 101.325  // 대기압에서의 압력(단위 : kPa)
#define TEM 15.00  // 표준대기온도(단위 : 'C)
#define DIM_TEM 0.0065  // 대기에서 온도 감소율 (단위 : K/m)
#define R_RHO 0.287  // 밀도에서 기체상수(단위 : J/(mol/K))
#define R_PRE 8.314  // 압력에서 기체상수(단위 : J/(mol/K))
#define MAIR 0.0289
#define MAX_ALTITUDE 13100  // 항공기 최대 비행 고도(단위 : m)
#define CHANGE_K 273.15  // 켈빈에서 섭씨 혹은 섭씨에서 켈빈으로 변화시키는 수
#define NUM_TEN 10  // '10'에 대한 수

int get_system(void);  // 방정식 선택 및 종료에 대한 함수 설정
double get_alititude(void);  // 고도입력에 대한 함수 설정
double get_temperature(double y);  // 고도에 따른 온도 변화 함수 설정
double get_rho(double x);  // 고도에 따른 밀도 변화 함수 설정
double get_pressure(double n);  // 고도에 따른 압력 변화 함수 설정
double out_result(double a, double b, double c, double d, double e, double f);  // 최종결과값 함수 설정

int main(void)
{
	int sys = 0;  // 시작 혹은 종료에 대해 저장할 변수
	int equ = 0;  // 방정식을 분류하는 데 저장할 변수
	double res = 0.0;  // 베르누이 방정식 결과값을 저장할 변수 
	double nATM = ATM;  // 표준대기압 변수 (단위 : kPa)
	double nP = 0.0;  // 압력을 저장할 변수 (단위 : kPa)
	double nV = 0.0;  // 속도를 저장할 변수(단위 : m/s)
	double nH = 0.0;  // 고도를 저장할 변수 (단위 : m)
	double nTEM = 0.0;  // 온도를 저장할 변수(단위 : K)
	double sum_Pa = 0.0;  // 고도에 따른 압력 변화값 (단위 : kPa)
	double nRHO = 0.0; // 고도에 따른 밀도 변화값 (단위 : kg/m^3)
	double nRES = 0.0; // 최종 결과값 저장할 변수

	printf("This is a limiting condition.\n");  // 제한조건에 대한 설명 출력
	printf("First, This is normal flow.\n");
	printf("Sceond, Viscosity effects are ignored.\n");
	printf("Third, Incompressible flow.\n");
	printf("Would you like to start a program to calculate Bernoulli's equation?\n");
	printf("Enter the Stat is (1111) and End is (0000): ");  // 시작 혹은 종료 할지 입력
	scanf_s("%d", &sys);  // 시작 혹은 종료에 대한 변수에 저장

	while (true)
	{
		if (sys == START) // 시작에 대한 변수일 경우
		{
			equ = get_system();

			if (equ == ENERGY)  // 에너지 방정식에 대한 변수 일 경우
			{
				nH = get_alititude();  // 고도입력에 대한 함수 호출

				nP = get_pressure(nH);  // 압력을 구하기 위한 함수 호출
				nRHO = get_rho(nH);  // 밀도를 구하기 위한 함수 호출
				nTEM = get_temperature(nH);  // 온도를 구하기 위한 함수 호출 후 섭씨 변환
				nV = sqrt(2 * (nATM - nP) / nRHO);  // 베르누이 방정식을 이용한 속도 구하는 공식
				
				res = (nP / nRHO) + (0.5 * pow(nV, 2)) + (G * nH);  // 에너지 방정식 결과값 계산

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // 최종결과값 함수 호출
			}
			else if (equ == PRESSURE)  // 압력 방정식에 대한 변수 일 경우
			{
				nH = get_alititude();  // 고도입력에 대한 함수 호출

				nP = get_pressure(nH);
				nRHO = get_rho(nH);
				nTEM = get_temperature(nH);
				nV = sqrt(2 * (nATM - nP) / nRHO);

				res = nP + (0.5 * nRHO * pow(nV, 2) + (nRHO * G * nH));  // 압력 방정식 결과값 계산

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // 최종결과값 함수 호출
			}
			else if (equ == HEAD)  // 수두 방정식에 대한 변수 일 경우
			{
				nH = get_alititude();  // 고도입력에 대한 함수 호출

				nP = get_pressure(nH);
				nRHO = get_rho(nH);
				nTEM = get_temperature(nH);
				nV = sqrt(2 * (nATM - nP) / nRHO);

				res = nP / (nRHO * G) + (pow(nV, 2) / (2.0 * G)) + nH;  // 수두 방정식 결과값 계산

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // 최종결과값 함수 호출
			}
			else if (equ == END)  // 종료에 대한 변수 일 경우
			{
				printf("Exit the program.\n");  // 프로그램 종료 출력
				break;  // 반복문 탈출
			}
			}
			else if (equ != END || equ != ENERGY || equ != PRESSURE || equ != HEAD)  // 방정식 및 종료를 분류하는 범위에 수가 아닐경우
			{
				printf("Return again\n");  // 다시하기를 출력
			}
		else if (sys == END)
		{
			printf("Exit the program.\n");
			break; 
		}
		else
		{
			printf("Return again\n");  // 다시하기를 출력
			continue;
		}
	}

	return 0;
}

int get_system(void)// 방정식 선택 및 종료에 대한 함수 정의
{
	int temp = 0;  // 사용할 방정식 및 종료에 대한 변수에 저장
	printf("\n");
	printf("Enter the view\n");  // "보기를 보고 입력하세요" 출력
	printf("energy is (2222)\n");  // (2222)번은 에너지 방정식을 출력
	printf("pressure is (3333)\n");  // (3333)번은 압력 방정식을 출력
	printf("headis is (4444)\n");  // (4444)는 수두 방정식을 출력
	printf("End is (0000)\n");  // (0000)은 종료를 출력
	printf("Decide which equation to use : ");  // 어떤 방정식을 사용할건지 출력
	scanf_s("%d", &temp);  // 사용할 방정식 및 종료에 대한 변수에 저장
	return temp;
}

double get_alititude(void)  // 방정식을 분류하는 데 저장할 변수
{
	double temp = 0.0;
	printf("Please enter your alititude(m) : ");  // 고도(높이)를 입력 받음(단위 : m)
	scanf_s("%lf", &temp);  // 고도(높이)에 대한 변수 저장
	return temp;
}

double get_temperature(double y)  // 고도에 따른 온도 변화 함수 정의
{
	double temp = 0.0;  // 압력 결과값에 대한 변수 지정
	temp = TEM - ((y / NUM_TEN) * (DIM_TEM * NUM_TEN));  // 고도에 따른 온도 변화 공식
	return temp;
}	

double get_rho(double x)  // 고도에 따른 밀도 변화 함수 정의
{
	double temp = 0.0;  // 밀도 결과값에 대한 변수 지정
	double temp_P = 0.0;  // 밀도를 계산하기 위한 압력값 지정 
	double temp_T = 0.0;  // 밀도를 계산하기 위한 온도값 지정

	temp_P = get_pressure(x);  // 압력 구하는 함수 호출
	temp_T = get_temperature(x);  // 온도 구하는 함수 호출
	temp = temp_P / (R_RHO * (temp_T + CHANGE_K));  // 고도에 밀도 변화 곻식

	return temp;
}

double get_pressure(double n)  // 고도에 따른 압력 변화 함수 정의
{
	double temp = 0.0;  // 압력 결과값에 대한 변수 지정
	if (n < MAX_ALTITUDE || n >= 0)
	{
		temp = ATM * pow(1.0 - (n * DIM_TEM) / (TEM+CHANGE_K), (G * MAIR) / (R_PRE * DIM_TEM));  // 고도에 압력 변환 공식
		return temp;
	}
	else if (n >= MAX_ALTITUDE || n < 0)  // 0km 이하, 13.1km 이상일 경우
	{
		printf("return again\n");  // 다시하기 출력
		return 0;  
	}
}

double out_result(double a, double b, double c, double d, double e, double f)  // 최종결과값 함수 정의
{

	printf("\n");
	printf("When altitude is %.2lf(m)\n", a);  // "고도가 '00'm일 때" 출력
	printf("Pressure : %.3lf(kPa)\n", b);  // "압력 결과값" 출력
	printf("Density : %.3lf(kg/m^3)\n", c);  // "온도 결과값" 출력
	printf("Temperature : %.3lf('C)\n", d);  // "속도 결과값" 출력
	printf("Speed : %.3lf(m/s)\n", e);  // "밀도 결과값" 출력
	printf("Constants in Bernoulli's height equation : %.2lf\n", f);  // 베르누이 방정식 결과값 출력

	return a, b, c, d, e, f;
}