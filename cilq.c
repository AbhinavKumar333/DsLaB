#include <stdio.h>
#include <stdlib.h>

#define max 5

struct queue
{
    int r,f,item,count;
    int queue[max];
};

void addq(struct queue *q)
{
    if((q->count) == max){
        printf("queue overflow");
    }
    else if((q->count) == 0){
         printf("Enter an element in the queuee");
        scanf("%d",&(q->item));
        q->r = q->f = 0;
        (q->queue[q->r]) = (q->item);(q->count)++;
    }
    else if((q->count) > 0){
        printf("Enter an element in the queue");
        scanf("%d",&(q->item));
        (q->r) = (((q->r) + 1)%max);
        (q->queue[q->r]) = (q->item);(q->count)++;
    }
}

int delq(struct queue *q)
{   int ret;
    if((q->count) == 0){
        printf("queue underflow");
    }
    else if(q->count == 1){

    ret = q->queue[q->r];
    (q->r) = (q->f) = -1;(q->count)--;
    }
    else{

    ret = q->queue[q->f];
    (q->f) = (((q->f) + 1)%max);(q->count)--;
    }
    return (ret);
}

void display(struct queue *q)
{   int i;
    printf("The queue is ");
    if((q->count) == 0){
        printf("empty");
    }
    else{
            if((q->r == q->f) || (q->r) > (q->f)){
        for(i=(q->f);i<=(q->r);i++){
            printf("\n\t|%d|",(q->queue[i]));
        }}
            else if((q->r) < (q->f)){
                for(i=0;i<=(q->r);i++)
                    {printf("\n\t|%d|",(q->queue[i]));}

		if(((q->f)-(q->r))> 1){
		for(i=(q->r)+1;i<(q->f);i++){printf("\n\t||");}}

                for(i=(q->f);i<max;i++){
                    {printf("\n\t|%d|",(q->queue[i]));}}

             }
    }
}

void main()
{   struct queue q;q.r=-1;q.f=-1;q.count = 0;
    int coun=0,y;char c;
    printf("Enter your choice\n");
    printf("\ta- add\n");
    printf("\tb- delete\n");
    printf("\tc- display\n");
    printf("\td- exit\n");

    while(coun<100){scanf("%c",&c);
   switch(c)
	{
		case 'a' :
			{addq(&q);coun++;
			break;}

		case 'b' :{y = delq(&q);
			printf("%d",y);
			coun++;break;}

		case 'c' :{display(&q);coun++;printf("%d",(q.count));break;}
		case 'd' :{exit(0);}
}
}
}

