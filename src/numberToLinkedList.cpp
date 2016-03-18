/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>


struct node * insertAtBegin(struct node *, int);
struct node {
	int num;
	struct node *next;
};


struct node * numberToLinkedList(int N) {
	struct node *head = NULL;
	int rem = 0;

	if (N < 0){
		N = -1 * N;//if N is negative make N positive
	}

	//if number is zero
	if (N == 0){
		head = insertAtBegin(head, N);
		return head;
	}
	//getting invidual digits
	while (N != 0){
		rem = N % 10;
		N = N / 10;
		head = insertAtBegin(head, rem);
	}

	return head;
}
struct node *insertAtBegin(struct node *h, int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	if (h == NULL){
		//if head is null
		h = temp;
		h->num = n;
		h->next = NULL;
	}
	else{
		//head is not null then make temp as head
		temp->num = n;
		temp->next = h;
		h = temp;
	}
	return h;
}

