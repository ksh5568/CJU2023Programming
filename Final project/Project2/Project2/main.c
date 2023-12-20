#include <stdio.h>
#include <math.h>
#include <time.h>

#define START 1111  // ���ۿ� ���� �� 
#define END 0000  // ���ῡ ���� ��
#define ENERGY 2222  // ������ �����Ŀ� ���� ��
#define PRESSURE 3333  //  �з� �����Ŀ� ���� ��
#define HEAD 4444  // ���� �����Ŀ� ���� ��
#define G 9.81  // �߷°��ӵ��� ���� ��(���� : m/s^2)
#define ATM 101.325  // ���п����� �з�(���� : kPa)
#define TEM 15.00  // ǥ�ش��µ�(���� : 'C)
#define DIM_TEM 0.0065  // ��⿡�� �µ� ������ (���� : K/m)
#define R_RHO 0.287  // �е����� ��ü���(���� : J/(mol/K))
#define R_PRE 8.314  // �з¿��� ��ü���(���� : J/(mol/K))
#define MAIR 0.0289
#define MAX_ALTITUDE 13100  // �װ��� �ִ� ���� ��(���� : m)
#define CHANGE_K 273.15  // �̺󿡼� ���� Ȥ�� �������� �̺����� ��ȭ��Ű�� ��
#define NUM_TEN 10  // '10'�� ���� ��
#define LIFTRATE 5  // ���� ���� �ð� ����
#define RATE_NUM 100  // ������� ���� ����

// �� ���� ����ü ����
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

// ���α׷� ���� ���� �Լ� ����
int Print_Explantion(void);

// ������ ���� �� ���ῡ ���� �Լ� ����
int get_system(void);

// �������� �з��ϴ� �� ������ ������ ���� �Լ� ����
void alititude_Calculate(int eq);

// ���� ���� �µ� ��ȯ �Լ� ����
void get_temperature(M_Tool* temp);

void get_rho(M_Tool* temp);

// ���� ���� �з� ��ȭ �Լ� ����
void get_pressure(M_Tool* temp);

// ���� �����ϴ� �ð� �Ի� �Լ� ����
void get_lift_time(M_Tool* temp);

// ��������� �Լ� ����
void Output_First_Result(M_Tool* temp);

int main(void)
{
	M_Tool ntool;

	// �������ǿ� ���� ���� ���
	ntool.sys = Print_Explantion();

	// �ݺ����� ���� ���ǿ� ���� ����� ���
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
			alititude_Calculate(ntool.equ);  // ���Է°� ����ϴ� �Լ� ȣ��
		}
		else if (ntool.sys == END)
		{
			printf("Exit the program.\n");
			break;
		}
		else
		{
			printf("Return again\n");  // �ٽ��ϱ⸦ ���
		}
	}
	return 0;
}

// ���α׷� ���� ���� �Լ� ����
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

// ������ ���� �� ���ῡ ���� �Լ� ����
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

// �������� �з��ϴ� �� ������ ������ ���� �Լ� ����
void alititude_Calculate(int eq)
{
	M_Tool temp[100];

	printf("\n");
	printf("Please enter your alititude(m) : ");  // ��(����)�� �Է� ����(���� : m)
	scanf_s("%lf", &temp->nH);  // ��(����)�� ���� ���� ����

	// �� �Լ��� ȣ���Ͽ� ���
	get_rho(temp);
	get_temperature(temp);
	get_pressure(temp);
	temp->nV = sqrt(2 * G * temp->nH);
	get_lift_time(temp);

	switch (eq)
	{
	case  ENERGY:
	{
		temp->res = (temp->nP / temp->nRHO) + (0.5 * pow(temp->nV, 2)) + (G * temp->nH);  // ������ ������ ����� ���
	}
	case PRESSURE:
	{
		temp->res = temp->nP + (0.5 * temp->nRHO * pow(temp->nV, 2) + (temp->nRHO * G * temp->nH));  // �з� ������ ����� ���
	}
	case HEAD:
	{
		temp->res = temp->nP / (temp->nRHO * G) + (pow(temp->nV, 2) / (2.0 * G)) + temp->nH;  // ���� ������ ����� ���
	}
	default:
	{
		printf("Return again\n");
	}
	}
	Output_First_Result(temp);  // ��������� �Լ� ȣ��

	return eq;
}

// ���� ���� �µ� ��ȯ �Լ� ����
void get_temperature(M_Tool* temp)
{
	// ���� ���� �µ� ��ȭ ����
	temp->nTEM = TEM - (temp->nH / NUM_TEN) * (DIM_TEM * NUM_TEN);  
	return temp;
}

// ���� ���� �е� ��ȭ �Լ� ����
void get_rho(M_Tool* temp)  
{
	// ���� �е� ��ȭ ����
	temp->nRHO = temp->nP / ((R_RHO * temp->nTEM) + CHANGE_K);  
	return temp;
};

// ���� ���� �з� ��ȭ �Լ� ����
void get_pressure(M_Tool* temp)
{
	if (temp < MAX_ALTITUDE || temp >= 0)
	{
		// ���� �з� ���� ��ȯ ����
		temp->nP = ATM * pow(1.0 - (temp->nH * DIM_TEM) / (TEM + CHANGE_K), (G * MAIR) / (R_PRE * DIM_TEM));  
		return temp;
	}
	else if (temp >= MAX_ALTITUDE || temp < 0)  // 0km ����, 13.1km �̻��� ���
	{
		printf("return again\n");  
	}
}

//������ �ö󰡴� �ð��� �Լ� ����
void get_lift_time(M_Tool* temp)
{
	for (int i = 0; i < temp->nH; ++i)
	{
		// ������ �ö󰡴� �ð� ���ϴ� ����
		temp->liftTime = (temp->nH - 0) / LIFTRATE;  

		return temp;
	}
}
// ��������� �Լ� ����
void Output_First_Result(M_Tool* temp)
{
	printf("\n");
	printf("Constants in Bernoulli's equation : %.3lf\n", temp->res);  // �������� ������ ����� ���
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