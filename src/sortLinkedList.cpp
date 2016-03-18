/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node *, struct node *);
struct node * sortLinkedList(struct node *head) {
	struct node *min, *i, *j;
	int t;

	if (head == NULL) return NULL;

	//selection sort
	for (i = head; i->next != NULL; i = i->next){
		min = i;
		for (j = i->next; j!= NULL; j = j->next){
			if ((j->num) < (min->num)){
				min = j;
			}
		} // inner for loop
		
		if (min != i){
			swap(min, i);
		}
	}//outer for loop
	
	return head;
}
void swap(struct node *a, struct node *b){
	int t;
	t = a->num;
	a->num = b->num;
	b->num = t;

}