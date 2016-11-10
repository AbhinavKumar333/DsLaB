#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};


struct node *getnode()
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	return p;
}

struct node *insert_front(struct node *first, int val)
{
	struct node *temp;
	if(first == NULL)
	{
		temp = getnode();
		temp -> info = val;
		temp -> llink = NULL;
		temp -> rlink = NULL;
		first = temp;
		return first;
	}
	else
	{
		temp = getnode();
		temp -> info = val;
		temp -> llink = NULL;
		temp -> rlink = first;
		first -> llink = temp;
		first = temp;
		return temp;
	}
}

struct node *insert(struct node *first, int val, int key)
{
	struct node *temp, *x, *y;
	if((first == NULL) || (first -> info == key))
	{
		first = insert_front(first, val);
		return first;
	}
	else
	{
		x = first;
		while(x != NULL)
		{
			if(x -> info == key)
				break;
			x = x -> rlink;
		}
		if(x == NULL)
		{
			printf("Invalid input.\n");
			return first;
		}
		else
		{
			temp = getnode();
			temp -> info = val;
			temp -> rlink = x;
			temp -> llink = x -> llink;
			y = temp -> llink;
			y -> rlink = temp;
			x -> llink = temp;
			return first;
		}
	}
}

struct node *delete(struct node *first, int val)
{
	struct node *temp;
	temp = first;
	if(first == NULL)
	{
		printf("Empty list.\n");
		return first;
	}
	else if(first -> info == val)
	{
		first = first -> rlink;
		free(temp);
		return first;
	}
	else
		{
			struct node *x, *prev, *next;
			x = first;
			while(x != NULL)
			{
				if(x -> info == val)
					break;
				x = x -> rlink;
			}
			if(x == NULL)
			{
				printf("Invalid input.\n");
				return first;
			}
			else
			{
				prev = x -> llink;
				next = x -> rlink;

				if(x -> rlink == NULL)
				{
					prev -> rlink = next;
					free(x);
					return first;
				}
				else
				{
					prev -> rlink = next;
					next -> llink = prev;
					free(x);
					return first;
				}
			}
		}

}

void display(struct node *first)
{
	struct node *temp;
	temp = first;
	if(temp == NULL)
	{
		printf("Empty list.\n");
		return;
	}
	printf("List contains:\n");
	while(temp != NULL)
	{
		printf("%d  ", temp -> info);
		temp = temp -> rlink;
	}
	printf("\n");

}

void main()
{
	int ch, val, key;
	struct node *first, *last, *temp;
	first = NULL;
	last = first;
	while(1)
	{
		printf("\n1.Insert at front\n2.Insert using key\n3.Delete\n4.Display\n5.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the value to be inserted:\n");
					scanf("%d", &val);
					first = insert_front(first, val);
					break;

			case 2: printf("Enter the value to be inserted:\n");
					scanf("%d", &val);
					printf("Enter the value of the next node:\n");
					scanf("%d", &key);
					first = insert(first, val, key);
					break;

			case 3: if(first == NULL)
					{
						printf("Empty list.\n");
						break;
					}
					printf("Enter the value to be deleted:\n");
					scanf("%d", &val);
					first = delete(first, val);
					break;

			case 4: display(first);
					break;

			default: exit(0);
		}
	}
}

