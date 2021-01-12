#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initial(struct node *head,int value);
struct node *addahead(struct node *head,struct node *newp,int value);
struct node *addafter(struct node *tail,int value);
struct node *add(struct node *head,struct node *newp,int pos,int value);
struct node *del(struct node *head,struct node *tail,int pos);
void search(struct node *head,int pos);
struct node *delafter(struct node *tail); 
struct node *valuesort(struct node *head);
void output(struct node *head);
void swap(struct node *head,struct node *left,struct node *right);
struct node{
	int value;
	struct node *prior;
	struct node *next;
};
int main(){
	int i,value,c,id,pos;
	char s[100],name[100];
	float y;
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *newp;
	struct node *tail;
	tail=head;
	printf("(1)初始化链表.initial\n");
	printf("(2)在前方添加结点.addahead\n");
	printf("(3)在后方添加结点.addafter\n");
	printf("(4)在第i个结点后添加结点.add\n");
	printf("(5)删除第n个结点(非尾结点).del\n");
	printf("(6)删除尾结点.delafter\n");
	printf("(7)查找第n个结点.search\n");
	printf("(8)根据值排序.sort\n");
	printf("(9)退出.exit\n");
	printf("请选择你要进行的操作\n");
	while(1){
		scanf("%d",&c);
		switch(c){
		case 1:
			printf("请输入定义的头节点数值:"); 
			scanf("%d",&value);
			initial(head,value);
			break;
		case 2:
			printf("请输入插入的头节点数值:");
			scanf("%d",&value);
			newp=(struct node *)malloc(sizeof(struct node));
			head=addahead(head,newp,value);
			output(head);
			break;
		case 3:
			printf("请输入插入的尾节点数值:"); 
			scanf("%d",&value);
			tail=addafter(tail,value);
			output(head);
			break;
		case 4:
			printf("请输入插入的节点位置和数值:");
			scanf("%d %d",&pos,&value);
			newp=(struct node *)malloc(sizeof(struct node));
			head=add(head,newp,pos,value);
			output(head);
			break;
		case 5:
			printf("请输入要删除的结点位置:"); 
			scanf("%d",&pos);
			head=del(head,tail,pos);
			output(head); 
			break;
		case 6:
			tail=delafter(tail);
			output(head);
			break;
		case 7:
			printf("请输入要查找的结点位置:");
			scanf("%d",&pos);
			search(head,pos);
			break;
		case 8:
			head=valuesort(head);
			output(head);
			break;
		case 9:
			printf("结束!");
			break;
		}
		if(c==9) break;
		printf("请选择你要进行的操作\n");
	}
	return 0;
}
void initial(struct node *head,int value){
	head->value=value;
	head->next=NULL;
	head->prior=NULL;
	printf("%6x %6x %6d %6x\n",head->prior,head,head->value,head->next);
	
}
struct node *addahead(struct node *head,struct node *newp,int value){
	newp->value=value;
	head->prior=newp;
	newp->next=head;
	newp->prior=NULL;
	head=newp;
	return head;
}
struct node *addafter(struct node *tail,int value){
	struct node *newtail=(struct node *)malloc(sizeof(struct node));
	newtail->value=value;
	tail->next=newtail;
	newtail->prior=tail;
	newtail->next=NULL;
	return newtail;
}
struct node *add(struct node *head,struct node *newp,int pos,int value){
	struct node *prep,*p;
	int x=0;
	prep=NULL;
	p=head;
	while(p!=NULL){
		x++;
		prep=p;
		p=p->next;
		if(x==pos) break;
	}
	newp->next=p;
	p->prior=newp;
	newp->value=value;
	prep->next=newp;
	newp->prior=prep;
	return head;
}
struct node *del(struct node *head,struct node *tail,int pos){
	struct node *p,*prep;
	int x=0;
	p=head;
	while(p!=NULL){
		x++;
		if(x==pos) break;
		prep=p;
		p=p->next;
	}
	if(p==NULL)
		return head;
	if(p==head){
		head->next->prior=NULL;
		head=head->next;
	}
	else{
		p->next->prior=prep;
		prep->next=p->next;
	}
	free(p);
	return head;
}
struct node *delafter(struct node *tail){
	tail->prior->next=NULL;
	tail=tail->prior;
	return tail;
}
void output(struct node *head){
	struct node *p;
	p=head;
	while(p!=NULL){
		printf("%6x %6x %6d %6x\n",p->prior,p,p->value,p->next);
		p=p->next;
	}
}
void search(struct node *head,int pos){
	struct node *p;
	int x=0;
	p=head;
	while(p!=NULL){
		x++;
		if(x==pos){
			printf("%6x %6x %6d %6x\n",p->prior,p,p->value,p->next);
			break;
		}
		p=p->next;
	}
}
struct node *valuesort(struct node *head){
	struct node *p,*q,*min;
	int t;
	p=head;
	for(;p!=NULL;p=p->next){
		min=p;
		for(q=p->next;q!=NULL;q=q->next){
			if(q->value<min->value) min=q;
		}
		if(min!=p){
			//t=min->value;min->value=p->value;p->value=t;
			swap(head,p,min); 
		}
	}
	return head;
}

void swap(struct node *head,struct node *left,struct node *right){
	struct node *temp;
	if(right->next==NULL){
		if(left->next==right){ 
			right->next=left;
			right->prior=left->prior;
			left->next=NULL;
			left->prior->next=right;
			left->prior=right;
		}
		else{
			right->next=left->next;
			right->prior->next=left;
			temp=right->prior;
			right->prior=left->prior;
			left->next->prior=right;
			left->next=NULL;
			left->prior->next=right;
			left->prior=temp;
		}
	}
	else{
		if(left->next==right){
			right->next->prior=left;
			temp=right->next;
			right->next=left;
			right->prior=left->prior;
			left->next=temp;
			left->prior->next=right;
			left->prior=right;
		}
		else{
			right->next->prior=left;
			temp=right->next;
			right->next=left->next;
			left->next->prior=right;
			left->next=temp;
			right->prior->next=left;
			temp=right->prior;
			right->prior=left->prior;
			left->prior->next=right;
			left->prior=temp;
		}
	}
}

