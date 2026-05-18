#include "CLinkedList.h"

LinkedList* createLinkedList() {
	LinkedList* li = (LinkedList*)malloc(sizeof(LinkedList));

	li->head = NULL;
	li->size = 0;

	return li;
}

LinkedList* insertFirstLinkedList(LinkedList* li, int item) {
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->data = item;
	
	if (li->head == NULL) {
		ptr->next = ptr;
		ptr->prev = ptr;
		li->head = ptr;
	}
	else {
		Node* fptr = li->head->prev;

		ptr->next = li->head;
		ptr->prev = fptr;

		fptr->next = ptr;
		li->head->prev = ptr;

		li->head = ptr;
	}

	li->size++;

	return li;
}
LinkedList* insertLastLinkedList(LinkedList* li, int item) {
	Node* nptr = (Node*)malloc(sizeof(Node));
	nptr->data = item;

	if (li->head == NULL) {
		nptr->next = nptr;
		nptr->prev = nptr;
		li->head = nptr;
	}
	else {
		Node* fptr = li->head->prev;
        
		nptr->next = li->head;
		nptr->prev = fptr;
		
		fptr->next = nptr;
		li->head->prev = nptr;
	}

	li->size++;

	return li;
}
LinkedList* insertAtLinkedList(LinkedList* li, int at, int item) {
	if (at < 0 || at > li->size) {
		return li;
	}

	if (at == 0) {
		return insertFirstLinkedList(li, item);
	}

	if (at == li->size) {
		return insertLastLinkedList(li, item);
	}

	Node* nptr = (Node*)malloc(sizeof(Node));
	nptr->data = item;

	Node* fptr = li->head;

	for (int i = 0; i < at - 1; i++) {
		fptr = fptr->next;
	}

	nptr->next = fptr->next;
	nptr->prev = fptr;

	fptr->next->prev = nptr;
	fptr->next = nptr;

	li->size++;

	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at < 0 || at >= li->size) {
		printf("Invalid index.\n");
		return li;
	}

	Node* fptr = li->head;

	for (int i = 0; i < at; i++) {
		fptr = fptr->next;
	}

	printf("Deleted value: %d\n", fptr->data);

	if (li->size == 1) {
		li->head = NULL;
	}
	else {
		fptr->prev->next = fptr->next;
		fptr->next->prev = fptr->prev;

		if (at == 0) {
			li->head = fptr->next;
		}
	}

	free(fptr);
	li->size--;

	return li;
}
void printLinkedList(LinkedList* li) {
	Node* nptr = li->head;

	printf("List: ");

	if (li == NULL || li->head == NULL) {
		printf("empty\n");
		return;
	}

	for (int i = 0; i < li->size; i++) {
		printf("%d ", nptr->data);
		nptr = nptr->next;
	}

	printf("\n");
}
int sizeLinkedList(LinkedList* li) {
	return li->size;
}
void destroyLinkedList(LinkedList* li) {
	if (li == NULL) {
		return;
	}

	Node* nptr, * mptr;
	for (int i = 0; i < li->size; i++) {
		mptr = nptr->next;
		free(nptr);
		nptr = mptr;
	}

	free(li);
}