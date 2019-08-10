#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Node *front=NULL;
struct Node *rear=NULL;

struct Node* deQueue()
{
	printf("\n*Using deQueue*");
	struct Node *temp;
	temp=front;
	front=front->link;
	printf("\nElement deQueued: %d",temp->data);
	free(temp);
	return front;
}

struct Node* enQueue()
{
	int data;
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	printf("\nEnter data for new element: ");
	scanf("%d",&data);
	temp->data=data;
	temp->link=NULL;
	
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
	return front;
}

struct Node* print()
{
	struct Node* itr;
	printf("\nCurrent Elements in Queue: ");
	itr=front;
	while(itr!=NULL)
	{
		printf("\nData: %d\n",itr->data);
		itr=itr->link;
	}
}

struct Node* peek()
{
	printf("\n*Using peek*\nCurrent element : %d ",front->data);
}

int main()
{		
	int n;
	printf("\nHow many elements? : ");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{	
		front=enQueue();
	}
	print();
	front=deQueue();
	print();
	peek();
	front=enQueue();
	print();
	return 0;
}

