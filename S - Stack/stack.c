#include<stdio.h>
typedef struct node* ptrtonode;
typedef ptrtonode List;
typedef int Elementtype;
List insert(List l,Elementtype x);
struct node
{
	Elementtype data;
	ptrtonode next;
};
List insert(List L,Elementtype x)
{
	List pre,tmp;
	pre=L;
	while(pre->next)
	{
		if(pre->next->data>x)
		{
			break;
		}
		else pre=pre->next;
	}
	List p=(ptrtonode)malloc(sizeof(struct node));
	p->data=x;
	p->next=pre->next;
	pre->next=p;
}
