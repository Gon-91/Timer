#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {
	while (1) {
		//�޴� �Է�
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.�����ġ\t2.Ÿ�̸�\t3.����\n\n");
		printf("���ϴ� �޴��� �Է� �ϼ��� : ");
		scanf_s("%d", &input);

		//�޴��� ���� ����
		if (input > 0 && input < 4) {
			if (input == 3) {
				printf("���α׷��� ���� �մϴ�.");
				break;
			}
			switch (input)
			{
			case 1:
				/*
				* �Ʒ� ����� �����Ͽ� ���� ����
				* ���� | ��� | ���� | �ʱ�ȭ
				*/
				printf("1��\n");
				system("pause");
				break;
			case 2:
				/*
				* �ð� / �� / �ʸ� �̿��� Ÿ�̸� ī���� �����ϰ� ���� ����
				* �ִ� 100�ð� ? 
				* �Է��� ���� ī���� �ð� ���� 
				* ���� | ���� | �ʱ�ȭ 
				*/
				printf("2��\n");
				system("pause");
				break;
			}
		}
		//���� ó��
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�.");
			system("pause");
		}
	}
	return 0;
}