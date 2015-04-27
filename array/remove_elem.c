#include <stdio.h>

int removeElement(int A[],int n,int elem)
{
	int i=0;
	int j=0;
	for(i=0;i<n;i++)
	{
		if(A[i] == elem)
			continue;
		A[j++] = A[i];
	}
	return j;
}

int main()
{
	int a[]={1,1,1,1,1};	
	printf("result len:%d\n",removeElement(a,5,1));
	return 0;
}
