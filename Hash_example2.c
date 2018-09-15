#include <iostream>
#include <cstdio>
#include <time.h>
#pragma warning(disable:4996)
using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE 0
#define OVERFLOW 3

typedef struct _NODE {	
	int key[3];
	int counter;
}NODE;
int buf[MAX];
NODE hit[50];
void Initialize(void)
{
	int i, j;
	for (i = 0; i < MAX; i++)
		buf[i] = -1;
	for (i = 0; i < 20; i++)
	{
		for(int j=0;j<3;j++)
			hit[i].key[j] = -1;
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
		if (hit[idx].counter > 2)
			printf("\n OverFlow\n");
		else
			hit[idx].key[hit[idx].counter++] = num;
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
		if ((i % 5) == 0)
			printf("\n");
		//printf("%4d ", hit[i].key);
		switch (hit[i].counter)
		{
		case 0:

		case 1:
			printf("%2d", hit[i].key[0]);
			break;

		case 2:
			printf("%2d/%2d", hit[i].key[0],hit[i].key[1]);
			break;

		case 3:
			printf("%2d/%2d/%2d", hit[i].key[0],hit[i].key[1],hit[i].key[2]);
			break;
		default:
			printf("**");
		}
		printf(", ");
	}
	printf("\n\n");
}
void displayHitCounter(void)
{
	int i;
	printf("====> Hit Counter Data <====\n");
	for (i = 0; i < 50; i++)
	{
		if ((i % 5) == 0)
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
