
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

int Intinput(int min, int max);
Time_format GetTime(clock_t time);
Time_format SetTime();