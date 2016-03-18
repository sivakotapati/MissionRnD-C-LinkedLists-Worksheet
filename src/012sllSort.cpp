/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};



void sll_012_sort(struct node *head){

	//count0 to count no.of 0's 
	//count1 to count no.of 1's
	//count2 tcount no.of 2's
	int count0 = 0, count1 = 0, count2 = 0, i, j, k;

	struct node *temp;
	temp = head;

	//coutint no.of 0's,1's,2's
	while (temp != NULL){
		if (temp->data == 0){
			++count0;
		}
		else if (temp->data == 1){
			++count1;
		}
		else if (temp->data == 2){
			++count2;
		}
		temp = temp->next;
	}

	//printf("\n%d %d %d\n", count0, count1, count2);
	temp = head;

	//inserting 0's,1's,2's
	i = 1, j = 1, k = 1;
	while (temp != NULL){
		if (i <= count0){//making tem->data as 0
			temp->data = 0;
			temp = temp->next;
			i++;

		}
		else if (j <= count1){//making temp->data as 1
			temp->data = 1;
			temp = temp->next;
			j++;

		}
		else if (k <= count2){//making temp->data as 2
			temp->data = 2;
			temp = temp->next;
			k++;
		}
	}//while
}