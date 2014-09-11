#include<stdio.h>
#define max 20
int usl[max];
main()
{
	int lo=0,hi,len,i;
	printf("Enter the number of elements in the array:");
	scanf("%d",&len);
	printf("\nEnter the elements in the array:\n");
	for(lo=0;lo<len;lo++)
		scanf("%d",&usl[lo]);
	printf("\nThe unsorted list is:");
	for(lo=0;lo<len;lo++)
		printf("%d  ",usl[lo]);
	printf("\n");
	hi=len-1;
	lo=0;
	quicksort(usl,lo,hi);		
	printf("\n **** Sorted Array **** \n");
	for(i=0;i<len;i++)
		printf("%d\t",usl[i]);
}
quicksort(int usl[],int lo,int hi)
{
	int n=hi-lo+1;
	int l=lo,r=hi-1;
	int temp;
	if(n == 1)
		return;
	int pivot=usl[hi];
	while(l<=r)	
	{
		while(usl[l]<pivot)
			l++;
		while((usl[r]>pivot) && (r>=l))
			r--;
		if(l<r)
		{
			temp=usl[l];
			usl[l]=usl[r];
			usl[r]=temp;	
			l++;
			r--;
		}
	}
	if(l!=hi)
	{
	    	temp=usl[l];
			usl[l]=usl[hi];
			usl[hi]=temp;
	}
	if(l>(lo+1))
		quicksort(usl,lo ,l-1);
	if(l+1<hi)
		quicksort(usl,l+1,hi);

}