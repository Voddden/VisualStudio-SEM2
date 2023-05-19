#include "push.h"

struct FILO* push(FILO* head) {
	struct FILO* temp = (struct FILO*)malloc(sizeof(struct FILO));
	temp->s = (char*)malloc(50);
	printf("Enter str: ");
	gets_s(temp->s, 50);
	temp->next = head;
	return temp;
}