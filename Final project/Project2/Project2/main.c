#include <stdio.h>
#include <math.h>
#include <time.h>

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
#define LIFTRATE 5  // 고도에 따른 시간 비율
#define RATE_NUM 100  // 결과값에 대한 비율

// 각 변수 구조체 정의
typedef struct
{
	int sys;  
	int equ; 
	double res;  
	const double nATM; 
	double nP;  
	double nV;  
	double nH;  
	double nTEM;  
	double nRHO; 
	double nRES; 
	double liftTime;   
}M_Tool;

// 프로그램 설명에 대한 함수 선언
int Print_Explantion(void);

// 방정식 선택 및 종료에 대한 함수 선언
int get_system(void);

// 방정식을 분류하는 데 저장할 변수에 관한 함수 선언
void alititude_Calculate(int eq);

// 고도에 따른 온도 변환 함수 선언
void get_temperature(M_Tool* temp);

void get_rho(M_Tool* temp);

// 고도에 따른 압력 변화 함수 선언
void get_pressure(M_Tool* temp);

// 고도에 도달하는 시간 게산 함수 선언
void get_lift_time(M_Tool* temp);

// 최종결과값 함수 선언
void Output_First_Result(M_Tool* temp);

int main(void)
{
	M_Tool ntool;

	// 제한조건에 대한 설명 출력
	ntool.sys = Print_Explantion();

	// 반복문을 통한 조건에 따른 결과값 출력
	while (1)
	{
		if (ntool.sys == START)
		{
			ntool.equ = get_system();
			
			if (ntool.equ == END)
			{
				printf("Exit the program.\n");
				break;
			}
			alititude_Calculate(ntool.equ);  // 고도입력과 계산하는 함수 호출
		}
		else if (ntool.sys == END)
		{
			printf("Exit the program.\n");
			break;
		}
		else
		{
			printf("Return again\n");  // 다시하기를 출력
		}
	}
	return 0;
}

// 프로그램 설명 대한 함수 정의
int Print_Explantion(void)
{
	M_Tool temp;

	printf("This is a limiting condition.\n");
	printf("First, This is normal flow.\n");
	printf("Sceond, Viscosity effects are ignored.\n");
	printf("Third, Incompressible flow.\n");
	printf("Lastly, it is limited to the altitude at which the aircraft is operated.\n");
	printf("Would you like to start a program to calculate Bernoulli's equation?\n");
	printf("Enter the Stat is (1111) and End is (0000): ");  
	scanf_s("%d", &temp.sys);  

	return temp.sys;
}

// 방정식 선택 및 종료에 대한 함수 정의
int get_system(void)
{
	M_Tool temp;

	printf("\n");
	printf("Enter the view\n");  
	printf("energy is (2222)\n"); 
	printf("pressure is (3333)\n");  
	printf("headis is (4444)\n");  
	printf("End is (0000)\n");  
	printf("Select : "); 
	scanf_s("%d", &temp.equ);  

	return temp.equ;
}

// 방정식을 분류하는 데 저장할 변수에 관한 함수 정의
void alititude_Calculate(int eq)
{
	M_Tool temp[100];

	printf("\n");
	printf("Please enter your alititude(m) : ");  // 고도(높이)를 입력 받음(단위 : m)
	scanf_s("%lf", &temp->nH);  // 고도(높이)에 대한 변수 저장

	// 각 함수를 호출하여 계산
	get_rho(temp);
	get_temperature(temp);
	get_pressure(temp);
	temp->nV = sqrt(2 * G * temp->nH);
	get_lift_time(temp);

	switch (eq)
	{
	case  ENERGY:
	{
		temp->res = (temp->nP / temp->nRHO) + (0.5 * pow(temp->nV, 2)) + (G * temp->nH);  // 에너지 방정식 결과값 계산
	}
	case PRESSURE:
	{
		temp->res = temp->nP + (0.5 * temp->nRHO * pow(temp->nV, 2) + (temp->nRHO * G * temp->nH));  // 압력 방정식 결과값 계산
	}
	case HEAD:
	{
		temp->res = temp->nP / (temp->nRHO * G) + (pow(temp->nV, 2) / (2.0 * G)) + temp->nH;  // 수두 방정식 결과값 계산
	}
	default:
	{
		printf("Return again\n");
	}
	}
	Output_First_Result(temp);  // 최종결과값 함수 호출

	return eq;
}

// 고도에 따른 온도 변환 함수 정의
void get_temperature(M_Tool* temp)
{
	// 고도에 따른 온도 변화 공식
	temp->nTEM = TEM - (temp->nH / NUM_TEN) * (DIM_TEM * NUM_TEN);  
	return temp;
}

// 고도에 따른 밀도 변화 함수 정의
void get_rho(M_Tool* temp)  
{
	// 고도에 밀도 변화 공식
	temp->nRHO = temp->nP / ((R_RHO * temp->nTEM) + CHANGE_K);  
	return temp;
};

// 고도에 따른 압력 변화 함수 정의
void get_pressure(M_Tool* temp)
{
	if (temp < MAX_ALTITUDE || temp >= 0)
	{
		// 고도에 압력 따른 변환 공식
		temp->nP = ATM * pow(1.0 - (temp->nH * DIM_TEM) / (TEM + CHANGE_K), (G * MAIR) / (R_PRE * DIM_TEM));  
		return temp;
	}
	else if (temp >= MAX_ALTITUDE || temp < 0)  // 0km 이하, 13.1km 이상일 경우
	{
		printf("return again\n");  
	}
}

//고도까지 올라가는 시간값 함수 정의
void get_lift_time(M_Tool* temp)
{
	for (int i = 0; i < temp->nH; ++i)
	{
		// 고도까지 올라가는 시간 구하는 공식
		temp->liftTime = (temp->nH - 0) / LIFTRATE;  

		return temp;
	}
}
// 최종결과값 함수 정의
void Output_First_Result(M_Tool* temp)
{
	printf("\n");
	printf("Constants in Bernoulli's equation : %.3lf\n", temp->res);  // 베르누이 방정식 결과값 출력
	printf("Time taken to reach altitude [%.3lf(s)]\n", temp->liftTime);
	printf("\n");
	printf("[ altitude (m) ] | [ Pressure (kPa) ] | [ Density  (kg/m^3) ] | [Temperature ('C)] | [ Speed (m/s) ]\n");

	for (int i = 0; i < temp->nH; i++)
	{
		if (i % 100 == 0)
		{
			printf("[%10.2lf (m)] | [%10.4lf (kPa)] | [%10.4lf (kg/m^3)] | [%10.4lf ('C)] | [%10.4lf (m/s)]\n", 
				(temp->nH / i) * RATE_NUM, (temp->nP / i) * RATE_NUM, (temp->nRHO / i) * RATE_NUM, (temp->nTEM / i) * RATE_NUM, (temp->nV / i) * RATE_NUM);
		}
	}

}