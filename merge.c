/*merge sort
Name: Garvit bansal
Rollno:Y11UC092*/
#include<stdio.h>
#define max 10
int array[max];
main()
{
	int i;
	//printf("Enter the number of element in an array:");
	//scanf("%d",&n);
	for(i=0;i<max;i++)
	{
		printf("Enter the element %d:",i+1);
		scanf("%d",&array[i]);
	}	
	printf("Unsorted list is:\n");
	for(i=0;i<max;i++)
		printf("%d ",array[i]);
	merge_sort(0,max-1);
		printf("\nSorted list is :\n");
	for(i=0;i<max;i++)
		printf("%d  ",array[i]);
	printf("\n");
}
 merge(int low,int mid,int high)
{
	int temp[max];
	int i=low,j=mid+1,k=low;
	while((i<=mid)&&(j<=high))
	{
		if(array[i]<=array[j])
			temp[k++]=array[i++];
		else
			temp[k++]=array[j++];
	}
		while(i<=mid)
			temp[k++]=array[i++];
		while(j<=high)
			temp[k++]=array[j++];
		for(i=low; i<=high;i++)
        	array[i]=temp[i];
}

merge_sort(int low,int high)
{
		int mid;
		if(low==high)
			return;
        //if(low != high )
   		else
   	 	{
    	    mid=(low+high)/2;
        	merge_sort(low, mid);
        	merge_sort(mid+1,high);
  		    merge(low,mid,high);
 	}
}