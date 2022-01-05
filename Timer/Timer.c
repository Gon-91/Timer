#include "Utility.h"


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
		input = Intinput(1, 2);
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