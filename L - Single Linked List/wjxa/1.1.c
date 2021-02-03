#include<stdio.h>// 实验8.2：两个有序链表合并后依然有序。
#include<malloc.h>
struct student 
{
	int data;
	struct student *next;
};
struct student *create(struct student *head,int n);
struct student *insert(struct student *head);
void output(struct student *head);
struct student *merge(struct student *head1,struct student *head2,struct student *head3);
struct student *insert2(struct student *head,int datathis);
int main()
{
	int n1,n2;
	struct student *head1,*head2,*head3;
	scanf("%d%d",&n1,&n2);
	head1=NULL;head2=NULL;head3=NULL;
	head1=create(head1,n1);
	head2=create(head2,n2);
	output(head1);
	printf("\n");
	output(head2);
	printf("\n");
	head3=merge(head1,head2,head3);
	output(head3);
	return 0;
}
struct student *create(struct student *head,int n)
{
	int i;
	for(i=0;i<n;i++)//头插法
	{
		head=insert(head);
	}
	return head;
}
struct student *insert(struct student *head)
{
	struct student *newp=(struct student *)malloc(sizeof(struct student));
	scanf("%d",&(newp->data));
	newp->next=head;
	head=newp;
	return head;
}
void output(struct student *head)
{
	struct student *p;
	p=head;
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=NULL);
}
struct student *merge(struct student *head1,struct student *head2,struct student *head3)
{
	struct student *p,*q;
	p=head1;
	q=head2;
	do
	{
		if(q==NULL||(p->data>q->data))
		{
			head3=insert2(head3,p->data);
			if(p!=NULL)p=p->next;
		}
		if(p==NULL||(p->data<=q->data))
		{
			head3=insert2(head3,q->data);
			if(q!=NULL)	q=q->next;
		}
		if(p==NULL&&q==NULL)break;
	}while(1);
	return head3;
}

struct student *insert2(struct student *head,int datathis)
{
	struct student *newp=(struct student *)malloc(sizeof(struct student));
	newp->data=datathis;
	newp->next=head;
	head=newp;
	return head;
}

