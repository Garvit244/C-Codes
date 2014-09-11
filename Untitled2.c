#include<stdio.h>
#include<string.h>
#define max 10
char array[max][max];
main()
{
	int i,j;
		for(i=0;i<max;i++)
	 	{
		 	printf("Enter the element %d:",i+1);
			scanf("%s",array[i]);
		}
		printf("%s",array[0]);
}
