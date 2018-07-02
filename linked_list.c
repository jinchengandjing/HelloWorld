#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
} ;

struct node *head = NULL;

void queue_add(int data)
{
	struct node *mynode = (struct node *) malloc(sizeof(struct node));
	mynode->data = data;
	mynode->next = head;

	head = mynode;
}

int queue_del(int data)
{
	struct node *myp = head;
	struct node *prev = NULL;

	if(head == NULL) return -3;

	while(myp != NULL)
	{
		if(myp->data == data)
		{
			if(prev == NULL)
			{
				head = myp->next;
				free(myp);
				return 0;

			}
			prev->next = myp->next;
			free(myp);
			return 0;
		}
		prev = myp;
		myp = myp->next;
	}
	return -2;
}

int queue_size(void)
{
	struct node *myp = head;
	int count = 0;

	while(myp != NULL)
	{
		myp = myp->next;
		count++;
	}
	return count;
}

void queue_sort(void)
{
	struct node *myp1, *myp2;
	int count = queue_size(), i, j, tempdata;

	if(count == 0 || count == 1) return;

	for(myp1 = head, i = 0; i < count - 1; i++, myp1 = myp1->next)
	{
		for(myp2 = myp1->next, j = i + 1; j < count; j++, myp2 = myp2->next)
		{
			if(myp1->data > myp2->data)
			{
				tempdata = myp1->data;
				myp1->data = myp2->data;
				myp2->data = tempdata;
			}
		}
	}
}

void queue_reverse(void)
{
	struct node *current = head, *prev, *temp;
	int count = queue_size();

	if(count == 0 || count == 1) return;

	prev = NULL;

	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}

void queue_print(void)
{
	struct node *myp = head;
	int count = 0;
	if(head == NULL) 
	{
		printf("Empty queue\n");
		return;
	}
	printf("\nTotal q length: %d\n", queue_size());
	while(myp != NULL)
	{
		printf("Seq no: %d, data: %d\n", ++count, myp->data);
		myp = myp->next;
	}
}

int main()
{
	int ret;
	queue_print();

	ret = queue_del(10);
	if(ret != 0) printf("queue_del error! The queue is empty or something wrong with it.\n");

printf("\nAdd 4 queues\n");
	queue_add(10);
	queue_add(2);
	queue_add(8);
	queue_add(5);
	queue_print();

printf("\nReverse queues\n");
	queue_reverse();
	queue_print();

printf("\nSort queues\n");
	queue_sort();
	queue_print();

printf("\nDelete item 2\n");
	queue_del(2);
	queue_print();

printf("\nDelete item 10\n");
	queue_del(10);
	queue_print();

printf("\nDelete item 8\n");
	queue_del(8);
	queue_print();

printf("\nDelete item 5\n");
	queue_del(5);
	queue_print();


printf("\nAdd 1, 2 3 to queue\n");
	queue_add(1);
	queue_add(2);
	queue_add(3);
	queue_print();

printf("\nDelete item 2\n");
	queue_del(2);
	queue_print();

printf("\nDelete item 3\n");
	queue_del(3);
	queue_print();

printf("\nDelete item 1\n");
	queue_del(1);
	queue_print();

	return 0;
}
