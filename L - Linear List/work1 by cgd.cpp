#include<stdio.h>
int *initialize(int n);
int del(int array[],int index,int m);
int add(int array[],int index,int value,int m);
int find(int array[],int index,int m);
int search(int array[],int value,int m);
int main(){
	int *p;
	int i;
	int n,x,index,value;
	int k=0;
	printf("请输入初始化数组个数：");
	scanf("%d",&n); 
	p=initialize(n);
	for(i=0;i<n;i++) printf("%d ",*(p+i));
	printf("\n"); 
	printf("1.添加元素.add\n");
	printf("2.删除元素.delete\n");
	printf("3.查找元素.find\n");
	printf("4.查找数值的下标.else\n");
	printf("5.退出.exit\n");
	while(1){
	printf("请选择你要进行的操作：");
	scanf("%d",&x);
	if(x==1){
		printf("输入添加的位置和值"); 
		scanf("%d %d",&index,&value);
		if(add(p,index,value,k)==1){
			k++;
		for(i=0;i<k;i++) printf("%d ",*(p+i));
		printf("\n");
		}
		else printf("error\n");
 	}
 	if(x==2){
		printf("输入删除的位置"); 
		scanf("%d",&index);
		if(del(p,index,k)==1){
			k--;
		for(i=0;i<k;i++) printf("%d ",*(p+i));
		printf("\n");
		}
		else printf("error\n");
 	}
 	if(x==3){
 		printf("输入查找的位置");
 		scanf("%d",&index);
 		printf("%d\n",find(p,index,k));
 	}
 	if(x==4){
 		printf("输入要查找的数值");
		scanf("%d",&value);
		if(search(p,value,k)==-1) printf("找不到啊\n");
		else printf("%d\n",search(p,value,k)); 
 	}
 	if(x==5) break; 
 }
	return 0;
} 
int *initialize(int x){
	static int a[100];
	int i;
	for(i=0;i<x;i++) a[i]=0;
	return a;
}
int add(int array[],int index,int value,int m){
	int i;
	if(index>m) return 0;
	else{
		for(i=m+1;i>index;i--){
			array[i]=array[i-1];
		}
		array[index]=value;
		return 1;
	}	
}
int del(int array[],int index,int m){
	int i;
	if(index>m) return 0;
	else{
		for(i=index;i<m-1;i++){
			array[i]=array[i+1];
		}
		return 1;
	}
}
int find(int array[],int index,int m){
	int i;
	if(index>m) return -1;
	else{
		return array[index]; 
	}
}
int search(int array[],int value,int m){
	int i;
	int flag=0;
	for(i=0;i<m;i++){
		if(array[i]==value){
			flag=1;return i;
		}
	}
	if(flag==0) return -1;
} 
