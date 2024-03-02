#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct student {
	char name[SIZE];
	char number[SIZE];
	struct std* link;
} std;

void freeNode(std* list) {
	std * pa = list;
	while (pa) {
		list = list->link;
		free(pa);
		pa = list;
	}
}

int main() {
	std* list = NULL, * prev = NULL, * p = NULL;
	char buffer[SIZE], strin[SIZE];
	int input;
	
	while (1) {
		printf("(1) refresh (2) add num (3) find num (4) all output (5) exit\n");
		printf("do: ");
		scanf("%d", &input);
		if (input == 5) {
			freeNode(list);
			break;
		}
		if (input == 1) {
			freeNode(list);
			list = NULL;
			printf("Sucess free node and refresh!\n");
		}
		if (input == 2) {
			printf("name: ");
			scanf("%s", &buffer);
			p = (std*)malloc(sizeof(std));
			strcpy(p->name, buffer);
			printf("number: ");
			scanf("%s", &buffer);
			strcpy(p->number, buffer);

			p->link = NULL;
			if (!list) list = p;
			else prev->link = p;
			prev = p;
		}
		if (input == 3) {
			int count = 0;
			printf("name: ");
			scanf("%s", &strin);
			p = list;
			while (p) {
				if (strcmp(strin, p->name) == 0) {
					printf("number: %s\n", p->number);
					count = 1;
				}
				p = p->link;
				if (count == 1) break;
			}
			if (count == 0) printf("Not found\n");
		}
		if (input == 4) {
			p = list;
			while (p) {
				printf("[%s, %s] -> ", p->name, p->number);
				p = p->link;
			}
			printf("NULL\n");
		}
	}

	return 0;
}