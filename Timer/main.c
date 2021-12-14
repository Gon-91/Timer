#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

int main() {
	while (1) {
		//메뉴 입력
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.스톱워치\t2.타이머\t3.종료\n\n");
		printf("원하는 메뉴를 입력 하세요 : ");
		scanf_s("%d", &input);
		//메뉴에 따른 제어
		if (input > 0 && input < 4) {
			if (input == 3) {
				printf("프로그램을 종료 합니다.");
				break;
			}

			switch (input)
			{
			case 1:
				/*
				* 아래 기능을 포함하여 구현 예정
				* 시작 | 기록 | 정지 | 초기화
				*/
				printf("아무키나 누르면 시작 합니다.");
				system("pause");
				clock_t start_time = clock();
				while (1) {
					clock_t curr_time = clock() - start_time;

					//UI개선 하기
					double time_double = (double)curr_time / 1000;
					//printf("%.3lf\n", time_double);

					int trans;
					int undersec;
					int sec;
					int min;
					int hour;

					trans = (int)time_double;
					undersec = curr_time%1000;
					sec = trans % 60;
					min = trans /60%60;
					hour = trans /60/60;

					printf("\n\n\t%d:%d:%d.%d\n\n", hour,min,sec, undersec);
					
					//키 입력을 받았을때 멈추기(일시정지)
					if (_kbhit()) {
						
						printf("1.재시작\t2.초기화\t3.종료\n");
						printf("원하는 기능을 선택 하세요 : ");
						scanf_s("%d", &input);
						//1. 재시작 선택시 스톱워치가 이어서 진행
						if (input == 1) {
							start_time = clock() - curr_time;
							continue;
						}
						//2. 초기화 선택시 스톱워치가 초기화 후 진행
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
				break;

			case 2:
				/*
				* 시간 / 분 / 초를 이용한 타이머 카운팅 시작하게 구현 예정
				* 최대 100시간 ? 
				* 입력을 통해 카운팅 시간 설정 
				* 시작 | 정지 | 초기화 
				*/
				//printf("2번\n");

				//타이머 설정 입력 
				int set_hour;
				int set_min;
				int set_sec;
				printf("시간을 입력해 주세요 : ");
				scanf_s("%d", &set_hour);
				printf("분을 입력해 주세요 : ");
				scanf_s("%d", &set_min);
				printf("초을 입력해 주세요 : ");
				scanf_s("%d", &set_sec);

				printf("아무키나 누르면 타이머가 실행됩니다.\n");
				printf("설정 시간 %d:%d:%d", set_hour, set_min, set_sec);
				system("pause");
				int sec = set_sec;
				int min = set_min;
				int hour = set_hour;
				int act = 0;
				clock_t start_time2 = clock();
				while (1) {
					system("cls");
					clock_t curr_time = clock() - start_time2;

					double time_double = (double)curr_time / 1000;
					int trans;
					int undersec;
					

					trans = (int)time_double;
					if (act == 1){ 
						trans = (int)time_double - set_sec; 
						//printf("작동:");
						//system("pause");

					}

					printf("\n\n\t%d:%d:%d\n\n", hour, min, sec - trans%60);
					if (trans % 60 - sec == 0) {
						min--;
						sec = 59;
						act = 1;
					}
					if (set_min == -1) {
						hour--;
						min = 59;
					}
				}

			}
		}
		//예외 처리
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다.");
			system("pause");
		}
	}
	return 0;
}