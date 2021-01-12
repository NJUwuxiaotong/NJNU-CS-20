#include<stdio.h>
#include<stdlib.h>
void initial(struct Queue *queue);
void push(struct Queue *queue);
void pop(struct Queue *queue);
void output(struct Queue *queue);
void mpop(struct Queue *queue);
void menu();
struct Link
{
	int data;
    struct Link* next;		
};
struct Queue
{	
	struct Link* head;
	int size;	
};
int main()
{
	struct Queue queue;
	int n,choice,flag=1;
	menu();
	while(flag)
	{   scanf("%d",&choice);
		switch(choice)
		{
			case 0:flag=0;
				    break;	
			case 1:output(&queue);
					break;
			case 2:initial(&queue);
					break;
			case 3:push(&queue);
					break;
			case 4:pop(&queue);
					break;
			case 5:mpop(&queue);
					break;
		
		}
 
 
	}
return 0;		
} 
void menu()
{
	printf("              队列管理               \n");
	printf("--------------------------------------\n");	
	printf(">1.显示队列中各元素\n");
	printf(">2.初始化\n");
	printf(">3.推入一个数\n");
	printf(">4.推出一个数\n");
	printf(">5.推入多个数\n");
	printf(">0.退出\n");
	printf("--------------------------------------\n");
	
}
void output(struct Queue *queue)
{
	struct Link *p=queue->head->next;
	if(queue->size==0)
	{
		printf("空队列!\n");
		return ;	
		
	}
		printf("            队列           \n");
		printf("----------------------------\n");	
	while(p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;	
	
	}	printf("\n"); 
		printf("----------------------------\n");
		printf(">>\n");
		
}
void initial(struct Queue *queue)
{	queue->head=(struct Link*)malloc(sizeof(struct Link));
	queue->head->next=NULL;
	queue->size=0;
	printf("初始化成功!\n");
}
void push(struct Queue *queue)
{
	struct Link *p,*q=queue->head; 
	p=(struct Link*)malloc(sizeof(struct Link));
	printf("请输入你要推入的值:");
	scanf("%d",&p->data);
	while(q->next!=NULL)
	{
		q=q->next;
	}
		q->next=p;
		p->next=NULL;
		queue->size++;
	printf("加入成功!\n");		
}
void pop(struct Queue *queue)
{
	if(queue->size==0)
	{
		printf("空队列!\n");	
		return ;
	 }	 
	struct Link *p=queue->head,*q=p->next,*a=q->next;
    p->next=a;
	free(q);
	queue->size--;
    printf("成功!\n");		
}
void mpop(struct Queue *queue)
{	struct Link *p=queue->head,*q=NULL;
	int n;	
	printf("请输入你要添加数的个数:");
	scanf("%d",&n);	
	if(n<=0)
	{
		printf("个数不能为非正数!");
		return ;
	}
	int i;
	while(p->next!=NULL)
	p=p->next;
	for(i=1;i<=n;i++)
	{
		q=(struct Link*)malloc(sizeof(struct Link));
		printf("请输入你要插入的第%d个值:",i);
		scanf("%d",&q->data); 
		p->next=q;
		q->next=NULL;
		p=q;
		queue->size++;
	}
  printf("插入成功!\n");	
	
	
	
	
}
