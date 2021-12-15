#include <stdio.h>
void quickSort(int arr[],int low,int high);
void printArray(int arr[],int n);

int main()
{
	int i,n,arr[20];
	printf("Enter no.of Elements Present in the array: ");
	scanf("%d",&n);
	int *ptr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	for(i=0;i<n;i++)
	{
		arr[i]=*(ptr+i);
	}
	quickSort(arr,0,n-1);
	printArray(arr,n);
}

void quickSort(int arr[],int low,int high)
{
	if(low>=high)
	{
		return;
	}
	int s=low;
	int e=high;
	int m=s+(e-s)/2;
	int p=arr[m];

	while(s<=e)
	{
		while(arr[s]<p)
		{
			s++;
		}
		while(arr[e]>p)
		{
			e--;
		}
		if(s<=e)
		{
			int temp=arr[s];
			arr[s]=arr[e];
			arr[e]=temp;
			s++;
			e--;
		}
		
		quickSort(arr,low,e);
	    quickSort(arr,s,high);
	
	}
}

void printArray(int arr[],int n)
{
	int  i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
