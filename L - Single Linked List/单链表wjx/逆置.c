//逆序



//遍历+收尾互换指针域（和头插不同） 
struct list *p=ph->next;
sturct list *pback;
if(p==NULL||p->next==NULL)
	return ;
pback=p->next;
if(p==ph->next)p->next=NULL;
p->next=ph->next;
ph->next=p;
p=pback;
top_insert(ph,p);

6、单链表的逆序
逆序步骤：
单链表的基本操作流程咱们基本搞懂了，下面写一个程序，这将会变得非常非常的简单。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slist
{
	int id ;
	struct slist *next ;			
}L;
//创建一个节点 
L *create_node(int data)
{
	//给每个节点分配结构体一样的空间大小 
	L *p = malloc(sizeof(L));
	if(NULL == p)
	{
		printf("malloc error!\n");
		return NULL ;
	}
	//由于结构体在未初始化的时候一样是脏数据，所以要清 
	memset(p,0,sizeof(L));
	//初始化第一个节点 
	p->id = data ; 
	//将节点的后继指针设置为NULL 
	p->next = NULL ;
}
void trave_list(L * pH)
{
	//保存第一个节点的位置 
	L *p = pH->next;//ph为链表的首地址，p指向第一个节点 
	L *pBack;
	int i = 0 ;//检验链表是不是只有一个节点或者没有节点（head不算）****只有一个节点不用逆置，没有节点直接退出 
	if(p->next == NULL || p == NULL)
		return ;		
	while( p->next!=NULL ) //遍历链表 
	{
		//保存p指向的节点的下一个节点 
		pBack = p->next ; 
		//找到第一个有效节点,其实就是头指针的下一个节点 
		if(p == pH->next) 
		{
		//在逆置中第一个有效节点逆置后就是最后一个节点，
		//所以第一个节点的指针域为NULL  
			p->next = NULL ; 
		} 
		else
		{
			new->next = p->next ;
			p->next = new ;
			p->next = pH->next ; //尾部连接 
		}
		pH->next = p ; //头部连接 
		p = pBack ; //走下一个节点 
	}
	top_insert(pH,p); //插入最后一个节点 
}



//将节点依次移到前面 
LinkList Reverse(LinkList L)
{
	LNode *p,*r;//p为该处的指针，r为下一个节点的指针，L为首指针 
	p=L->next;//先让p指向第一个节点 
	L->next=NULL;//将L与之后的断开连接 
	while(p!=NULL)
	{
		r=p->next;//r指向p的下一个节点 
		p->next=L->next;//p的指向的节点的指针域：第一次循环时为NULL，其余为当前情况下第一个节点的地址 
		L->next=p;//第一个节点变成p所指的节点 
		p=r;//p的指向变为之前存的下一个节点 
	}
	return L;	
} 






