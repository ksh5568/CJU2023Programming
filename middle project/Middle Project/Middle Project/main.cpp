#include <stdio.h>
#include <math.h>

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

int get_system(void);  // ������ ���� �� ���ῡ ���� �Լ� ����
double get_alititude(void);  // ���Է¿� ���� �Լ� ����
double get_temperature(double y);  // ���� ���� �µ� ��ȭ �Լ� ����
double get_rho(double x);  // ���� ���� �е� ��ȭ �Լ� ����
double get_pressure(double n);  // ���� ���� �з� ��ȭ �Լ� ����
double out_result(double a, double b, double c, double d, double e, double f);  // ��������� �Լ� ����

int main(void)
{
	int sys = 0;  // ���� Ȥ�� ���ῡ ���� ������ ����
	int equ = 0;  // �������� �з��ϴ� �� ������ ����
	double res = 0.0;  // �������� ������ ������� ������ ���� 
	double nATM = ATM;  // ǥ�ش��� ���� (���� : kPa)
	double nP = 0.0;  // �з��� ������ ���� (���� : kPa)
	double nV = 0.0;  // �ӵ��� ������ ����(���� : m/s)
	double nH = 0.0;  // ���� ������ ���� (���� : m)
	double nTEM = 0.0;  // �µ��� ������ ����(���� : K)
	double sum_Pa = 0.0;  // ���� ���� �з� ��ȭ�� (���� : kPa)
	double nRHO = 0.0; // ���� ���� �е� ��ȭ�� (���� : kg/m^3)
	double nRES = 0.0; // ���� ����� ������ ����

	printf("This is a limiting condition.\n");  // �������ǿ� ���� ���� ���
	printf("First, This is normal flow.\n");
	printf("Sceond, Viscosity effects are ignored.\n");
	printf("Third, Incompressible flow.\n");
	printf("Would you like to start a program to calculate Bernoulli's equation?\n");
	printf("Enter the Stat is (1111) and End is (0000): ");  // ���� Ȥ�� ���� ���� �Է�
	scanf_s("%d", &sys);  // ���� Ȥ�� ���ῡ ���� ������ ����

	while (true)
	{
		if (sys == START) // ���ۿ� ���� ������ ���
		{
			equ = get_system();

			if (equ == ENERGY)  // ������ �����Ŀ� ���� ���� �� ���
			{
				nH = get_alititude();  // ���Է¿� ���� �Լ� ȣ��

				nP = get_pressure(nH);  // �з��� ���ϱ� ���� �Լ� ȣ��
				nRHO = get_rho(nH);  // �е��� ���ϱ� ���� �Լ� ȣ��
				nTEM = get_temperature(nH);  // �µ��� ���ϱ� ���� �Լ� ȣ�� �� ���� ��ȯ
				nV = sqrt(2 * (nATM - nP) / nRHO);  // �������� �������� �̿��� �ӵ� ���ϴ� ����
				
				res = (nP / nRHO) + (0.5 * pow(nV, 2)) + (G * nH);  // ������ ������ ����� ���

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // ��������� �Լ� ȣ��
			}
			else if (equ == PRESSURE)  // �з� �����Ŀ� ���� ���� �� ���
			{
				nH = get_alititude();  // ���Է¿� ���� �Լ� ȣ��

				nP = get_pressure(nH);
				nRHO = get_rho(nH);
				nTEM = get_temperature(nH);
				nV = sqrt(2 * (nATM - nP) / nRHO);

				res = nP + (0.5 * nRHO * pow(nV, 2) + (nRHO * G * nH));  // �з� ������ ����� ���

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // ��������� �Լ� ȣ��
			}
			else if (equ == HEAD)  // ���� �����Ŀ� ���� ���� �� ���
			{
				nH = get_alititude();  // ���Է¿� ���� �Լ� ȣ��

				nP = get_pressure(nH);
				nRHO = get_rho(nH);
				nTEM = get_temperature(nH);
				nV = sqrt(2 * (nATM - nP) / nRHO);

				res = nP / (nRHO * G) + (pow(nV, 2) / (2.0 * G)) + nH;  // ���� ������ ����� ���

				nRES = out_result(nH, nP, nRHO, nTEM, nV, res);  // ��������� �Լ� ȣ��
			}
			else if (equ == END)  // ���ῡ ���� ���� �� ���
			{
				printf("Exit the program.\n");  // ���α׷� ���� ���
				break;  // �ݺ��� Ż��
			}
			}
			else if (equ != END || equ != ENERGY || equ != PRESSURE || equ != HEAD)  // ������ �� ���Ḧ �з��ϴ� ������ ���� �ƴҰ��
			{
				printf("Return again\n");  // �ٽ��ϱ⸦ ���
			}
		else if (sys == END)
		{
			printf("Exit the program.\n");
			break; 
		}
		else
		{
			printf("Return again\n");  // �ٽ��ϱ⸦ ���
			continue;
		}
	}

	return 0;
}

