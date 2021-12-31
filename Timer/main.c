#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

// ��� - ����ó�� �޴� �Է�
int Intinput(int min, int max) {
	int input;
	while (1) {
		scanf_s("%d", &input);
		if (input >= min && input <= max) {
			return input;
		}
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���. : ");
		}
	}
}
// ���� - �����ġ �κ�
void StopWatch() {
	printf("===== �����ġ =====\n");
	printf("�ƹ�Ű�� ������ ���� �մϴ�.");
	system("pause");


	clock_t start_time = clock();
	while (1) {
		// �ð� ��� �� �ð� ���� �����
		clock_t curr_time = clock() - start_time;
		double time_double = (double)curr_time / 1000;
		int trans;
		int undersec;
		int sec;
		int min;
		int hour;
		trans = (int)time_double;
		undersec = curr_time % 1000;
		sec = trans % 60;
		min = trans / 60 % 60;
		hour = trans / 60 / 60;
		//�ð� �������� ���
		printf("\n\n\t%d:%d:%d.%d\n\n", hour, min, sec, undersec);

		//Ű �Է��� �޾����� ���߱�(�Ͻ�����)
		if (_kbhit()) {

			//�Ͻ����� �� ���� ����
			printf("1.�����\t2.�ʱ�ȭ\t3.����\n");
			printf("���ϴ� ����� ���� �ϼ��� : ");
			int input = Intinput(1, 3);

			//1. ����� ���ý� �����ġ�� �̾ ����
			if (input == 1) {
				start_time = clock() - curr_time;
				continue;
			}
			//2. �ʱ�ȭ ���ý� �����ġ�� �ʱ�ȭ �� ����
			if (input == 2) {
				start_time = clock();
				continue;
			}
			else {
				break;
			}

		}
		system("cls");
	}
	system("pause");
}
// ���� - Ÿ�̸� �κ�
void Timer() {
	//Ÿ�̸� ���� �Է� 
	int set_total = 0;
	int input;
	while (1) {
		system("cls");
		set_total = 0;
		printf("�ð��� �Է��� �ּ��� : ");
		input = Intinput(0, INT_MAX);
		system("cls");
		set_total = input * 60 * 60;
		printf("���� �Է��� �ּ��� : ");
		input = Intinput(0, INT_MAX);
		system("cls");
		set_total += input * 60;
		printf("�ʸ� �Է��� �ּ��� : ");
		input = Intinput(0, INT_MAX);
		system("cls");
		set_total += input;


		//�ð� ���� Ȯ��
		printf("���� �ð� %d:%d:%d\n", set_total / 60 / 60, set_total / 60 % 60, set_total % 60);
		printf("1. ����\t2. �缳��\n");
		printf("���� �ð��� Ȯ�� �� �ּ���. : ");
		input = Intinput(1,2);
		if (input == 1) {
			printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� ����˴ϴ�.\n");
			system("pause");

			break;
		}
		else {
			printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� �ʱ⼳��ȭ������ ���ư��ϴ�.\n");
			system("pause");
		}
	}





	// �ð� ī���� ���� ��
	clock_t start_time2 = clock();
	while (1) {
		system("cls");
		// 0�ʷ� ����� ���� �ð� - �Ҹ�ð� ���
		clock_t curr_time = clock() - start_time2;
		double time_double = (double)curr_time / 1000;
		int curr_sec = (int)time_double;
		int target = set_total - curr_sec;
		printf("\n\n\t%d:%d:%d\n\n", target / 60 / 60, target / 60 % 60, target % 60);

		//Ű�Է½� �Ͻ�����
		if (_kbhit()) {
			system("pause");
			printf("1. �̾��ϱ�\t2. �缳��\t 3. ����\n");
			printf("���� �ð��� Ȯ�� �� �ּ���. : ");
			input = Intinput(1, 3);

			//�̾��ϱ��
			if (input == 1) {
				printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� ����˴ϴ�.\n");
				system("pause");
				clock_t stop_time = clock() - (curr_time + start_time2);
				double stop_time_double = (double)stop_time / 1000;
				int stop_time_sce = (int)stop_time_double;
				set_total = set_total + stop_time_sce;
				start_time2 = clock();
			}

			//�ٽ� ������
			else if (input == 2) {
				while (1) {
					system("cls");
					set_total = 0;
					printf("�ð��� �Է��� �ּ��� : ");
					scanf_s("%d", &input);
					system("cls");
					set_total = input * 60 * 60;
					printf("���� �Է��� �ּ��� : ");
					scanf_s("%d", &input);
					system("cls");
					set_total += input * 60;
					printf("�ʸ� �Է��� �ּ��� : ");
					scanf_s("%d", &input);
					system("cls");
					set_total += input;


					//�ð� ���� Ȯ��
					printf("���� �ð� %d:%d:%d\n", set_total / 60 / 60, set_total / 60 % 60, set_total % 60);
					printf("1. ����\t2. �缳��\n");
					printf("���� �ð��� Ȯ�� �� �ּ���. : ");
					scanf_s("%d", &input);
					if (input == 1) {
						printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� ����˴ϴ�.\n");
						system("pause");
						start_time2 = clock();
						break;
					}
					else {
						printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� �ʱ⼳��ȭ������ ���ư��ϴ�.\n");
						system("pause");
					}
				}
			}
			else {
				break;
			}

		}

		//�ð� �Ҹ�� Ż��
		if (target == 0) {
			printf("�����Ͻ� �ð��� ��� �Ҹ�Ǿ����ϴ�.\n");
			system("pause");
			break;

		}
	}
}
int main() {

	//���α׷� ����
	while (1) {
		//���� ȭ�� �κ�
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.�����ġ\t2.Ÿ�̸�\t3.����\n\n");
		printf("���ϴ� �޴��� �Է� �ϼ��� : ");
		input = Intinput(1, 3);
		//�޴� �Է� �� �����ϱ�
		//�������� �Է��̸�
		if (input > 0 && input < 4) {
			//���� �Է½�
			if (input == 3) {
				printf("���α׷��� ���� �մϴ�.");
				break;
			}
			//�����ġ �Ǵ� Ÿ�̸� �κ�
			switch (input)
			{
			//�����ġ
			case 1:
				StopWatch();
				break;
			//Ÿ�̸�
			case 2:
				Timer();
				break;
			}
		}
		//���� �߻� �� 
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�.");
			system("pause");
		}
	}
	return 0;
}