#include <stdio.h>
void quickSort(int arr[],int low,int high);

int main()
{
	int arr[]={5,3,1,4,2};
	int i;
	int n=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
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
