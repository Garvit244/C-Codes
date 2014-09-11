/*make the BST and perform operation on it
name: Garvit Bansal
Roll no: Y11UC092 */

#include<stdio.h>
#include<stdlib.h>
struct tree_node
{
	int data;
	struct tree_node* lson;
	struct tree_node* rson;
};
struct node
{
	int data;
	struct tree_node* ptr;
	struct node* next;
};
struct tree_node* create_node()
{
	struct tree_node* temp=(struct tree_node*)malloc(sizeof(struct tree_node));
	temp->lson=NULL;
	temp->rson=NULL;
	return (temp); 
}
struct tree_node* create_root()
{
	struct tree_node* root=create_node();
	root->data=0;
	return (root);
}

struct node* create_header()
{
	struct node* header=(struct node*)malloc(sizeof(struct node));
	header->data=0;
	header->ptr=NULL;
	header->next=NULL;
	return (header);
}
struct tree_node* search(struct tree_node* root,int info)
{
	if(root==NULL)
		return NULL;
	else if(root->data==info)
		return (root);
	else if((root->data)>info)
		return (search((root->lson),info));
	else	
		return (search((root->rson),info));
	
}

struct tree_node* insert(struct tree_node* root,int dta)
{
	struct tree_node* temp;
	struct tree_node* tmp=(struct tree_node*)malloc(sizeof(struct tree_node));
	tmp->data=dta;
	tmp->lson=NULL;
	tmp->rson=NULL;
	while (root != NULL) {
      	if ((root->data) == dta)  
		    break;
		if ((root->data) > dta)	
		{	
			temp=root;
		    root = root->lson;
		}
		else	
		{
			temp=root;                   	
		    root=root->rson;
		}
      } 

	if((temp->data)>dta)
	{
		if((temp->lson)==NULL)
			temp->lson=tmp;
		else
			temp=temp->lson;
		
	}
	
	else
	{
		if((temp->rson)==NULL)
			temp->rson=tmp;
		else
			temp=temp->rson;
	}	
	return (root);
}

struct tree_node* insert_a_node(struct tree_node* root,int data)
{
	struct tree_node *curr,*parent;
	curr=root;
	parent=NULL;
	while(curr!=NULL)
	{
		if((curr->data)==data)
		{
			printf("The node already exist");
			return (NULL);
		}
		if ((curr->data)>data) 
	 	{
		 	parent=curr;  
		 	curr= curr->lson;
	 	} 
		else 
		{
			parent= curr;  
			curr= curr->rson;
		} 
	} 
	struct tree_node* tmp=(struct tree_node*)malloc(sizeof(struct tree_node));
	tmp->data=data;
	tmp->lson=NULL;
	tmp->rson=NULL;
	if((parent->data)>data)
		parent->lson=tmp;
	else
		parent->rson=tmp;
		
	return (root);
	
}

struct tree_node* del(struct tree_node* root,int data)
{
	struct tree_node *curr,*parent;
	curr=root;
	parent=NULL;
	while(curr!=NULL)
	{
		if((curr->data)==data)
			break;
		if ((curr->data)>data) 
	 	{
		 	parent=curr;  
		 	curr= curr->lson;
	 	} 
		else 
		{
			parent= curr;  
			curr= curr->rson;
		} 
	} 
	
	////////////////////////////////////////////////////////////////////////////	
      if(curr == NULL)
      	{
	    	printf("The given node does not exist");
			return (NULL);  	
      	}
      	if(((curr->lson)==NULL) &&	((curr->rson)==NULL))
      	{
      		if(parent!=NULL)
      		{
	      		if((parent->data)>data)
	      			parent->lson=NULL;
      			else
      				parent->rson=NULL;
	      	}
	      	free(curr);
	      	if(parent!=NULL)
	      		return (root);
      		else
      			return (NULL);
      	}
 		if(((curr->lson)!=NULL) &&	((curr->rson)==NULL))
	    {
 			if(parent!=NULL)
      		{
	      		if((parent->data)>data)
	      			parent->lson=curr->lson;
      			else
      				parent->rson=curr->lson;
	      	}
			else
				root=curr->lson;
			free(curr);
			return(root);		
		}     
			if(((curr->lson)==NULL) &&	((curr->rson)!=NULL))
	   		 {
 			if(parent!=NULL)
      		{
	      		if((parent->data)>data)
	      			parent->lson=curr->rson;
      			else
      				parent->rson=curr->rson;
	      	}
			else
				root=curr->rson;
			free(curr);
			return(root);		
			} 
}

void display(struct tree_node* root,int c)
{
	int i;
	c+=2;
	printf("%d",root->data);
	if(root->lson == NULL && root->rson == NULL)
		return;
	else
		printf("-->");
	if(root->lson != NULL)
	{
			printf("\n");
			for(i=0;i<c;i++)
				printf("\t");	
			printf("left_son->");
			display(root->lson,c);
	}	
		if(root->rson != NULL)
	{
			printf("\n");
			for(i=0;i<c;i++)
				printf("\t");	
			printf("right_son->");
			display(root->rson,c);
	}		
}

main()
{
		struct tree_node* root=create_root();
		int i,val;
		while(1)
	{
		printf("\n-------MENU--------\n");
		printf("1. Search in the BST\n");
		printf("2. Insert in the BST\n");
		printf("3. Insert_a_node in the BST\n");
		printf("4. Delete a node in the BST\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice...");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
					printf("Enter the value to be searched:");
					scanf("%d",&val);
					struct tree_node *tmp=search(root,val);
					if(tmp == NULL)
						printf("Node does not exist\n");
					else
						printf("Node is present");
					break;
					
			case 2: printf("Enter the data to be entered: ");
					scanf("%d",&val);
					insert(root,val);
					break;
					
			case 3: printf("Enter the data to be entered: ");
					scanf("%d",&val);
					insert_a_node(root,val);
					break;
					
			case 4: printf("Enter the data to be deleted: ");
					scanf("%d",&val);
					del(root,val);
					break;
			
			case 5: display(root,0);
					break;
					
			case 6: exit(0);
			
		}
	}
return 0;
}
