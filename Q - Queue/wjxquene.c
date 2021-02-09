#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define error -1
struct quene
{
	int *data;
	int front,rear;
	int n;//数组的长度 
};
//initial
int main()
{
struct quene *list;
int n;
scanf("%d",&n);
list->data=(int*)malloc(list->n*sizeof(int));
list->front=list->rear=-1;
}

int pop(struct quene *list)
{
	if(list->front==list->rear)
	{
		printf("空队列");
		return error; 
	}
	else
	{
		list->front=list->front+1;
		return list->data[list->front]; 
	}
}
int push(struct quene *list)
{
	if((list->rear+1)%list->n==list->front)
	{
		printf("已满");
		return error; 
	}
	else
	{
		int x;
		scanf("%d",&x);
		list->data[++list->rear]=x;
		
	}
} 
