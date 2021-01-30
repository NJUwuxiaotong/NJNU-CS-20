//双向链表的正向遍历 
void double_list_for_each(DL *header)
{
	DL *p = header ;
	while(p->next != NULL)
	{
		p = p->next ;
		printf("%d ",p->data);
	}
}
 
 
//双向链表的反向遍历 
void double_list_for_each_nx(DL *header)
{
	DL *p = header ;
	while( p->next!= NULL)//先正向遍历 
	{
		p = p->next ;	
	}// 此时p所指为尾节点 
	while(p->prev != NULL)//通过反向的连接指针域，反向遍历 
	{
		printf("%d ",p->data);
		p = p->prev ;
	}
}

