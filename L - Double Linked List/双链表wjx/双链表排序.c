//Ë«Á´±íµÄÅÅÐò
struct doublelink
{
	int data;
	struct node*prev;
	struct node*next;	
}; 
void swap(struct node *head,int i1,int i2)
{
	struct node *a,*b,*pre;
	pre=searchnow(head,i1-1);
	a=pre->next;
	b=p->next;
	
	a->next=b->next;
	a->prev=b->next>prev;
	
	b->prev=pre;
	b->next=a; 
	
} 
void quene(struct node *head)
{
	int i,j,flag=0;
	struct node *p;
	if(p->next1==NULL)return ;
	for(i=0;i<length(head)-1;i++)
	{
		for(j=0;j<length(head)-1;j++)
		{
			if(p->data>p->next->data)
			{
				flag=1;
				swap(head,j+1,j+2);
			}
			if(flag==1)
			{
				flag=0;
			}
			else
			{
				p=p->next;
			}
		}
	}
}
int length(struct node *head)
{
	int i=0;
	struct node* p=head;
	while(p->next!=NULL)
	{
		i++;
	}
	return i;
}
struct node* searchnow(struct node*head,int x)
{
	int i=0;
	struct node*p=head;
	while(i!=x)
	{
		p=p->next;
	}
	return p;
}
