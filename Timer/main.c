#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

// �ð� ���� ����ü
typedef struct Time_format
{
	int total;
	int hour;
	int min;
	int sec;
	int undersec;
}Time_format;



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
// ��� - �ð� ó��
Time_format GetTime(clock_t time) {
	Time_format data;
	double tempd = (double)time / 1000;
	int tempi = (int)tempd;
	data.hour = tempi / 60 / 60;
	data.min = tempi / 60 % 60;
	data.sec = tempi % 60;
	data.undersec = time % 1000;
	return data;
}
Time_format SetTime() {
	Time_format data;
	int set_total = 0;
	system("cls");
	set_total = 0;
	printf("�ð��� �Է��� �ּ��� : ");
	set_total = Intinput(0, INT_MAX) * 60 * 60;
	system("cls");
	printf("���� �Է��� �ּ��� : ");
	set_total += Intinput(0, INT_MAX) * 60;
	system("cls");
	printf("�ʸ� �Է��� �ּ��� : ");
	set_total += Intinput(0, INT_MAX);
	system("cls");
	data = GetTime((clock_t)(set_total * 1000));
	data.total = set_total;
	return data;
}
// ���� - �����ġ �κ�
void StopWatch() {
	printf("===== �����ġ =====\n");
	printf("�ƹ�Ű�� ������ ���� �մϴ�.");
	system("pause");

	Time_format data;
	clock_t start_time = clock();
	while (1) {
		// �ð� ��� �� �ð� ���� ����� 
		clock_t curr_time = clock() - start_time;
		data = GetTime(curr_time);
		//�ð� �������� ���
		printf("\n\n\t%d:%d:%d.%d\n\n", data.hour, data.min, data.sec, data.undersec);

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

	Time_format data;
	//Ÿ�̸� ���� �Է� 
	int input;
	while (1) {

		data = SetTime();

		//�ð� ���� Ȯ��
		printf("���� �ð� %d:%d:%d\n", data.hour, data.min, data.sec);
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
	clock_t start_time = clock();
	while (1) {
		system("cls");
		// 0�ʷ� ����� ���� �ð� - �Ҹ�ð� ���
		clock_t curr_time = clock() - start_time;
		double time_double = (double)curr_time / 1000;
		int curr_sec = (int)time_double;
		int target = data.total - curr_sec;
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
				clock_t stop_time = clock() - (curr_time + start_time);
				start_time += stop_time;
			}

			//�ٽ� ������
			else if (input == 2) {
				while (1) {
					data = SetTime();
					//�ð� ���� Ȯ��
					printf("���� �ð� %d:%d:%d\n", data.hour, data.min, data.sec);
					printf("1. ����\t2. �缳��\n");
					printf("���� �ð��� Ȯ�� �� �ּ���. : ");
					scanf_s("%d", &input);
					if (input == 1) {
						printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� ����˴ϴ�.\n");
						system("pause");
						start_time = clock();
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