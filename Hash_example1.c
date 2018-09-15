#include <iostream>
#include <cstdio>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct _NODE {	
	int key;
	int counter;
}NODE;
int buf[MAX];
NODE hit[50];
void Initialize(void)
{
	int i;
	for (i = 0; i < MAX; i++)
		buf[i] = -1;
	for (i = 0; i < 20; i++)
	{
		hit[i].key = -1;
		hit[i].counter = 0;
	}
}
void makeRandomNumber(void)
{
	int i, num, idx;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < 50)
	{
		num = rand() % 100;
		buf[num] = num;
		idx = num % 50;
		hit[idx].key = num;
		hit[idx].counter++;

		i++;
	}
}
void displayBuffer(void)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d", buf[i]);
	}
	puts("");
}
void displayHitBuffer(void)
{
	int i;
	printf("====> Hit Key Data <====\n");

	for (i = 0; i < 50; i++)
	{
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d ", hit[i].key);
	}
	puts("");
}
void displayHitCounter(void)
{
	int i;
	printf("====> Hit Counter Data <====\n");
	for (i = 0; i < 50; i++)
	{
		if ((i % 10) == 0)
			printf("\n");
		printf("%4d ", hit[i].counter);
	}
	puts("");
}

int s;
int main()
{
	Initialize();
	makeRandomNumber();
	displayBuffer();
	printf("\n");
	displayHitBuffer();
	displayHitCounter();
	system("pause");
	return 0;
}
