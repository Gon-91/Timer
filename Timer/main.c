#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {

	while (1) {

		system("cls");
		printf("\t=== Test Program ==\n\n");
		//�޴� �Է� 
		int input;
		printf("1.�����ġ\t2.Ÿ�̸�\t3.����\n\n");
		printf("���ϴ� �޴��� �Է� �ϼ��� : ");
		scanf_s("%d", &input);

		//�޴��� ���� ����
		if (input > 0 && input < 4) {
			if (input == 3) break;

			switch (input)
			{
			case 1:
				printf("1��\n");
				system("pause");
				break;
			case 2:
				printf("2��\n");
				system("pause");
				break;
			}
		}
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�.");
			system("pause");

		}

	}

	return 0;
}