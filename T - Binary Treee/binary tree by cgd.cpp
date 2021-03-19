#include<stdio.h>
#include<stdlib.h>
int front=0,rear=0;
typedef struct bitnode{
	int data;
	struct bitnode *lchild,*rchild;
}bitnode,*bittree;
bittree create();
void xianxu(bittree t);
void push(bittree *a,bittree node);
bitnode *pop(bittree *a);
void output(bittree node);
int main(){
	bittree tree;
	bittree a[20];
	printf("�������һ������ֵ(����-1��ʾ����һ������)��\n");
	tree=create();
	bittree p;
	printf("��������Ľ��Ϊ:\n"); 
	xianxu(tree);
	printf("��������Ľ��Ϊ:\n");
	push(a,tree);
	while(rear>front){
		p=pop(a);
		output(p);
		if(p->lchild!=NULL){
			push(a,p->lchild);
		}
		if(p->rchild!=NULL){
			push(a,p->rchild);
		}
	}
	return 0;
}
bittree create(){
	int data,s;
	bittree t;
	scanf("%d",&data);
	s=getchar();
	if(data==-1){
		return NULL;
	}
	else{
		t=(bittree)malloc(sizeof(bitnode));
		t->data=data;
		printf("������%d��������",data);
		t->lchild=create();
		printf("������%d��������",data);
		t->rchild=create();
		return t;
	}
}
void xianxu(bittree t){
	if(t==NULL){
		return;
	}
	printf("%d ",t->data);
	xianxu(t->lchild);
	xianxu(t->rchild);
}
void push(bittree *a,bittree node){
    a[rear]=node;
    rear++;
}
bitnode *pop(bittree *a){
	return a[front++];
}
void output(bittree node){
	printf("%d ",node->data);
}


















