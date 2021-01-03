struct student *create(struct student *head,int n)
{
	int i;
	for(i=0;i<n;i++)//头插法的遍历即为逆序 
	{
		head=insert(head);
	}
	return head;
}
struct student *insert(struct student *head)
{
	struct student *newp=(struct student *)malloc(sizeof(struct student));
	scanf("%d",&(newp->data));
	printf("%d",newp->data);//这是正序 
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
