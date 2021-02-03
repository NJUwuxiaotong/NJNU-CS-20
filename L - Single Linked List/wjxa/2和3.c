struct node *delete(struct node*head,int data)
{
	struct node *prev,*p;
	prev=NULL;p=head;
	while(p!=0)
	{
		if(p->data==data)break;
		prev=p;
		p=p->next;
	}
	if(p==NULL)return head;
	if(p==head)head=head->next;
	else prev->next=p->next;
	free(p);
	return head;
}
struct node *delete(struct node*head,int data)
{
	struct node *prev,*p;
	prev=NULL;p=head;
	while(p!=0)
	{
		if(p->data<data)delete(head,p->data);
		prev=p;
		p=p->next;
	}
	if(p==NULL)return head;
	if(p==head)head=head->next;
	else prev->next=p->next;
	free(p);
	return head;
}
