//删除

/*单向链表的删除要考虑两种情况，一种的普通节点的删除(当然，头节点不能算)
还有一种是尾节点的前一个节点的删除情况，注意，删除完节点还需要释放对应节点的内存空间。
*/
struct list *p = header ;  //当前节点
struct list *prev = NULL ; //当前节点的上一个节点
while(NULL != p->next)
{ 
	prev = p ;  
    p = p->next ; 
    return 0 ;
}
while(NULL != p->next)
{ 
    prev = p ;  
    p = p->next ; //同时运作两个指针，以便最后得到要找节点的前一个节点 
    if(p->id == data)
    {   
    }
	return 0 ;
}
//两种情况： 
//1.普通节点 
if(p->id == data)
{
    prev->next = p->next ;//上一个节点的指针域指向下一个节点（即将该节点的指针域赋值给上一个节点的指针域） 
    free(p);//此时p指针所指已经被删掉，（而在单链表里，下一节点也无法找到该节点）故释放掉无用的p节点 
}
//2.下一节点为NULL的节点  （即删除的是尾节点 ） 
if(p->id == data)
{
    if(p->next == NULL)
    {
	    prev->next = NULL ;//直接令该节点的上一个节点的指针域为NULL 
        free(p);
    }
}




p=head;
prev=NULL;
while(p->next!=NULL)
{
	prev=p;
	p=p->next;
	if(p->data==data)
	{
		prev->next=p->next;	
		free(p);
	}	
}
//此时已经可以确定该p为尾节点（因为已经遍历到这里了） 
if(p->data==data)
{
	prev->next=NULL;
	free(p);
} 





















