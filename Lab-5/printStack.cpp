#include "printStack.h"

void printStack(FILO* head) {
	printf("--------------\n");
	struct FILO* temp = head;
	while (temp != NULL) {
		printf("%s\n", temp->s);
		temp = temp->next;
	}
	printf("--------------\n");
}