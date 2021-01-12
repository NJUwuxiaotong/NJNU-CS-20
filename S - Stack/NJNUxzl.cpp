#include<stdio.h>
#include<stdlib.h>
void initial(struct Stack *stack);
void push(struct Stack *stack);
void pop(struct Stack *stack);
void output(struct Stack *stack);
void menu();
struct Link
{
	int data;
    struct Link* next;		
};
struct Stack
{	
	struct Link* head;
	int size;	
};
int main()
{
	struct Stack stack;
	int n,choice,flag=1;
	menu();
	while(flag)
	{   scanf("%d",&choice);
		switch(choice)
		{
			case 0:flag=0;
				    break;	
			case 1:output(&stack);
					break;
			case 2:initial(&stack);
					break;
			case 3:push(&stack);
					break;
			case 4:pop(&stack);
					break;
			 
		}
 
 
	}
return 0;		
} 
void menu()
{
	printf("             链表栈管理               \n");
	printf("--------------------------------------\n");	
	printf(">1.显示栈中各元素\n");
	printf(">2.初始化\n");
	printf(">3.推入一个数\n");
	printf(">4.推出栈顶的数\n");
	printf(">0.退出\n");
	printf("--------------------------------------\n");
	
}
void output(struct Stack *stack)
{
	struct Link *p=stack->head;
	if(stack->size==0)
	{
		printf("空栈!\n");
		return ;	
		
	}
	else if(stack->size==1)
	{	printf("    栈中元素\n");
		printf("----------------\n");
		printf("栈顶 "); 
		printf("栈底 %d\n",p->data);	
		printf("----------------\n");
		return ;
		
	}
		printf("    栈中元素\n");
		printf("----------------\n");
		printf("栈顶 ");	
	while(p->next!=NULL)
	{	printf("%d\n",p->data);
		printf("     ");
		p=p->next;	
	
	}	
		printf("\b\b\b\b\b栈底 %d\n",p->data);
		printf("----------------\n");
		
}
void initial(struct Stack *stack)
{
	stack->head=NULL;
	stack->size=0;
	printf("初始化成功!\n");
}
void push(struct Stack *stack)
{
	struct Link *p;
	p=(struct Link*)malloc(sizeof(struct Link));
	printf("请输入你要推入的值:");
	scanf("%d",&p->data);
	p->next=stack->head;
	stack->head=p;
	stack->size++;
	printf("加入成功!\n");		
}
void pop(struct Stack *stack)
{
	if(stack->size==0)
	{
		printf("空栈!\n");	
		return ;
	 }	 
	struct Link *p=stack->head;
	stack->head=p->next;
	free(p);
	stack->size--;
    printf("成功!\n");		
}
