#include<stdio.h>
#include<stdlib.h>
#define max 5

struct queue
{
	int r,f;
	int item;
	int queue[max];
};

void addq(struct queue *q)
{
	/*if queue is full*/
	if((q->r) == max-1)
		printf("queue overflow");
	else
	{	printf("Enter an item to be inserted into the queue");scanf("%d",&(q->item));
		++(q->r);
		(q->queue[q->r]) = (q->item);
	}
}
int delq(struct queue *q)
{
	/*if queue is empty*/
	if((q->r) == -1)
		printf("queue underflow");
	else
	{	int ret;
		ret = (q->queue)[q->r];
		--(q->r);
		return ret;
	}}
void display(struct queue *q)
{
	int i;
	if((q->r) == -1){printf("Queue is empty");}

	else{
	for(i=(q->f);i<=(q->r);i++)
	{
		printf("\t|%d|\n",(q->queue[i]));
	}}

}
void main()
{	int count=0;char c;int y;

		struct queue q; q.r = -1; q.f = 0;
		printf("Enter your choice\n");
		printf("\t(a) Adding an item\n");
		printf("\t(b) Deleting an item\n");
		printf("\t(c) Display the queue\n");
		printf("\t(d) Exit\n");
	while(count<100){scanf("%c",&c);
		switch(c)
			{case 'a':{ addq(&q); count++;break;}
			case 'b':{y = delq(&q);printf("%d",y);count++;break;}

			case 'c':{display(&q);count++;break;}

			case 'd':{exit (0);}}
}}



