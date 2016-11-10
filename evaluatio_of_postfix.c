#include<stdio.h>
#include<stdlib.h>


int push(float x,float s[],int *t)
{
	s[++(*t)] = x;
}

float pop(float s[],int *t)
{
	if(*t == -1){return 0;}
	else{
		return s[(*t)--];
	}
}


void main()
{
	float stack[100];	int top = -1;
	char pfix[100];
	printf("Enter the postfix expression");
	scanf("%s",pfix);

	int rhs,lhs;
	char *e;
	e = pfix;
	
	while(*e != '\0'){
		
		if(isalnum(*e))
		{	push((float)(*e - '0'),stack,&top);	}
		
		else{
			switch (*e){
			case '+': rhs = pop(stack,&top); lhs = pop(stack,&top); push(lhs+rhs,stack,&top); break;

			case '-': rhs = pop(stack,&top); lhs = pop(stack,&top); push(lhs-rhs,stack,&top); break;
	
			case '*': rhs = pop(stack,&top); lhs = pop(stack,&top); push(lhs*rhs,stack,&top); break;

			case '/': rhs = pop(stack,&top); lhs = pop(stack,&top); push(lhs/rhs,stack,&top); break;
			}
		}e++;}
	while(top != -1){
	printf("%f",pop(stack,&top));	}

}
		










