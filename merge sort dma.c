#include <stdio.h>
#include <stdlib.h>
void mergeSort(int a[],int s,int e);
void mergeArray(int arr[],int s,int mid,int m, int e);
void printArray(int arr[],int n);

int main()
{
	int i,n,a[20];
	scanf("%d",&n);
	int *ptr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	for(i=0;i<n;i++)
	{
		a[i]=*(ptr+i);
	}
	mergeSort(a,0,n);
    printArray(a,n);
}

void mergeSort(int a[],int s,int e)
{
	if(s<e){
	int mid=(s+e)/2;
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	
	mergeArray(a,s,mid,mid+1,e);
    }
}

void mergeArray(int arr[],int s,int mid,int m, int e)
{
	int temp[50];
	int i,j,k;
	i=s;
	j=mid;
	k=0;
	
	while(i<mid && j<e)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<e)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	for(i=s,j=0;i<e;i++,j++)
	{
		arr[i]=temp[j];
	}
	
}

void printArray(int arr[],int n)
{
	int  i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
