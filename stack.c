#include<stdio.h>
#include<stdlib.h>


#define max 5

struct stack{
		int stack[max];
		int top,item;
};

void push(struct stack *s)
{
	if((s->top) == (max-1))
		printf("Stack Overflow");
	else
	{
		++(s->top);
		(s->stack[s->top]) =(s->item);
	}
}

int pop(struct stack *s)
{
	int ret;
	if((s->top) == -1)
	{
		ret = 0;
		printf("Stack underflow");
	}
	else
	{
		ret = (s->stack[s->top]);
		--(s->top);
	}
	return(ret);
}

void display(struct stack *s)
{
	int i;
	printf("The stack is");
	if((s->top) == -1)
	   printf("Stack is empty");
	else
	{
		for(i=(s->top);i>=0;--i)
		  { printf("\n\t|%3d|\t\n",(s->stack[i]));}

		printf("\n");
	}
}

void main()
{
	struct stack s;
	char c;int count=0,y;
	s.top = -1;
	printf("Enter your choice:\n");
	printf("\ta - Pushing an item\n");
	printf("\tb - Poping an item\n");
	printf("\tc - Display the stack\n");
	printf("\td - Exit");

	while(count<100){
	scanf("%c",&c);

	switch(c)
	{
		case 'a' :
			printf("Enter the element to be pushed");
			scanf("%d",&(s.item));
			push(&s);count++;
			break;

		case 'b' :y = pop(&s);
			printf("%d",y);
			count++;break;

		case 'c' :display(&s);count++;break;
		case 'd' :exit(0);
	}}
}
