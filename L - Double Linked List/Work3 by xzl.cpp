#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct Node
{
	int data;
	struct Node *next;	
	struct Node *pre;
};
struct Node *Initial();
void output(struct Node *head);
void search(struct Node *head);
void add(struct Node *head);
void count(struct Node *head);
void delet(struct Node *head);
void insert(struct Node *head);
void st(struct Node *head);
void cde(struct Node *head);
void res(struct Node *head);
void reserach(struct Node *head);
void dde(struct Node *head);
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
			case 2:count(head);
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
			case 8:cde(head);
					break;
			case 9:res(head);
					break;
			case 10:reserach(head);
					break;
			case 11:dde(head);
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
    printf(">8.删除链表中指定数值\n");
    printf(">9.链表逆序\n");
    printf(">10.查找倒数第i个结点\n");
    printf(">11.删除链表中指定范围的数值\n");
    printf(">0.退出\n");
    printf("---------------------------------------\n");

}
struct Node *Initial()
{
	struct Node *head,*p,*s;
	int n,i;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->data=0;
	head->pre=NULL;
	head->next=NULL; 
	p=head;
	printf("---------------初始化-----------------\n"); 
    printf("请输入你要初始化的结点数:");
    scanf("%d",&n);
    head->data=n;
    for(i=1;i<=n;i++)
    {
    	s=(struct Node *)malloc(sizeof(struct Node));
		printf("请输入第%d个结点数值:",i);	
    	scanf("%d",&s->data);
    	p->next=s;
    	s->pre=p;
    	s->next=NULL;
    	p=s;
	}
	printf("初始化结束!\n");
	printf("--------------------------------------\n");
	return head;	
}
void output(struct Node *head)
{
	struct Node *p=head->next;
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
	struct Node *p=head->next;
	int i=1,n;
	printf("请输入你要查找的结点:");
	scanf("%d",&n);
	while(i<n)
	{
	  p=p->next;
	  i++; 		  		
	}
  printf("第%d个结点的数值为%d\n",n,p->data);
  printf("接下来干嘛?\n");	
  
}
void add(struct Node *head)
{
	struct Node *p=head;
	struct Node *a=NULL;
	a=(struct Node *)malloc(sizeof(struct Node));
	while(p->next!=NULL)
	{
	  p=p->next;		
	}
	p->next=a;
	printf("输入你要插入的数据:");	
	scanf("%d",&a->data);
	a->pre=p;
	a->next=NULL;
	printf("插入成功!\n");
	printf("接下来干嘛?\n");
	head->data++;	
}
void count(struct Node *head)
{	 
printf("一共有%d个结点\n",head->data);
printf("接下来干嘛?\n");	
}
void delet(struct Node *head)
{	struct Node *p=head->next;
	int n,i=1;
    printf("输入你要删除的结点:");
    scanf("%d",&n);
	if(n>head->data||n<=0)
	{
		printf("不存在该结点!\n");
		return ;
    }
    if(n==head->data)
    {
      while(p->next!=NULL)
	  {
	  	p=p->next;
	  }	
    p->pre->next=NULL;
	free(p);
	printf("接下来干嘛?\n");
    head->data--;
	return ;		  	
	}
	while(i<n)
	{ 
	  p=p->next;
	  i++;	
	}
	p->pre->next=p->next;
	p->next->pre=p->pre;
	free(p);
printf("接下来干嘛?\n");
head->data--;	
}
void insert(struct Node *head)
{
	struct Node *p=head->next,*a=NULL;
	int n,i=1,x;
	a=(struct Node *)malloc(sizeof(struct Node));
	printf("请输入你要插入的位置:");
	scanf("%d",&n);
	if(n>head->data||n<=0)
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
	a->pre=p;
	p->next=a;
	p->next->pre=a;	
	printf("接下来干嘛?\n");
}
void st(struct Node *head)
{
	struct Node *p=head->next;
	int a[10000]={0},i=0,j; 
	if(p->next == NULL) 
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
	p=head->next;
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
void cde(struct Node *head)
{
	struct Node *p=head->next;
	int d;
	printf("请输入你要删除的数值:");
	scanf("%d",&d);
	while(p!=NULL)
	{	
		if(p->data==d)
		{
			p->pre->next=p->next;
			p=p->next;
			head->data--;		
		}	
		else
		{
		p=p->next;
		}
	}
	printf("删除成功!\n");			
}
void res(struct Node *head)
{
	int a[100],i=0;
	struct Node *p=head->next;
	while(p!=NULL)
	{
		a[i]=p->data;	
		p=p->next;
		i++;
	}
	p=head->next;
	i--;	
	while(p!=NULL)
	{
		p->data=a[i];
		i--;	
		p=p->next;	
	}
 printf("逆序成功!\n");	
}
void reserach(struct Node *head)
{
	struct Node *p=head->next;
	int n,m,i=1;
	printf("请输入你要查找倒数第几个结点的值?");
	scanf("%d",&n);	
	m=head->data-n+1;
	while(i<m)
	{
	  p=p->next;
	  i++; 		  		
	}
  printf("倒数第%d个结点的数值为%d\n",n,p->data);
  printf("接下来干嘛?\n");	
}
void dde(struct Node *head)
{
   struct Node *p=head->next;
	int d;
	printf("你要删除小于多少的结点?");
	scanf("%d",&d);
	while(p!=NULL)
	{	
		if(p->data<d)
		{
			p->pre->next=p->next;
			p->next->pre=p->pre;
			p=p->next;
			head->data--;		
		}	
		else
		{
		p=p->next;
		}
	}
	printf("删除成功!\n");		
}
