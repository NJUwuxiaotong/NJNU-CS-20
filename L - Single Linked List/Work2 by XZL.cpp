#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int t=0;
using namespace std;
struct Node
{
	int data;
	struct Node *next;	
};
struct Node *Initial();
void output(struct Node *head);
void search(struct Node *head);
void add(struct Node *head);
void count();
void delet(struct Node *head);
void insert(struct Node *head);
void st(struct Node *head);
void menu();
int main()
{	int n,choice,flag=1;
	struct Node *head=Initial(); 
	menu();
	while(flag)
	{   scanf("%d",&choice);
		switch(choice)
		{
			case 0:flag=0;
				    break;	
			case 1:output(head);
					break;
			case 2:count();
					break;
			case 3:search(head);
					break;
			case 4:add(head);
					break;
			case 5:insert(head);
					break;
			case 6:delet(head);
					break;
			case 7:st(head);
					break;		
		}
 
 
	}
return 0;	
}
void menu()
{
    printf("               链表管理:\n");
	printf("--------------------------------------\n");
    printf(">1.显示当前链表\n");
	printf(">2.计算链表长度\n");
	printf(">3.查找结点数值\n"); 
	printf(">4.在链表尾部插入结点\n");
	printf(">5.在第i个结点后插入结点\n"); 
    printf(">6.删除第i个结点\n");
    printf(">7.按从小到大排序\n");
    printf(">0.退出\n");
    printf("---------------------------------------\n");

}
struct Node *Initial()
{
	struct Node *head,*p,*s;
	int n,i;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->data=0;
	head->next=NULL; 
	p=head;
    printf("请输入你要初始化的结点数:");
    scanf("%d",&n);
    t+=n;
    if(n==1)
    {
		printf("请输入第1个结点数值:");
    	scanf("%d",&head->data);
	}
	else
	{
    for(i=1;i<=n;i++)
    {
    	if(i==1)
    	{
		printf("请输入第1个结点数值:");
    	scanf("%d",&head->data);	
		}
		else
		{
    		s=(struct Node *)malloc(sizeof(struct Node));
			printf("请输入第%d个结点数值:",i);	
    		scanf("%d",&s->data);
    		p->next=s;
    		s->next=NULL;
    		p=s;
		}
	  }
	}
	return head;	
}
void output(struct Node *head)
{
	struct Node *p=head;
	int j=1;
	 printf("------------------\n");
	 printf("     当前链表     \n");
	while(p!=NULL)
	{
	 printf("第%d个   %d\n",j,p->data);	
	 p=p->next;	
	 j++;
	}	
	 printf("------------------\n");
	printf("接下来干嘛?\n");	
}
void search(struct Node *head)
{
	struct Node *p=head;
	int i=1,n;
	printf("请输入你要查找的结点:");
	scanf("%d",&n);
	while(i<n)
	{
	  p=p->next;
	  i++; 		  		
	}
  printf("第n个结点的数值为%d\n",p->data);
  printf("接下来干嘛?\n");	
  
}
void add(struct Node *head)
{
	struct Node *p=head;
	struct Node *a=NULL;
	int n;
	a=(struct Node *)malloc(sizeof(struct Node));
	while(p->next!=NULL)
	{
	  p=p->next;		
	}
	p->next=a;
	printf("输入你要插入的数据:");	
	scanf("%d",&n);
	a->data=n;
	a->next=NULL;
	printf("插入成功!\n");
	printf("接下来干嘛?\n");
	t++;	
}
void count()
{	 
printf("一共有%d个结点\n",t);
printf("接下来干嘛?\n");	
}
void delet(struct Node *head)
{	struct Node *p=head,*pr=NULL;
	int n,i=1;
    printf("输入你要删除的结点:");
    scanf("%d",&n);
	if(n>t||n<=0)
	{
		printf("不存在该结点!\n");
		return ;
    }
    if(n==1)
    {
		printf("头结点不可动!\n");
		return ;
	}
	while(i<n)
	{ pr=p;
	  p=p->next;
	  i++;	
	}
	pr->next=p->next;
	free(p);
printf("接下来干嘛?\n");
t--;	
}
void insert(struct Node *head)
{
	struct Node *p=head,*a=NULL;
	int n,i=1,x;
	a=(struct Node *)malloc(sizeof(struct Node));
	printf("请输入你要插入的位置:");
	scanf("%d",&n);
	if(n>t||n<=0)
	{
		printf("不存在该结点!\n");
		return ;
    }
	printf("请输入你要插入的值:");
	scanf("%d",&x);
	a->data=x;
	while(i<n)
	{
	  p=p->next;
	  i++;		
	}
	a->next=p->next;
	p->next=a;	
	printf("接下来干嘛?\n");
}
void st(struct Node *head)
{
	struct Node *p;
	p=head;
	int a[10000]={0},i=0,j; 
	if(head->next == NULL) 
   {
      printf("只有一个结点，无需排序\n");
      return ;
   }
	while(p!=NULL)
	{	
		a[i]=p->data;
		i++;
		p=p->next;		
	}
	p=head;
	sort(a,a+i);
	i=0;
	while(p!=NULL)
	{
		p->data=a[i];
		i++;
		p=p->next;
	
	}
printf("排序成功!\n");
}
