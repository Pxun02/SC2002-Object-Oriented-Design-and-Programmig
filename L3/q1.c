#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
	ListNode *tmp1, *tmp2, *newNode;
	tmp1 = head;
	for(int i=0;i<start-1;i++)
		tmp1 = tmp1->next;
	for(int j=0;j<end-1;j++) {
		tmp2 = head;
		for(int i=0;i<end;i++){
			tmp2 = tmp2->next;
		}
		newNode = malloc(sizeof(ListNode));
		newNode->item = tmp2->item;
		newNode->next = tmp1->next;
		tmp1->next = newNode;
		tmp1 = tmp1->next;
	}
	tmp2 = tmp1;
	for(int i=0;i<end;i++){
		tmp2 = tmp2->next;
	}
	tmp1->next = tmp2;
	
	return head;
}