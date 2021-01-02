#include<stdio.h>//nitialize(n) → 初始化一个数组，该数组大小为 n，元素初始化为 0，函数返回该数组 
int*initialize(int a[])
{
	int i,n;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		a[i]=0;
	}
	return a;
}
//add(array, index, value) → 往数组 array 中位置为 index 添加大于 0 的数值value。
//如果指定位置 index 大于数组中现有的数值个数，报错；否则，正常添加。返回值
//显示添加成功与否。
int add(int array[],int index,int value)
{
	int i,n;
	n=sizeof(a)/sizeof(a[0]);
	if(index<=n)
	{
		for(i=n-1;i>=index-1;i--)
		{
			a[i+1]=a[i];	
		} 
		a[index-1]=value;
		return 1;
	}
	else 
	{
		printf("fault");
		return 0;
	}	
}
//delete(array, index) → 删除数组 array 指定位置index 的数值，返回该数值。如果
//index 超过了 array 现有数值的个数，则返回-1.
int delete(int array[],int index)
{
	int i,n;
	n=sizeof(a)/sizeof(a[0]);
	if(index<=n)
	{
		for(i=index;i<n;i++)
		{
			a[i]=a[i+1];
		}
		a[n-1]=0;
		return index;
	}
	else return -1;
}
//find(array, index) → 查询 array 中指定位置 index 的数值，返回该数值。如果index
//超过数组中已有数值个数，则返回-1.
int find(int array[],int index)
{
	int i,n;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		if(a[i]==index)return i;
	}
	return -1;
}
//…… (也可以实现其他的类似函数，比如查找某个数值、按照指定数值删除等)





