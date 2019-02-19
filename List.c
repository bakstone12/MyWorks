#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref,int new_data)
{
	struct Node* new_Node = (struct Node*) malloc(sizeof(struct Node));
	new_Node->data = new_data;
	new_Node->next = (*head_ref);
	(*head_ref) = new_Node;
}

void printList(struct Node *node) 
{ 
	int count=0;
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        if(node->data>0)
        	count++;
        node = node->next; 
        
    } 
    printf("Yparxoun %d Thetikoi aritmoi sth lista ",count);
} 

int main()
{
	int i=0,given_number,temp;
	struct Node* head=NULL;
	do{
		do{
			printf("\nGive the 1st number ");
			scanf("%d",&given_number);
			i+=1;
			if(given_number < -10 || given_number > 10)
			{
				printf("Lathos h timi prepei na einai apo [-10,10]");
			}
		}while(given_number <-10 || given_number >10);
		
		push(&head,given_number);
		
		do{
			printf("\nGive the 2nd number: ");
			scanf("%d",&temp);
			i+=1;
			if(temp<(given_number-10) || temp>(given_number+10))
			{
				printf("Lathos h timh prepei na einai apo[%d,%d]",given_number-10,given_number+10);
			}
		}while(temp<(given_number-10) || temp>(given_number+10));
		
		push(&head,temp);
		
		do{
			printf("\nGive the 3rd number: ");
			scanf("%d",&given_number);
			i+=1;
			if(given_number<(temp-10) || given_number>(temp+10))
			{
				printf("Lathos h timi prepei na einai apo [%d,%d]",temp-10,temp+10);
			}
		}while(given_number<(temp-10) || given_number>(temp+10));
		
		push(&head,given_number);
		
	}while(i<3);
	
	printList(head);
}
