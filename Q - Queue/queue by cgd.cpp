#include<stdio.h>
#include<stdlib.h>
struct queue *initial(struct queue *q);
struct queue *push(struct queue *q);
struct queue *pop(struct queue *q);
int isempty(struct queue *q);
void output(struct queue *q);
struct node{
	int data;
	struct node *next;
};
struct queue{
	struct node *front,*rear;
	int length;
};
int main(){
	int x;
	struct queue *q=NULL;
	q=initial(q);
	printf("请选择你要进行的操作:\n"); 
	printf("1.初始化队列.initial\n"); 
	printf("2.入队.push\n"); 
	printf("3.出队.pop\n"); 
	printf("4.others\n"); 
	printf("5.结束.quit\n");
	while(1){
		scanf("%d",&x);
		switch(x){
			case 1:
				q=initial(q);
				break;
			case 2:
				q=push(q);
				output(q);
				break;
			case 3:
				q=pop(q);
				output(q);
				break;
			case 5:
				printf("结束!"); 
				break;
		}
		if(x==5) break;
		printf("请选择你要进行的操作:\n");
	}
	return 0;
}
struct queue *initial(struct queue *q){
	if(q!=NULL) free(q);
	q=(struct queue*)malloc(sizeof(struct queue));
	q->length=0;
	q->rear=(struct node*)malloc(sizeof(struct node));
	q->front=q->rear;
	q->rear->next=NULL;
	printf("初始化成功\n");
	return q;
}
struct queue *push(struct queue *q){
	int data;
	struct node *p;
	p=q->rear;
	while(p->next!=NULL) p=p->next;
	printf("请输入入队的值:");
	scanf("%d",&data);
	p->data=data;
	p->next=(struct node*)malloc(sizeof(struct node));
	p->next->next=NULL;
	q->length++;
	return q;
}
struct queue *pop(struct queue *q){
	if(isempty(q)==1){
		printf("队列为空，无法出队!");
		return q;
	}
	else{
		printf("出队结点为%d\n",q->rear->data);
		q->rear=q->rear->next;
		q->length--;
		return q;
	}
}
int isempty(struct queue *q){
	if(!q->length) return 1;
	else return 0;
}
void output(struct queue *q){
	struct node *p=q->rear;
	if(isempty(q)==1){
		printf("队列为空\n"); 
	}
	else{
		printf("当前队列中有%d个结点",q->length);
		while(p->next!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
}

