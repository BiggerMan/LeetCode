#include <stdio.h>
#include <stdlib.h>

#define MAXLEN (1024)

int set[MAXLEN];
int initSet()
{
	int i=0;
	for(i=0;i<MAXLEN;i++)
		set[i]=i;
}
int find(int x)
{
	while(x != set[x])
	{
		x = set[x];
	}
	return set[x];
}
int unionSet(int to, int from)
{
	int toRoot = find(to);
	int fromRoot = find(from);
	if(toRoot == fromRoot)
		return;
	set[fromRoot] = toRoot;

	return 0;
}

int main()
{
	initSet();
	set[5]=2;
	set[2]=2;
	set[4]=3;
	set[3]=1;
	printf("find(5):%d\n",find(5));
	printf("find(4):%d\n",find(4));
	printf("afterUnion:\n");
	unionSet(4,5);
	printf("find(5):%d\n",find(5));
	printf("find(4):%d\n",find(4));

	return 0;
}
