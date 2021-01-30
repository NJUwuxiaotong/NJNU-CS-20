
#include <stdio.h>
#include <stdlib.h>                                //->指针指向节点的结构体成员 *****
#include <string.h>
struct  list_node//结构体的内容 
{
	int data ; 
	struct list_node *next ;
};
 
typedef struct list_node list_single ; 	
 
int main(void)
{
	list_single *node = NULL ;          //1、首先，当然是定义一个头指针
	node = (list_single *)malloc(sizeof(list_single/*申请结构体大小的内存的地址赋值给指针*/)); //2、然后分配内存空间 
	if(node == NULL){
		printf("malloc fair!\n");
	}
	memset(node,0,sizeof(list_single)); //3、清一下    /*memset函数用于（对较大结构体或数组）初始化赋值；三个参数为：1.指针或数组 2.要赋的值 3.内存块的长度*/ 
													   /*memset在string.h库里*/
													   /*	对于字符指针类型的，剩余的部分通常是不会为0的*/
	node->data = 100;					//4、给链表节点的数据赋值
	/*结构体指针类型可以使它找到结构体单元*/									
	node->next = NULL ;                 //5、将链表的指针域指向空
	printf("%d\n",node->data);
	free(node);
	return 0 ;
}
//创造节点的函数
list_single *create_list_node(int data)//1.定义一个结构体类型指针开始指向为空（头指针），2.申请地址（结构体大小的结构体指针地址），
									   //2.清节点数据（用memset函数进行赋值）【注意：没有初始化的时候数据是脏的】 
									   // 3.将其结构体内部赋值，内部指针赋值为空，     创建完成 
									   // 4.返回指向该节点的指针（头指针）          
{
	list_single *node = NULL ;
	node = (list_single *)malloc(sizeof(list_single));
	if(node == NULL){
		printf("malloc fair!\n");
	}
	memset(node,0,sizeof(list_single));
	node->data = 100 ;
	node->next = NULL ;
	return node ;
}
 

