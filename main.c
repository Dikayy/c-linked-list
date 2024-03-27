#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* nextNode;
} tNode;

tNode* createNode(int value) {
	tNode* nodePtr = malloc(sizeof(tNode));
	nodePtr->value = value;
	nodePtr->nextNode = NULL;

	return nodePtr;
}

void push(tNode* list, int value) {
	tNode* ptr = list;
	while(ptr->nextNode != NULL) {
		ptr = ptr->nextNode;
	}
	ptr->nextNode = createNode(value);
}

void insertBefore(tNode* list, int pos, int value) {
	tNode* cur = list;
	for(int i = 0; i < pos - 1; i++) {
		cur = cur->nextNode;
	}
	tNode* newNode = createNode(value);
	newNode->nextNode = cur->nextNode;
	cur->nextNode = newNode;
}

void delete(tNode* list, int pos) {
	tNode *cur = list;
	for(int i = 0; i < pos - 1; i++) {
		cur = cur->nextNode;
	}
	tNode* delNode = cur->nextNode;
	cur->nextNode = delNode->nextNode;
	free(delNode);
}

void printList(tNode* list) {
	tNode* ptr = list;
	printf("List: ");
	while(ptr != NULL) {
		printf("%d", ptr->value);
		if(ptr->nextNode != NULL)
			printf(" -> ");
		ptr = ptr->nextNode;
	}
	printf("\n");
}

int main() {
	tNode* list = createNode(1);
	for(int i = 2; i <= 15; i++) {
		push(list, i);
	}
	printList(list);

	insertBefore(list, 4, 45);
	printList(list);
	
	delete(list, 7);
	printList(list);

	return 0;
}

