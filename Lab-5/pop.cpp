#include "pop.h"

struct FILO* pop(FILO* head) {
	if (head)
	{
		head = head->next;
		return head;
	}
}