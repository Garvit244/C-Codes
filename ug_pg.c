#include<stdio.h>
#include<string.h>
#define max 10
char array[max][max];
char array_ug[max][max];
char array_pg[max][max];
main()
{
	int i,j,ug=0,pg=0;
	for(i=0;i<max;i++)
	{
		printf("Enter the element %d:",i+1);
		scanf("%s",array[i]);
	}
	for(i=0;i<max;i++)
		{
			if((array[i][3]=='u')||(array[i][3]=='U'))
			{
			strcpy(array_ug[ug],array[i]);
			ug++;
			}
			else
			{
			strcpy(array_pg[pg],array[i]);
			pg++;
			}
		}
	//for(i=0;i<pg;i++)
	//printf("%s ",array_pg[i]);
	//printf("\n");
	//for(i=0;i<ug;i++)
	//printf("%s ",array_ug[i]);
	//printf("\n");
	for(i=0;i<pg;i++)
	strcpy(array[i],array_pg[i]);
	for(j=0;j<ug;j++,i++)
	strcpy(array[i],array_ug[j]);
	merge_sort(0,pg-1);
	merge_sort(pg,max-1);
	printf("\nSorted list is :\n");
	for(i=0;i<max;i++)
	printf("%s\n",array[i]);		
}
merge_sort(int low,int high)
{
	int mid;
        if(low != high )
    	{
    		mid=(low+high)/2;
        	merge_sort(low, mid);
        	merge_sort(mid+1,high);
  		merge(low,mid,high);
    	}
}
merge(int low,int mid,int high)
{
	int temp[max][max];
	int i=low,j=mid+1,k=low;
	while((i<=mid)&&(j<=high))
	{
		if(strcmp(array[i],array[j])<0)
		strcpy(temp[k++],array[i++]);		
		else
		strcpy(temp[k++],array[j++]);
	}
		while(i<=mid)
			strcpy(temp[k++],array[i++]);
		while(j<=high)
			strcpy(temp[k++],array[j++]);
		for(i=low; i<=high;i++)
        	strcpy(array[i],temp[i]);
}
