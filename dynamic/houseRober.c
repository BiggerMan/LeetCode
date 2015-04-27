#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *dp[n] = max(dp[n-1],dp[n-2]+num[n-1]) n-1:because c is begin from 0,so num[n-1] is the nth number
 */
int rob(int num[], int n)
{
	if(n==1)//n==1 is special
		return num[0];
	int i,j;
	int maxi=0,maxj=0;
	int *dp = (int*)malloc((n+1)*sizeof(int));
	memset(dp,0,sizeof(int)*(1+n));

	dp[1]=num[0];
	for(i=2;i<=n;i++)
	{
		dp[i] = dp[i-1] > (dp[i-2]+num[i-1]) ? dp[i-1]:dp[i-2]+num[i-1];
	}

	return dp[n];
}

int main()
{
	int a[]={1,2,9,11,2};
	printf("max:%d\n",rob(a,5));
	int b[]={2,1,1,2};
	printf("max:%d\n",rob(b,4));
	int c[]={1};
	printf("max:%d\n",rob(c,1));

	return 0;
}