int get_system(void)// ������ ���� �� ���ῡ ���� �Լ� ����
{
	int temp = 0;  // ����� ������ �� ���ῡ ���� ������ ����
	printf("\n");
	printf("Enter the view\n");  // "���⸦ ���� �Է��ϼ���" ���
	printf("energy is (2222)\n");  // (2222)���� ������ �������� ���
	printf("pressure is (3333)\n");  // (3333)���� �з� �������� ���
	printf("headis is (4444)\n");  // (4444)�� ���� �������� ���
	printf("End is (0000)\n");  // (0000)�� ���Ḧ ���
	printf("Decide which equation to use : ");  // � �������� ����Ұ��� ���
	scanf_s("%d", &temp);  // ����� ������ �� ���ῡ ���� ������ ����
	return temp;
}

double get_alititude(void)  // �������� �з��ϴ� �� ������ ����
{
	double temp = 0.0;
	printf("Please enter your alititude(m) : ");  // ��(����)�� �Է� ����(���� : m)
	scanf_s("%lf", &temp);  // ��(����)�� ���� ���� ����
	return temp;
}

double get_temperature(double y)  // ���� ���� �µ� ��ȭ �Լ� ����
{
	double temp = 0.0;  // �з� ������� ���� ���� ����
	temp = TEM - ((y / NUM_TEN) * (DIM_TEM * NUM_TEN));  // ���� ���� �µ� ��ȭ ����
	return temp;
}	

double get_rho(double x)  // ���� ���� �е� ��ȭ �Լ� ����
{
	double temp = 0.0;  // �е� ������� ���� ���� ����
	double temp_P = 0.0;  // �е��� ����ϱ� ���� �з°� ���� 
	double temp_T = 0.0;  // �е��� ����ϱ� ���� �µ��� ����

	temp_P = get_pressure(x);  // �з� ���ϴ� �Լ� ȣ��
	temp_T = get_temperature(x);  // �µ� ���ϴ� �Լ� ȣ��
	temp = temp_P / (R_RHO * (temp_T + CHANGE_K));  // ���� �е� ��ȭ ���

	return temp;
}

double get_pressure(double n)  // ���� ���� �з� ��ȭ �Լ� ����
{
	double temp = 0.0;  // �з� ������� ���� ���� ����
	if (n < MAX_ALTITUDE || n >= 0)
	{
		temp = ATM * pow(1.0 - (n * DIM_TEM) / (TEM+CHANGE_K), (G * MAIR) / (R_PRE * DIM_TEM));  // ���� �з� ��ȯ ����
		return temp;
	}
	else if (n >= MAX_ALTITUDE || n < 0)  // 0km ����, 13.1km �̻��� ���
	{
		printf("return again\n");  // �ٽ��ϱ� ���
		return 0;  
	}
}

double out_result(double a, double b, double c, double d, double e, double f)  // ��������� �Լ� ����
{

	printf("\n");
	printf("When altitude is %.2lf(m)\n", a);  // "���� '00'm�� ��" ���
	printf("Pressure : %.3lf(kPa)\n", b);  // "�з� �����" ���
	printf("Density : %.3lf(kg/m^3)\n", c);  // "�µ� �����" ���
	printf("Temperature : %.3lf('C)\n", d);  // "�ӵ� �����" ���
	printf("Speed : %.3lf(m/s)\n", e);  // "�е� �����" ���
	printf("Constants in Bernoulli's height equation : %.2lf\n", f);  // �������� ������ ����� ���

	return a, b, c, d, e, f;
}