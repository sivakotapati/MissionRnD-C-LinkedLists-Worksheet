/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int linkedListLength(struct node * );
	
struct node * removeEveryKthNode(struct node *head, int K) {
	//returns head after removing every Kth node,NULL for invalid K

	if (head == NULL || K <= 0)//checking for invalid inputs
		return NULL;

	int count = 1, len = 0;
	len = linkedListLength(head);

	if (K > len)
		return head;

	struct node *prev, *curr;
	prev = head;
	curr = head;

	while (head != NULL&&curr != NULL){
		if (K == 1){
			//deleting kth i.e 1st element
			head = head->next;
		}
		else{
			if (count == K){
				//deleting Kth element
				prev->next = curr->next;
				count = 0;
			}
			prev = curr;
			curr = curr->next;
			count++;
		}

	}
	return head;
}
int linkedListLength(struct node * h){
	//returns length of linkedlist
	int i = 0;

	while (h != NULL){
		++i;
		h = h->next;
	}
	return i;
}