struct node *insert(struct node *head,struct node *newp)
{
	struct node *prew,*p;
	prev=NULL;p=head;
	while(p!=NULL)
	{
		if(p->data>newp->data)break;
		prev=p;
		p=p->next;
	}
	newp->next=p;
	if(p==head)head=newp;
	else prev->next=newp;
	return head;
 } 
