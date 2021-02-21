typedef struct Tnode* position;
typedef position Bintree;
struct Tnode
{
	int data;
	Bintree left;
	Bintree right;
};

struct Qnode
{
	int *data;
	position front,rear;
	int maxsize;
};
typedef Qnode Queue;

position depthfind(Bintree BST,int x)
{
	if(!BST)return NULL;
	if(x>BST->data)
	{
		BST=BST->right;	
	}	
	else if(x<BST->data)
	{
		BST=BST->left;
	}
	else return BST;
} 
 
 
position widthfind(Bintree BST,int x)
{
	Queue Q;
	Bintree T;
	if(!BT)return ;
	Q=createqueue();
	AddQ(Q,BT);
	while(!Isempty(Q))
	{
		T=delete(Q);//抛出队列最前面的元素，再把左右子节点加入队列，先加入的，先出来，从而达到层序 
		if(x==T->data)
			return T;
		if(T->left) AddQ(Q,T->left);
		if(T->right) AddQ(Q,T->right);
	}		
}



