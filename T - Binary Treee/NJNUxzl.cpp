#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;	
}Node; 
Node *CreateBiTree()
{	
    Node *p;
	int a;
	scanf("%d",&a);
	if(a==0)
	{
		p=NULL;	
	} 
	else
	{
		p=(BiTNode *)malloc(sizeof(BiTNode));
		p->data=a;
		p->lchild=CreateBiTree();
		p->rchild=CreateBiTree();	
	}
	return p;	
}

void Preorder(Node *p)
{ 
	if(p)
	{
		printf("%d ",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
		
	}
}
int chf(int n)
{
	int i,m=1;
	if(n==0)
	return 1;
	else
	for(i=1;i<=n;i++)	
	m*=2;
	return m;
}
void CreateBiTree2(int q[])
{	
	char c;
	int i = 0;
	int n = 0;
	printf("请输入:"); 
	while ((c = getchar()) != '\n')
	{
		if (isdigit(c))
		{
			ungetc(c, stdin);
			scanf("%d", &q[n++]);
		}	
		
	}

}
void Adjust(int q[])
{
	int i=0,t;
	for(i=2;q[i]!=0;i=i+2)
	{
		t=q[i];
		q[i]=q[i-1];
		q[i-1]=t;		
	}
}
void Forder(int q[])
{  	 int i,j,n=0; 
	for(i=0;i<100;i++)
	{
		for(j=0;j<chf(i);j++)
		{
			if(q[n]==0)
			break;
			printf("%d ",q[n]);
		 	n++;
		}
			printf("\n"); 
	 		if(q[n]==0)
	 		break;
			 	
	 	
	 }
	
	
}


int main()
{	
	int a[100]={0};
	Node *p;
	printf("层序遍历:\n");
	CreateBiTree2(a);
 	Adjust(a);
 	Forder(a);
 	printf("前序遍历:");
 	printf("请输入(输入时请用0将二叉树补成满二叉树):");
 	p=CreateBiTree();
	Preorder(p);
		 
		  
	 
	
	
	
	
	
	
	 


	
return 0;	
 } 
