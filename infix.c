#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct node* create();
void push(int, struct node*);
int pop(struct node*);
int prec(int ch);
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head;
	char exp[100];
	int ch,ch2,j,i=0;
	head=(struct node *)malloc(sizeof(struct node *));
	printf("ENTER THE INFIX EXPRESSION:\n");
	scanf("%s",exp);
	push('(',head);
	j=strlen(exp);
	exp[j++]=')';
	//printf("%s",exp);
	for(i=0;i<j;i++)
	{
		ch=exp[i];
		switch(prec(ch))
		{
			case 1: push(ch,head);
					break;
			case 2: ch2=pop(head);
					while(ch2!='(')
					{
						printf("%c",ch2);
						ch2=pop(head);
					}
					break;
			case 3: ch2=pop(head);
					while(prec(ch2)>3)
					{
						printf("%c",ch2);
						ch2=pop(head);
					}
					push(ch2,head);
					push(ch,head);
					break;
			case 4: push(ch,head);
					break;
			default: printf("%c",ch);
		}
	}
	printf("\n");
	getch();
}
int prec(int ch)
{
	switch(ch)
	{
		case '(' : return 1;
		case ')' : return 2;
		case '+' : 
		case '-' : return 3;
		case '*' :
		case '/' :
		case '%' : return 4;
		default:return 0;
	}
}		
void push(int new_data, struct node* ptr)
{	
	struct node *newptr;
	newptr = (struct node*)malloc(sizeof(struct node*));
	newptr->data = new_data;
	ptr->data = ptr->data+1;
	//ptr = ptr->next;
	newptr->next = ptr->next;
	ptr->next = newptr;
}
int pop(struct node *ptr)
{
	int z;
	struct node* temp_ptr;
	ptr->data = ptr->data - 1;
	z=(ptr->next)->data;
	temp_ptr = ptr->next;
	ptr->next = (ptr->next)->next;
	free(temp_ptr);
	return z;
}
