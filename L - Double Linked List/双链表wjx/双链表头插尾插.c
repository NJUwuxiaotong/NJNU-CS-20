//尾插 

void double_list_tail_insert(DL *header , DL *new)
{
	DL *p = header ;
	while(NULL != p->next)
	{
		p = p->next ;
	}
	//和新节点建立双向连接
	p->next = new ;//尾->new 
	new->prev = p;//new->尾 
}


//头插


void double_list_top_insert(DL *header , DL *new)
{
	new->next = header->next ; 
	if(header->next!=NULL  ) 
		header->next->prev = new ;//新节点和第一个节点反向连接 
	header->next = new ;//新节点和头结点相互连接 
	new->prev = header ;
	
}
 
