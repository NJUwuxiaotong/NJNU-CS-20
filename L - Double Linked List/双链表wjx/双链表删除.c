int double_list_delete_node(DL *header , int data)
{
	DL *p = header;
	while(NULL != p->next)
	{
		p = p->next ;
		if(p->data == data)
		{
			if(p->next != NULL)
			{
				p->next->prev = p->prev ;//两个连接都换掉 
				p->prev->next = p->next ;
				free(p);
			} 
			else//p所指为尾节点 
			{ 
				p->prev->next = NULL ;//直接删除尾节点，（因为只要找不到最后一个即可，无需再断其他连接） 
				free(p); 
			}
			return 0 ;
		}
	}
	printf("\n没有找到对应要删除的节点，或者节点已经被删除！\n");
	return -1 ;	
} 

