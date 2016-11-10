#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node *getnode(){
	return((struct node*)malloc(sizeof(struct node)));
}

struct node* push(struct node *s,int item){
	struct node *temp;	
	temp = getnode();
	temp->info = item;
	temp->link = s;
	s = temp;
	return s;
}

struct node* pop(struct node *s,int *pitem){
	struct node *temp;
	if(s == NULL){printf("Empty stack"); return;}
	
	*pitem = s->info;
	temp = s;
	s = s->link;
	free(temp);
	return s;	
}

void display(struct node *s){
	struct node *temp;
	temp = s;
	while(temp != NULL){	
		printf("%d\t",temp->info);
		temp = temp->link;
	}	
}
void main(){
	struct node *stack; int i,item,pitem;
	stack = NULL;
	
	printf("Enter your choice");	
	printf("\n1. Pushing an element");
	printf("\n2. Poping an element");
	printf("\n3. Display the  stack");
	printf("\n4. Exit");
	do{
		scanf("%d",&i);
		switch(i){
			case 1: printf("Enter an item");scanf("%d",&item); stack = push(stack,item);break;
		
			case 2: stack = pop(stack,&pitem);break;
			
			case 3: display(stack);break;
		}
	}while(i!=4);
}
