#include <stdio.h>
#include <stdint.h>//for uint32_t

int hammingWeight(uint32_t n)
{
	int count=0;
	//o(lgn)
	/*
	while( n!=0 )
	{
		if(n&1)
			count++;
		n >>= 1;
	}
	*/
	//better one o(n):n == counts of 1
	while( n!=0 )
	{
		n &= n-1;
		count++;
	}

	return count;
}



int main(int argc,char *argv[])
{
	if(argc<=1)
	{
		printf("need a number..\n");
		return 0;
	}
	uint32_t n = atoi(argv[1]);	
	printf("hammingWeight of %d is:%d\n",n,hammingWeight(n));

	return 0;
}
