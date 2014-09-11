#include<stdio.h>
#include<string.h>
#define max 5
char arr[max][max];
char arr_ug[max][max];
char arr_pg[max][max];
main()
{
	int i,j,ug=0,pg=0;
	for(i=0;i<max;i++)
	{
		printf("Enter the elements in the array %d",i+1);
		scanf("%s",&arr[i]);
	}
	for(i=0;i<max;i++)
	{
		if((arr[i][3]=='u') || (arr[i][3]=='U'))
			strcpy(arr_ug[ug++],arr[i]);
		else	
			strcpy(arr_pg[pg++],arr[i]);
	}
	for(i=0;i<pg;i++)
			strcpy(arr[i],arr_pg[i]);
			ug=0;
	for(i=pg;i<max;i++)
			strcpy(arr[i],arr_ug[ug++]);
	int lo=0;
	int hi=max-1;
	quicksort(arr,lo,hi);
	for(i=0;i<max;i++)
		printf("%s ",arr[i]);
}
quicksort(char arr[],int lo,int hi)
{
	int n=hi-lo+1;
	int l=lo, r=hi-1;
	char temp[max];
	char pivot[max];
	strcpy(pivot,arr[hi]);
	if(n == 0)
		return;
	while(l<=r)
	{
		while(strcmpi(arr[l],pivot)>0)
			l++;
		while((strcmpi(arr[r],pivot)<0) && (r>=l))
			r--;
		if(l<r)
		{
			strcpy(temp,arr[l]);
			strcpy(arr[l],arr[r]);
			strcpy(arr[r],temp);
			l++;
			r--;
		}
	}
	if(l!=hi)
	{
			strcpy(temp,arr[l]);
			strcpy(arr[l],arr[hi]);
			strcpy(arr[hi],temp);
	}
	if(l>(lo+1))
		quicksort(arr,lo ,l-1);
	if(l+1<hi)
		quicksort(arr,l+1,hi);
	
}