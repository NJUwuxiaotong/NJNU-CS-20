#include<stdio.h>
void initialize(int a[]);
void add(int a[]);
void delet(int a[]);
void find(int a[]);
void print(int a[]);
void updown(int a[]);
int n,m=0;
int main()
{
int flag=1;	
int a[1000]={0};	
printf("请输入数组的大小:");	
scanf("%d",&n);
printf("Menu:\n");
printf("1:初始化数组\n2:添加数值\n3:删除数值\n4:查找数值\n5:颠倒数组\n6:显示当前数组\n");
printf("0:退出\n");
int choice;
while(1)
{
  if(flag==1)
  scanf("%d",&choice);
  else break;	
 switch(choice)
 {  
    case 0:flag=0;
       	   break;
 
	case 1:initialize(a);
	 	   break;	
			
    case 2:add(a);
           break;
	
	case 3:delet(a);
		   break;
	
	case 4:find(a);
	 	   break;
	
	case 5:updown(a);
	       break;
	
	case 6:print(a);
	       break;								
 }
}
return 0;		
}
void initialize(int a[])
{
 int i;
 for(i=0;i<n;i++)
 {
   a[i]=0;	
 }	
printf("初始化成功!\n");
print(a);	
}
void add(int a[])
{
 int x,y,i;	
 printf("请输入你要添加的位置:\n");
 scanf("%d",&x);
 printf("请输入你要添加的数值:\n");  	
 scanf("%d",&y);
 if(x>=0&&x<n&&y>0&&m<n)
 {
   if(x<m)
   {
	for(i=n-1;i>x;i--)
	{
	 a[i]=a[i-1];		
	}	
	a[x]=y;
	m++;
	printf("添加成功!\n");		
   }	 
  else
  {
    a[m]=y;
	m++;
	printf("添加成功!\n");		
  }	 
  	 
  	 
 }
 else
 	{
  	printf("添加失败!\n");		
 	}

}
void delet(int a[])
{
 int x,i;	
 printf("请输入你要删除的位置:\n");
 scanf("%d",&x);
 if(x>=0&&x<n)
 {
   for(i=x;i<n-1;i++)
   a[i]=a[i+1];	
   printf("删除成功!\n");
   m--;
   a[m]=0;
 }
 else
 {
  printf("删除失败!\n");		
 }	
 	
}
void find(int a[])
{
 int x;	
 printf("请输入你要查找数的位置:");
 scanf("%d",&x);
 if(x>=0&&x<n)
 printf("%d\n",a[x]);
 else
 printf("查找失败!\n");	
}
void print(int a[])
{
 int i;
 for(i=0;i<n;i++)
 {
 if(a[i]!=0)	
 printf("%d ",a[i]);
 }
 printf("\n");		
}
void updown(int a[])
{
 int i=0,j=m-1,t;
 while(i<j)
 {
  t=a[i];
  a[i]=a[j];
  a[j]=t;		
  i++;
  j--;	
 }
 printf("颠倒成功!\n");		
}
