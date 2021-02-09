#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define error -1
struct stack
{
	int *data;
	int top;
	int maxsize;	
};
int main()
{
	//initial
	struct stack *s;
	scanf("%d",&s->maxsize);
	s->top=-1;
	s->data=(int*)malloc(s->maxsize*sizeof(int));
}
int push(struct stack *s)
{
	int x;
	scanf("%d",&x);
	if(s->maxsize-1==s->top)
	{
		printf("Õ»Âú");
		return error;
	}
	else
	{
		s->data[++s->top]=x;
		return 1;
	}
}

int pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("¿ÕÕ»");
		return error; 
	}
	else
	{
		return s->data[s->top--];
	}
}
