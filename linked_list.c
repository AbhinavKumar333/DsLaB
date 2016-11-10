#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

struct node *getnode(){
	return(struct node *)malloc(sizeof(struct node));
}

void main(){
	struct node *first,*temp,*next,*prev; int pos,count=0,i,item; char c;

	printf("Enter your choice\n");
	printf("\ta. Insert at the front\n");
	printf("\tb. Insert at any position\n");
	printf("\tc. Delete a node from specified postition\n");
	printf("\td. Search a node\n");
	printf("\te. Display all nodes\n");
	printf("\tx. Exit\n");
	do{	scanf("%c",&c);
		switch(c){
			case 'a':	first = getnode(); printf("Enter an element"); scanf("%d",&item); first->info = item;
                        first->link = NULL;count++;break;

			case 'b':printf("Enter the position for the new node where total nodes are %d\n",count); scanf("%d",&pos);
                        printf("Enter an element"); scanf("%d",&item);
                        next = first; i = 1;
                        while(pos!=i){
                            prev = next;
                            next = next->link; i++;
                        }   next = getnode(); next->info = item; next->link = prev->link; prev->link = next; count++; break;

            case 'c':   printf("Enter the node info to be deleted where total nodes are %d\n",count);
		        scanf("%d",&pos);
                        next = first;
                        while(next!=NULL){
                            prev=next;
                            if(next->info==pos){ prev->link = next->link; free(next);}
                            next = next->link;
                        }count--;break;


            case 'd':   printf("Enter the node to be searched\n");
		        scanf("%d",&pos);
                        next = first; i = 1;
                        while(pos != next->info){
                                next = next->link;i++;
                        }   printf("The element was found at position %d\n",i);

            case 'e':       next = first;
                            while(next != NULL){
                                printf("|%d|-->",next->info);
				 next = next->link;
                        }break;

		}

	}while(c != 'x');

}
