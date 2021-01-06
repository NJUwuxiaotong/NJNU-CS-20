#include<stdio.h>
#include<stdlib.h>
void initial(struct stack *top,int value);
struct stack *push(struct stack *top,int value);
struct stack *pop(struct stack *top);
void output(struct stack *top);
struct stack{
	int value;
	struct stack *next;
};
int main(){
	int value,x;
	struct stack *top=(struct stack *)malloc(sizeof(struct stack));
	top->next=NULL;
	printf("1.初始化.initial\n");
	printf("2.入栈.push\n");
	printf("3.出栈.pop\n");
	printf("4.退出.exit\n");
	printf("请选择你的操作:");
	while(1){
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("请输入栈底的值:");
				scanf("%d",&value);
				initial(top,value);
				output(top);
				break;
			case 2:
				printf("请输入加入栈的值:");
				scanf("%d",&value);
				top=push(top,value);
				output(top);
				break;
			case 3:
				top=pop(top);
				output(top);
				break;
			case 4:
				printf("结束!");
				break;
		}
		if(x==4) break;
		printf("请选择你的操作:\n");
	}
	return 0;
}
void initial(struct stack *top,int value){
	top->value=value;
}
struct stack *push(struct stack *top,int value){
	struct stack *newp;
	newp=(struct stack *)malloc(sizeof(struct stack));
	newp->value=value;
	newp->next=top;
	top=newp;
	return top;
}
struct stack *pop(struct stack *top){
	struct stack *p;
	p=top;
	if(p->next!=NULL){
		top=top->next;
		free(p);
		return top;
	}
	else printf("栈已经空了!");
}
void output(struct stack *top){
	struct stack *p;
	p=top;
	while(p!=NULL){
		printf("%6X %6d %6x\n",p,p->value,p->next);
		p=p->next;
	}
}
