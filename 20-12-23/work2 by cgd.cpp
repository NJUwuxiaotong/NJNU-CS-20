#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initial(struct node *head,int value);
struct node *addahead(struct node *head,struct node *newp,int value);
struct node *addafter(struct node *tail,int value);
struct node *add(struct node *head,struct node *newp,int pos,int value);
struct node *del(struct node *head,int pos);
void search(struct node *head,int pos);
struct node *valuesort(struct node *head);
void output(struct node *head);
struct node{
	int value;
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
	printf("(5)删除第n个结点.delete\n");
	printf("(6)查找第n个结点.search\n");
	printf("(7)根据值排序.sort\n");
	printf("(8)退出.exit\n");
	printf("请选择你要进行的操作\n");
	while(1){
		scanf("%d",&c);
		if(c==1){
			printf("请输入定义的头节点数值:"); 
			scanf("%d",&value);
			initial(head,value);
		}
		if(c==2){
			printf("请输入插入的头节点数值:");
			scanf("%d",&value);
			newp=(struct node *)malloc(sizeof(struct node));
			head=addahead(head,newp,value);
			output(head);
		}
		if(c==3){
			printf("请输入插入的尾节点数值:"); 
			scanf("%d",&value);
			tail=addafter(tail,value);
			output(head);
		}
		if(c==4){
			printf("请输入插入的节点位置和数值:");
			scanf("%d %d",&pos,&value);
			newp=(struct node *)malloc(sizeof(struct node));
			head=add(head,newp,pos,value);
			output(head);
		}
		if(c==5){
			printf("请输入要删除的结点位置:"); 
			scanf("%d",&pos);
			head=del(head,pos);
			output(head); 
		}
		if(c==6){
			printf("请输入要查找的结点位置:");
			scanf("%d",&pos);
			search(head,pos);
		}
		if(c==7){
			head=valuesort(head);
			output(head);
		}
		if(c==8){
			printf("结束!");
			break;
		}
		printf("请选择你要进行的操作\n");
	}
	return 0;
}
void initial(struct node *head,int value){
	head->value=value;
	head->next=NULL;
	printf("%x %6d %x\n",head,head->value,head->next);
	
}
struct node *addahead(struct node *head,struct node *newp,int value){
	newp->value=value;
	newp->next=head;
	head=newp;
	return head;
}
struct node *addafter(struct node *tail,int value){
	struct node *newtail=(struct node *)malloc(sizeof(struct node));
	newtail->value=value;
	tail->next=newtail;
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
	newp->value=value;
	prep->next=newp;
	return head;
}
struct node *del(struct node *head,int pos){
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
	if(p==head)
		head=head->next;
	else
		prep->next=p->next;
	free(p);
	return head;
}
void output(struct node *head){
	struct node *p;
	p=head;
	while(p!=NULL){
		printf("%x %6d %x\n",p,p->value,p->next);
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
			printf("%x %6d %x\n",p,p->value,p->next);
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
		if(min!=q){
			t=p->value;
			p->value=min->value;
			min->value=t;
		}
	}
	return head;
}
