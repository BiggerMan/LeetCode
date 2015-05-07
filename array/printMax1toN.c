#include <stdio.h>
#include <stdlib.h>
#include <string.h>

printNumber(char *number)
{
	printf("%s\n",number);
}

incNumber(char *number)
{
	int len=strlen(number);
	int isOverFlow=0;
	int takeOver=0;//jinwei
	int i;
	for(i=len-1;i>=0;i--)
	{
		int sum = number[i]-'0' + takeOver;
		if(i == len-1)
			sum++;
		number[i] = '0' + sum%10;
		takeOver = sum/10;
		if(takeOver&&i==0)
			isOverFlow=1;
		if(takeOver==0)
			break;
	}
	return isOverFlow;
}

int printMax1toN(int n)
{
	char *number = (char*)malloc(sizeof(char)*n);
	int i;
	for(i=0;i<n;i++)
		number[i]='0';
	number[n]='\0';
	while(!incNumber(number))
	{
		printNumber(number);
	}
}

int main()
{
	printMax1toN(5);

	return 0;
}
