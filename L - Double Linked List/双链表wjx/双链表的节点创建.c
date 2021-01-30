//双链表
/*单链表的查找和删除比较麻烦，为了弥补不足，引入双链表*/ 


//双链表的创建  ： 步骤(与单链表类似，就是多了一个指针):

struct double_list
{                                                          
    int data ;
    struct double_list *prev ;
    struct double_list *next ;
};       
                                                     
struct list *create_node(int data) 
{
	struct double_list *p =(struct double_list *)malloc(sizeof(struct double_list));
	p->data = data ;
	p->prev = NULL ; 
	p->next = NULL ;
} 
