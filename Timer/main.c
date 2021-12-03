#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {

	while (1) {

		system("cls");
		printf("\t=== Test Program ==\n\n");
		//메뉴 입력 
		int input;
		printf("1.스톱워치\t2.타이머\t3.종료\n\n");
		printf("원하는 메뉴를 입력 하세요 : ");
		scanf_s("%d", &input);

		//메뉴에 따른 제어
		if (input > 0 && input < 4) {
			if (input == 3) break;

			switch (input)
			{
			case 1:
				printf("1번\n");
				system("pause");
				break;
			case 2:
				printf("2번\n");
				system("pause");
				break;
			}
		}
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다.");
			system("pause");

		}

	}

	return 0;
}